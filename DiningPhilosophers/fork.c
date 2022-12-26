#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
//#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>

sem_t forks[5];

void philosopher(int n){
    while(1){
        if(n==4){
            printf("Philosopher %d is thinking\n",n);
            sem_wait(&forks[0]);
            sem_wait(&forks[4]);
            printf("Philosopher %d is eating\n",n);
            sleep(1);
            sem_post(&forks[0]);
            sem_post(&forks[4]);
        }
        else{
            printf("Philosopher %d is thinking\n",n);
            sem_wait(&forks[n]);
            sem_wait(&forks[n+1]);
            printf("Philosopher %d is eating\n",n);
            sleep(1);
            sem_post(&forks[n]);
            sem_post(&forks[n+1]);
        }
    }
}

int main(){
    //dining philosopher problem
    pthread_t p[5];
    for (int i=0;i<5;i++){
        sem_init(&forks[i],0,1);
    }
    for (int i=0;i<5;i++){
        pthread_create(&p[i],NULL,(void *)philosopher,(void *)i);
    }
    for (int i=0;i<5;i++){
        pthread_join(p[i],NULL);
    }
    return 0;
}