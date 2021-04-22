#include<iostream>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

// Define thread task prototype
void *runner(void *param);

int sum = 0;

// Define a mutex
//pthread_mutex_t myMutex;

// Define a binary semaphore
sem_t mySem;

int main(int argc, char *argv[]) {

	if(argc != 2) {
		cerr << "Requires 2 arguments" << endl;
		return EXIT_FAILURE;	
	}

	if(atoi(argv[1]) <= 0) {
		cerr << "Second arg. needs to be positive" << endl;
		return EXIT_FAILURE;
	}

	// Initialize mutex
	// pthread_mutex_init(&myMutex, NULL);

	// Initialize binary semaphore
	sem_init(&mySem, 0, 1);

	// Define tread IDs, not initialization
	int num_of_threads = atoi(argv[1]);
	pthread_t tid[num_of_threads];

	// Define thread attributes (currently optional, not necessary for the current program)
	for(int i=0; i<num_of_threads; i++) {
		// Create Threads
		pthread_create(&tid[i], NULL, runner, NULL);
	}
	
	// Join Threads
	for(int i=0; i<num_of_threads; i++) {
		pthread_join(tid[i], NULL);
	}

	cout << "Sum is: " << sum << endl;
	return EXIT_SUCCESS;
}

// Implementation of Thread task
void *runner(void *param) {
	// Lock mutex
	// pthread_mutex_lock(&myMutex);

	// Semphore wait (decrease)
	sem_wait(&mySem);

	// Begin critical section
	sum++;
	// End critical section

	// Unlock mutex
	// pthread_mutex_unlock(&myMutex);

	// Semphore post (increase)
	sem_post(&mySem);
	pthread_exit(0);
}



