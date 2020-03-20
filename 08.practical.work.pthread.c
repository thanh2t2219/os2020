#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* prime(void * arg) {
	for(int i=2; i<=1000000; i++) {
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
}

int main() {
	pthread_t newthread;

	pthread_create(&newthread, NULL, prime, NULL);
	fibonacci();

	pthread_join(newthread, NULL);
}
