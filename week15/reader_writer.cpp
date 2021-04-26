#include<iostream>
#include<unistd.h>
#include<pthread.h>

#define NUM_OF_THREADS 40

using namespace std;

// mutex between writer and reader
pthread_mutex_t writer_lock;
pthread_mutex_t reader_lock;

int reader_count = 0;

int data = 0;

// Define thread tasks
void *reader(void *arg);
void *writer(void *arg);

int main() {

	pthread_t tid[NUM_OF_THREADS];
	int thread_num[NUM_OF_THREADS];
	srand(time(NULL));

	// init mutex
	if(pthread_mutex_init(&writer_lock, NULL) != 0) {
		cerr << "Error: Cannot initiate writer mutex" << endl;
		return EXIT_FAILURE;
	}

	if(pthread_mutex_init(&reader_lock, NULL) != 0) {
		cerr << "Error: Cannot initiate reader mutex" << endl;
		return EXIT_FAILURE;
	}

	// create NUM_OF_WRITER amount of writer threads
	for(int i=0; i<NUM_OF_THREADS-2; i++) {
		thread_num[i] = i+1;
		//if((rand()%3) > 1)
			pthread_create(&tid[i], NULL, writer, &thread_num[i]);
		//else 
		//	pthread_create(&tid[i], NULL, reader, &thread_num[i]);
	}

	for(int i=NUM_OF_THREADS-2; i<NUM_OF_THREADS; i++) {
		thread_num[i] = i+1;
		pthread_create(&tid[i], NULL, reader, &thread_num[i]);
	}

	// Join and run threads
	for(int i=0; i<NUM_OF_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}

	// destroy the mutex
	pthread_mutex_destroy(&writer_lock);
	pthread_mutex_destroy(&reader_lock);
	return EXIT_SUCCESS;
}

//WRITER
void *writer(void *arg) {

	int *thread_no = (int *)arg;
	while(1) {
		//obtain the lock
		pthread_mutex_lock(&writer_lock);
		// Critical Section BEGIN
		
		data++;
		cout << "Writer thread #" << (*thread_no) << ", data=" << data << endl;
		//sleep(1);
		// Critical Section END
		pthread_mutex_unlock(&writer_lock);
		//release the lock
	}
}

//READER
void *reader(void *arg) {
	int *thread_no = (int *)arg;
	//obtain the lock
	while(1) {
		pthread_mutex_lock(&reader_lock);
		if(reader_count == 0) 
			pthread_mutex_lock(&writer_lock);
		
		reader_count++;
		pthread_mutex_unlock(&reader_lock);

		// Critical Section BEGIN
		
		cout << "RC= "<< reader_count << "Reader thread #" << (*thread_no) << ", reading data=" << data << endl;

		// Critical Section END
		sleep(1);
		pthread_mutex_lock(&reader_lock);
		reader_count--;
		if(reader_count == 0)
			pthread_mutex_unlock(&writer_lock);
		pthread_mutex_unlock(&reader_lock);
	}
	//release the lock
}


