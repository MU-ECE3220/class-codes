#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

#define BUFFER_SIZE 20
#define MAX_PRODUCER 15
#define MAX_CONSUMER 5


// Define the mutex or semaphores
pthread_mutex_t isEmpty = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t isFull = PTHREAD_MUTEX_INITIALIZER;

// Define prototypes for producer and consumer
void *producer(void *arg);
void *consumer(void *arg);
int findFree();
int findFull();

// Define buffer array
int buffer[BUFFER_SIZE];

// Define full and empty count
int full_count = 0, empty_count = BUFFER_SIZE;
int produced = 0, consumed = 0;

// Helper function: find free space in array
int findFree() {
	int i;
	for(i=0; i<BUFFER_SIZE; i++){
		if(buffer[i] == 0)
			return i;
	}
	return i;
}

// Helper function: find filled space in array
int findFull() {
	int i;
	for(i=0; i<BUFFER_SIZE; i++){
		if(buffer[i] != 0)
			return i;
	}
	return i;
}

// main function
int main() {

	pthread_t tid[MAX_PRODUCER + MAX_CONSUMER];
	srand(time(NULL));
	// initialize buffer array
	for(int i=0; i<BUFFER_SIZE; i++) {
		buffer[i] = 0;
	}

	// Create the threads

	// Create producer threads
	for(int i=0; i<MAX_PRODUCER; i++){
		void *memory = new int;
		int *p = (int *)memory;
		*p = i + 1;
		pthread_create(&tid[i], NULL, producer, p);
	}

	// Create consumer threads
	for(int i=0; i<MAX_CONSUMER; i++){
		void *memory = new int;
		int *p = (int *)memory;
		*p = i + 1;
		pthread_create(&tid[i + MAX_PRODUCER], NULL, consumer, p);
	}

	// Join the threads
	for(int i=0; i<MAX_PRODUCER + MAX_CONSUMER; i++) {
		pthread_join(tid[i], NULL);
	}

	return EXIT_SUCCESS;
}


// Define producer function
void *producer(void *arg) {
	int index, data;
	
	do {
		int producer_id = *((int *)arg);
		data = (rand() % 10) + 50;

		while(1) {
			if(pthread_mutex_lock(&isEmpty) == 0) {
				cout<< "SUCCESS" << endl;
				break;
			}
			else {
				cout<< "Ooops maybe next time " << producer_id << "..." << endl;
			}
		}

		index = findFree();
		
		produced++;
		buffer[index] = data;
		cout << "Producer " << producer_id << " produced data=" <<  data << ", index=" << index << endl; 
		cout << "TOTAL PRODUCE:" << produced << endl;
		pthread_mutex_unlock(&isFull);

	} while(1);
}


// Define consumer function
void *consumer(void *arg) {
	int index, data;
	do {
		int consumer_id = *((int *)arg);

		pthread_mutex_lock(&isFull);

		index = findFull();

		data = buffer[index];		
		consumed++;
		buffer[index] = 0;
		cout << "Consumer " << consumer_id << " consumed data=" <<  data << ", index=" << index << endl; 
		cout << "TOTAL CONSUME:" << consumed << endl;
		pthread_mutex_unlock(&isEmpty);

	} while(1);
}

