#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

typedef struct StudentInfo {

	struct StudentInfo *next;
	char name[50];
	int age;
}Student;

int main() {

	Student *head = malloc(sizeof(*head));
			
	Student *tmp = head;

	for(int i=0; i<SIZE; i++) {
		scanf("%s", tmp->name);
		scanf("%d", &tmp->age);

		tmp->next = malloc(sizeof(*head));
		tmp = tmp->next;
	}

	tmp = head;

	while(tmp != NULL){
		printf("%s\n",tmp->name);
		printf("%d\n",tmp->age);
		tmp = tmp->next;
	}

	tmp = head;

	while(tmp != NULL) {
		Student *p;
		p = tmp;
		tmp = tmp->next;
		free(p);
	}

	return 0;
}
