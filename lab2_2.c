/*lab2 prog2- print the student's name and average if its greater than 85*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stud
{
	char* name;
	int marks[4];
	float avg;
}student;


student* Create_Class(int);
void Avg_Mark(student*);
void Print_One(student*);



int a_main()
{
	int size, i;
	student* arr;
	printf("Enter the number of students:");
	scanf("%d", &size);
	arr = Create_Class(size);
	for (i = 0; i < size; i++) // Print the students name and average if greater then 85
		if (arr[i].avg > 85)
			Print_One(&arr[i]);


	return 0;


}
/*func name: Create_Class
input: int size
output: pointer to arr
algorithm: create an array of students and insert their marks and name to each student accordingly.*/

student* Create_Class(int size)
{
	int i,j,name_len;
	student* arr;
	char student_name[50];

	arr = (student*)malloc(size * sizeof(student)); // Allocate memory to the name of each student by its size. 

	if (arr == NULL) {
		free(arr);
		exit(1);
	}


	for (i = 0; i < size; i++) {
		printf("\nEnter your name:");
		scanf("%s", student_name);

		name_len = strlen(student_name);

		arr[i].name = (char*)malloc((name_len + 1) * sizeof(char));// Allocate memory to the name of each student by its size. 
		if (arr[i].name == NULL) {
			free(arr[i].name);
			exit(1);
		}
		
			

		strcpy(arr[i].name, student_name);// Copy the name of the student into its struct.

		printf("\nEnter your marks:");
		for (j = 0; j < 4; j++)
			scanf("%d", &arr[i].marks[j]);// Scan the marks into the struct.
		Avg_Mark(&arr[i]);
	
	}
	free(arr[i].name);
	free(arr);

	return arr;
}


/*func name: Avg_Mark
input: student* s
output: none
algorithm: calculate the average of a given student.*/

void Avg_Mark(student* s)
{
	float sum=0;
	int i;
	for (i = 0; i < 4; i++)
		sum +=(s->marks[i]); 
	(s->avg) = sum / 4.0; // Assign the average to the student struct. 

}

/*func name: Print_One
input: student* s
output: none
algorithm: print the name and avg of given student
*/
void Print_One(student* s)
{
	printf("\nthe average of %s is %0.1lf", s->name, s->avg);
}

