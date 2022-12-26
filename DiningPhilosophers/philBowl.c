#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
//#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>

int philosophers[5]={0,1,2,3,4};
int forks[5]={0,1,2,3,4};
int bowls[2]={0,1};

void philosopher(int n){
    int left=n%5;
    int right=(n+1)%5;
    printf("Philosopher %d is picking up fork %d and %d\n",n,left,right);
    printf("Philosopher %d is using bowl %d\n",n,n%2);
    printf("Philosopher %d is eating\n",n);
    sleep(1);
    printf("Philosopher %d is putting down fork %d and %d\n",n,left,right);
}

int main(){
    int i=0;
    while(1){
        pthread_t p[2];
        philosopher(i);
        philosopher(i+2);
        i++;
        if(i==3){
            i=0;
        }
    }
}