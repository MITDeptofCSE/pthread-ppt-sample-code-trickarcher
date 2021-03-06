#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;

void runner(void* args);

int main(int argc, char** argv) {
	pthread_t tid;
	pthread_attr_t attr;

	if(argc != 2) {
		fprintf(stderr, "usage a.out <integer value>\n");
		return -1;
	}

	int arg_int = atoi(argv[1]);
	if(arg_int < 0) {
		fprintf(stderr, "%d must be >= 0\n", arg_int);
		return -1;
	}

	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, (void*)runner, (void*)&arg_int);

	pthread_join(tid, NULL);

	printf("sum = %d\n", sum);
}

void runner(void* args) {
	int i; 
	int upper = *((int*)(args));
	sum = 0;

	for(i = 1; i <= upper; i++)
		sum += i;
	pthread_exit(0);
}
