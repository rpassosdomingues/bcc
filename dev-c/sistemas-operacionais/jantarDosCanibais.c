#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5  
// Número máximo de porções no caldeirão
#define NUM_CANIBAIS 6
// Número de canibais

int caldeirao = 0;  // Variável compartilhada para representar o estado do caldeirão

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // Mutex para garantir exclusão mútua
sem_t encher_caldeirao_sem;  // Semáforo para controlar o enchimento do caldeirão
sem_t servir_sem;  // Semáforo para controlar o ato de se servir do caldeirão

void* canibal(void* arg) {
    while (1) {
        // Tentar se servir do caldeirão
        sem_wait(&servir_sem);

        pthread_mutex_lock(&mutex);
        if (caldeirao > 0) {
            caldeirao--;
            printf("Canibal %ld se serviu do caldeirão. Restam %d porção(es).\n", (long)arg, caldeirao);
        }
        pthread_mutex_unlock(&mutex);

        // Se o caldeirão está vazio, avisar o cozinheiro
        if (caldeirao == 0) {
            sem_post(&encher_caldeirao_sem);
        }

        // Comer
        printf("Canibal %ld está comendo.\n", (long)arg);
        sleep(1);  // Simula o tempo de comer

        // Liberar o acesso ao caldeirão para outros canibais
        sem_post(&servir_sem);

        // Fazer outras atividades qualquer
        // ...
    }
}

void* cozinheiro(void* arg) {
    while (1) {
        // Esperar o caldeirão estar vazio
        sem_wait(&encher_caldeirao_sem);

        // Encher o caldeirão
        pthread_mutex_lock(&mutex);
        caldeirao = N;
        printf("Cozinheiro encheu o caldeirão com %d porção(es).\n", caldeirao);
        pthread_mutex_unlock(&mutex);

        // Fazer outras atividades qualquer
        // ...
    }
}

int main() {
    pthread_t canibais[NUM_CANIBAIS];
    pthread_t cozinheiro_thread;

    // Inicializar os semáforos
    sem_init(&encher_caldeirao_sem, 0, 0);
    sem_init(&servir_sem, 0, 1);

    // Criar threads dos canibais
    for (long i = 0; i < NUM_CANIBAIS; i++) {
        pthread_create(&canibais[i], NULL, canibal, (void*)i);
    }

    // Criar thread do cozinheiro
    pthread_create(&cozinheiro_thread, NULL, cozinheiro, NULL);

    // Aguardar as threads terminarem
    for (int i = 0; i < NUM_CANIBAIS; i++) {
        pthread_join(canibais[i], NULL);
    }
    pthread_join(cozinheiro_thread, NULL);

    // Destruir os semáforos
    sem_destroy(&encher_caldeirao_sem);
    sem_destroy(&servir_sem);

    // Liberar o mutex
    pthread_mutex_destroy(&mutex);
  
    return 0;
}