#include "linkedlist_functions.h"

#define SIZE 3


int main() {
	Student *head = calloc(1, sizeof(*head));

	Student *tmp = head;

	for(int i=0; i<SIZE; i++) {
		scanf("%s", tmp->name);
		scanf("%d", &tmp->age);
		
		if(i != SIZE-1){
			tmp->next = calloc(1, sizeof(*head));
			tmp = tmp->next;
		}
	}
	
	print_list(head);
	
	Student *student;
	student = calloc(1, sizeof(*student));
	strncpy(student->name, "John\0", 50);
	student->age = 45;

	insert_to_end(head, student);
	
	print_list(head);
	
	empty_list(head);

	return 0;
}


















