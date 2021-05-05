#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

#define BUFFER_SIZE 20
#define MAX_PRODUCER 1000
#define MAX_CONSUMER 1000


// Define the mutex or semaphores
pthread_mutex_t isEmpty[BUFFER_SIZE]; // = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t isFull[BUFFER_SIZE]; // = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t produceCount = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t consumerCount = PTHREAD_MUTEX_INITIALIZER;

// Define prototypes for producer and consumer
void *producer(void *arg);
void *consumer(void *arg);

// Define buffer array
int buffer[BUFFER_SIZE];

// Define full and empty count
int full_count = 0, empty_count = BUFFER_SIZE;
int produced = 0, consumed = 0;

// main function
int main() {

	pthread_t tid[MAX_PRODUCER + MAX_CONSUMER];
	srand(time(NULL));
	// initialize buffer array
	for(int i=0; i<BUFFER_SIZE; i++) {
		buffer[i] = 0;
		// initializing mutexes
		pthread_mutex_unlock(&isEmpty[i]);
		pthread_mutex_lock(&isFull[i]);
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
	
	cout << "Total Produce: " << produced << endl;
	cout << "Total Consumed: " << consumed << endl;

	for(int i=0; i<BUFFER_SIZE; i++) {
		cout << "buffer[" << i << "] = " << buffer[i] << endl; 
	}

	return EXIT_SUCCESS;
}


// Define producer function
void *producer(void *arg) {
	int index = 0, data;
	
	do {
		int producer_id = *((int *)arg);
		data = (rand() % 10) + 50;
		int i = 0;
		while(1) {
			if(pthread_mutex_trylock(&isEmpty[i]) == 0)
				break;
			i = (i+1) % BUFFER_SIZE;
		}
		
		//index = findFree();
		pthread_mutex_lock(&produceCount);
		produced++;
		pthread_mutex_unlock(&produceCount);
		buffer[i] = data;
		//cout << "Producer " << producer_id << " produced data=" <<  data << ", index=" << i << endl; 
		//cout << "TOTAL PRODUCE:" << produced << endl;
		pthread_mutex_unlock(&isFull[i]);
		index++;
	} while(index != 10);
}


// Define consumer function
void *consumer(void *arg) {
	int index = 0, data;
	do {
		int consumer_id = *((int *)arg);

		int i = 0;
		while(1) {
			if(pthread_mutex_trylock(&isFull[i]) == 0)
				break;
			i = (i+1) % BUFFER_SIZE;
		}

		//index = findFull();

		data = buffer[i];

		pthread_mutex_lock(&consumerCount);		
		consumed++;
		pthread_mutex_unlock(&consumerCount);

		buffer[i] = 0;
		//cout << "Consumer " << consumer_id << " consumed data=" <<  data << ", index=" << i << endl; 
		//cout << "TOTAL CONSUME:" << consumed << endl;
		pthread_mutex_unlock(&isEmpty[i]);
		index++;
	} while(index != 10);
}

