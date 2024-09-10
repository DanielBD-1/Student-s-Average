#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Average.h"


int* input_Data(int number_of_exams) {

	int* grades;
	int i;

	grades = (int*)malloc(number_of_exams * sizeof(int));
	if (grades == NULL) { 
		printf("Memory Allocation Failed for grades!\n");
		return NULL;
	}
	for (i = 0; i < number_of_exams; i++) {

		printf("Enter Grade %d: ", i + 1);
		scanf_s("%d", &grades[i]);

		while (grades[i] < 0 || grades[i] > 100) {
			printf("Invalid Input, please enter a grade between 0 and 100.\n");
			printf("Enter Grade %d (0-100): ", i + 1);
			scanf_s("%d", &grades[i]);
		}
		printf("\n");
	}
	
	return grades;
}

float student_Average(int* grades, int number_of_exams) {

	int sum = 0; 
	int i;

	for (i = 0; i < number_of_exams; i++)
		sum += grades[i];
	return (float)sum / number_of_exams;

}


float total_Average(float* average_grades, int number_of_students) {

	int i;
	float sum = 0;

	for (i = 0; i < number_of_students; i++)
		sum += average_grades[i];
	return (float)sum / number_of_students;

}

void Classification(student_init_data* Student, int number_of_students, float* average_grades, statistics* stats) {

	int i;

	stats->total_average = total_Average(average_grades, number_of_students);
	stats->students_below_average_count = 0;
	stats->students_above_or_equal_average_count = 0;

	for (i = 0; i < number_of_students; i++) {

		if (average_grades[i] >= stats->total_average)
			stats->students_above_or_equal_average_count++;
		else
			stats->students_below_average_count++;
	}

	stats->above_or_equal_average = (student_processed_data*)malloc(stats->students_above_or_equal_average_count * sizeof(student_processed_data));
	stats->below_average = (student_processed_data*)malloc(stats->students_below_average_count * sizeof(student_processed_data));
	if (stats->above_or_equal_average == NULL || stats->below_average == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	int above_index = 0;
	int below_index = 0;
	for (i = 0; i < number_of_students; i++) {

		student_processed_data spd;
		spd.ID = Student[i].ID;
		spd.averageGrade = average_grades[i];

		if (average_grades[i] >= stats->total_average)
			stats->above_or_equal_average[above_index++] = spd;
		else
			stats->below_average[below_index++] = spd;

	}

}

void print_Tab(statistics* stats, int number_of_students) {

	int i;

	printf("Total Average is: %.2lf \n", stats->total_average);

	for (i = 0; i < stats->students_above_or_equal_average_count; i++) {

		printf("Students Above or Equal to Average: \n Student's ID: %d , Average Grade: % .2lf \n"
			, stats->above_or_equal_average[i].ID, stats->above_or_equal_average[i].averageGrade);

	}

	for (i = 0; i < stats->students_below_average_count; i++) {
		printf("Students Below Average: \n Student's ID: %d , Average Grade: %.2lf \n"
			, stats->below_average[i].ID, stats->below_average[i].averageGrade);

	}
}


	void free_Memory(student_init_data* Students, int number_of_students, statistics* stats) {

		int i;

		for (i = 0; i < number_of_students; i++) {
			free(Students[i].grades);
		}

		free(stats->above_or_equal_average);
		free(stats->below_average);
	}

