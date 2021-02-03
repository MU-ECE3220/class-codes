#include "linkedlist_functions.h"

void insert_to_end(Student *list, Student *data) {
	Student *temp = list;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = data;
}

void print_list(Student *list) {
	while(list != NULL){
		printf("%s\n",list->name);
		printf("%d\n",list->age);
		list = list->next;
	}
}

void empty_list(Student *list) {
	while(list != NULL) {
		Student *p;
		p = list;
		list = list->next;
		free(p);
	}
}
