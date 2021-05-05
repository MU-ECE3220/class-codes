#include<iostream>
#include<pthread.h>
#include<semaphore.h>

using namespace std;

#define NUMBER_OF_THREADS 5
// define room size for semaphore
#define ROOM_SIZE 4
// initialize mutexes
pthread_mutex_t chopstick[5] = PTHREAD_MUTEX_INITIALIZER;

// define semaphore
sem_t isEating;

void think(int);
void eat(int);
void *philosopher(void*);

// print thinking message
void think(int id) {
	cout << "Philosopher ID: "<< (id+1) << "is thinking" << endl;
}

// print eating message
void eat(int id) {
	cout << "Philosopher ID: "<< (id+1) << "is eating" << endl;
}

void *philosopher(void *id) {
	//receive philosopher id
	int philoID = *((int *)id);

	while(1) {
		think(philoID);
		// only allow max 4 threads 
		sem_wait(&isEating);
		// lock left chopstick
		pthread_mutex_lock(&chopstick[philoID]);
		// lock right chopstick
		pthread_mutex_lock(&chopstick[((philoID+1)%5)]);
		eat(philoID);
		// unlock right chopstick
		pthread_mutex_unlock(&chopstick[((philoID+1)%5)]);
		// unlock left chopstick
		pthread_mutex_unlock(&chopstick[philoID]);
		// signal the semaphore
		sem_post(&isEating);
	}
}

int main() {

	pthread_t tid[5];
	pthread_attr_t attr[5];
	
	int i=0;
	// initialize and error check semaphore
	if(sem_init(&isEating, 0, ROOM_SIZE) != 0)
	{
		printf("ERROR: cannot create semaphore\n");	
		return -1;
	}

	//create and initialize threads
	for(i=0; i<NUMBER_OF_THREADS; i++) {
		void *memory = malloc(sizeof(int));
		int* id = (int *) memory;
		*id = i;
		pthread_attr_init(&attr[i]);
		pthread_create(&tid[i], &attr[i], philosopher, id);
	}
	// join the threads
	for(i=0; i<NUMBER_OF_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}

	return EXIT_SUCCESS;
}
