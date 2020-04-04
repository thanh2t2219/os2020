#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t = lock;
void* prime(void * arg) {
	for(int i=2; i<=1000000; i++) {
		sem_wait(&lock);
		int count = 0;
		for(int j=2; j<=i; j++) {
			if(i%j==0){
				count++;
			}
		}
		if (count == 1) {
			sleep(1);
			printf("Prime number: %d\n", i);
		}
	}
	return NULL;
}

void fibonacci() {
	int num = 2, previous = 1;
	for(int i=0; i<1000000; i++) {
		sleep(1);
		printf("%d\n", num);
		int next = num + previous;
		previous = num;
		num = next;
		
		if(num >= 1000000){
			break;
		}
	}
	sem_wait(&lock);
	printf("");
	sem_post(&lock);
	return NULL;
}

int main() {
	sem_init(&lock, 0, 1);
	pthread_t newthread1;
	pthread_t newthread2;

	pthread_create(&newthread1, NULL, prime, NULL);
	pthread_create(&newthread2, NULL, fibonacci, NULL);
	pthread_join(newthread1, NULL);
	pthread_join(newthread2, NULL);
	sem_destroy(&lock);
	return 0;
}
