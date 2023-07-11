#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define N 10
#define MAX_CANIBALS 10

typedef struct {
    int num_canibals;
    int count_mutex;
    int count_semaphore;
    double wait_time;
} ExperimentResult;

int caldeirao = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t encher_caldeirao_sem;
sem_t servir_sem;

void* canibal(void* arg) {
    long id = (long)arg;
    double wait_time = 0.0;
    int count_mutex = 0;
    int count_semaphore = 0;

    int num_cycles = *((int*)arg);
    for (int cycle = 0; cycle < num_cycles; cycle++) {
        sem_wait(&servir_sem);

        pthread_mutex_lock(&mutex);
        if (caldeirao > 0) {
            caldeirao--;
            printf("Canibal %ld took a portion. Remaining portions: %d.\n", id, caldeirao);
        }
        pthread_mutex_unlock(&mutex);

        if (caldeirao == 0) {
            sem_post(&encher_caldeirao_sem);
        }

        printf("Canibal %ld is eating.\n", id);
        sleep(1);

        sem_post(&servir_sem);

        double start_time = (double)clock() / CLOCKS_PER_SEC;
        for (int i = 0; i < MAX_CANIBALS; i++) {
            if (i != id) {
                sem_wait(&servir_sem);
                double end_time = (double)clock() / CLOCKS_PER_SEC;
                wait_time += end_time - start_time;
                sem_post(&servir_sem);
            }
        }

        pthread_mutex_lock(&mutex);
        count_mutex++;
        count_semaphore = id - 1;
        pthread_mutex_unlock(&mutex);
    }

    ExperimentResult* result = malloc(sizeof(ExperimentResult));
    result->num_canibals = id;
    result->count_mutex = count_mutex;
    result->count_semaphore = count_semaphore;
    result->wait_time = wait_time;

    pthread_exit(result);
}

void* cozinheiro(void* arg) {
    while (1) {
        sem_wait(&encher_caldeirao_sem);

        pthread_mutex_lock(&mutex);
        caldeirao = N;
        printf("The cook filled the caldeirao with %d portions.\n", caldeirao);
        pthread_mutex_unlock(&mutex);
    }
}

void write_data(const char* filename, ExperimentResult** results, int num_results) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < num_results; i++) {
        fprintf(file, "%d, %d, %d, %.3f\n", results[i]->num_canibals, results[i]->count_mutex, results[i]->count_semaphore, results[i]->wait_time);
    }

    fclose(file);
}

int main() {
    int start_canibals = 1;
    int end_canibals = 10;
    int increment = 1;
    int num_cycles = 3; // Define o número de ciclos

    pthread_t canibals[MAX_CANIBALS];
    pthread_t cozinheiro_thread;
    ExperimentResult* results[MAX_CANIBALS];
    int num_results = 0;

    sem_init(&encher_caldeirao_sem, 0, 0);
    sem_init(&servir_sem, 0, 1);

    for (int num_cannibals = start_canibals; num_cannibals <= end_canibals; num_cannibals += increment) {
        for (long i = 0; i < num_cannibals; i++) {
            int* cycles = malloc(sizeof(int));
            *cycles = num_cycles;
            pthread_create(&canibals[i], NULL, canibal, cycles);
        }

        pthread_create(&cozinheiro_thread, NULL, cozinheiro, NULL);

        for (int i = 0; i < num_cannibals; i++) {
            ExperimentResult* result;
            pthread_join(canibals[i], (void**)&result);
            results[num_results++] = result;
        }

        pthread_cancel(cozinheiro_thread);
        if (num_cannibals >= 10) {
            break;
        }
    }

    sem_destroy(&encher_caldeirao_sem);
    sem_destroy(&servir_sem);
    pthread_mutex_destroy(&mutex);

    write_data("output.txt", results, num_results);

    for (int i = 0; i < num_results; i++) {
        free(results[i]);
    }

    return 0;
}
