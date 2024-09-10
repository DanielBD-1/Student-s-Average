#ifndef AVERAGE_1
#define AVERAGE_1
#define MAX_STUDENTS 100
#pragma once
typedef struct student_init_data {

	int ID;
	int number_of_exams;
	int* grades;
}student_init_data;

student_init_data Students[MAX_STUDENTS];


typedef struct student_processed_data {

	int ID;
	float averageGrade;
}student_processed_data;


typedef struct statistics {

	student_processed_data* above_or_equal_average;
	student_processed_data* below_average;
	int students_below_average_count;
	int students_above_or_equal_average_count;
	float total_average;
}statistics;



int* input_Data(int);
float student_Average(int*, int);
float total_Average(float*, int);
void Classification(student_init_data*, int, float*, statistics*);
void print_Tab(statistics*, int);
void free_Memory(student_init_data*, int, statistics*);



#endif // !AVERAGE_1
