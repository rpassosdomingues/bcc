#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // Para a função usleep

#define N 5
// Número máximo de porções no caldeirão
#define NUM_CANIBAIS 6

int caldeirao = 0; // Variável compartilhada para representar o estado do caldeirão

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex para garantir exclusão mútua
sem_t encher_caldeirao_sem;                        // Semáforo para controlar o enchimento do caldeirão
sem_t servir_sem;                                  // Semáforo para controlar o ato de se servir do caldeirão

void servir(long int canibal)
{

  sem_wait(&servir_sem);

  pthread_mutex_lock(&mutex);
  if (caldeirao > 0)
  {
    caldeirao--;
    sleep(1);
    printf("Canibal %ld se serviu do caldeirão. Restam %d porção(es).\n", canibal, caldeirao);
  }
  if (caldeirao == 0)
  {
    sem_post(&encher_caldeirao_sem);
  }
  pthread_mutex_unlock(&mutex);
}

void comer(long int canibal)
{
  printf("Canibal %ld está comendo.\n", canibal);
  pthread_mutex_lock(&mutex);
  if (caldeirao > 0)
    sem_post(&servir_sem);
  pthread_mutex_unlock(&mutex);
  sleep(1);
  // Espera 1 segundo antes da próxima ação
}

void *canibal(void *arg)
{
  while (1)
  {
    servir((long)arg);
    comer((long)arg);
  }
}

void encher()
{
  sem_wait(&encher_caldeirao_sem);
  pthread_mutex_lock(&mutex);
  caldeirao = N;
  printf("Cozinheiro encheu o caldeirão com %d porção(es).\n", caldeirao);
  sem_post(&servir_sem);
  pthread_mutex_unlock(&mutex);
}

void dormir()
{
  sleep(1);
  return;
}

void *cozinheiro(void *arg)
{
  while (1)
  {
    encher();
    dormir();
  }
}

int main()
{
  pthread_t canibais[NUM_CANIBAIS];
  pthread_t cozinheiro_thread;

  sem_init(&encher_caldeirao_sem, 0, 1);
  sem_init(&servir_sem, 0, caldeirao);

  for (long i = 0; i < NUM_CANIBAIS; i++)
  {
    pthread_create(&canibais[i], NULL, canibal, (void *)i);
  }

  pthread_create(&cozinheiro_thread, NULL, cozinheiro, NULL);

  for (int i = 0; i < NUM_CANIBAIS; i++)
  {
    pthread_join(canibais[i], NULL);
  }
  pthread_join(cozinheiro_thread, NULL);

  sem_destroy(&encher_caldeirao_sem);
  sem_destroy(&servir_sem);
  pthread_mutex_destroy(&mutex);

  return 0;
}
