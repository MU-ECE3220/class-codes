#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct StudentInfo {

	struct StudentInfo *next;
	char name[50];
	int age;
}Student;

void insert_to_end(Student *list, Student *data);
void print_list(Student *list);
void empty_list(Student *list);
