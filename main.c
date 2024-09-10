#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Average.h"

int main() {

	int number_of_students;
	int i;
	float* average_grades = NULL;
	statistics stats;
	printf("===================================================\n");
	printf(" _    _      _                            _          \n");
	printf("| |  | |    | |                          | |         \n");
	printf("| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___    \n");
	printf("| |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\   \n");
	printf("\\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) |  \n");
	printf(" \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   \n");

	printf("Please Enter Number of Students: ");
	scanf_s("%d", &number_of_students);
	if (number_of_students > MAX_STUDENTS || number_of_students <= 0) {
		printf("Invalid Input");
		return 1;
	}
	printf("\n");

	average_grades = (float*)malloc(number_of_students * sizeof(float));
	if (average_grades == NULL) {
		printf("Allocation Failed!");
		return 1;
	}

	for (i = 0; i < number_of_students; i++) {

		printf("Please Enter Student's ID: ");
		scanf_s("%d", &Students[i].ID);

		printf("\n");

		printf("Please Enter Number of Exams: ");
		scanf_s("%d", &Students[i].number_of_exams);

		printf("\n");

		Students[i].grades = input_Data(Students[i].number_of_exams);
		if (Students[i].grades == NULL) {
			printf("Failed to allocate memory for grades. Exiting.\n");
			exit(1);
		}

		average_grades[i] = student_Average(Students[i].grades, Students[i].number_of_exams);

	}
	printf("\n\n\n");
	Classification(Students, number_of_students, average_grades, &stats);
	print_Tab(&stats, number_of_students);
	free_Memory(Students, number_of_students, &stats);
	free(average_grades);



}