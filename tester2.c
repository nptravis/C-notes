#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>


typedef struct Student
{
	int RollNo;
	char Name[3];
	double Marks;
}Student;
/* // this section to write to a file
int main (void)
{
	Student s1,s2;
	FILE *file = fopen("students.txt", "w+");

	if (file == NULL)
	{
		printf("Can't read file");
		return 1;
	}

	while(1)
	{
		printf("Enter roll number: ");
		scanf("%d", &s1.RollNo);
		printf("Enter Name: ");
		scanf("%s", s1.Name);
		printf("Enter Marks: ");
		scanf("%lf", &s1.Marks);
  

		fprintf(file, "%d\t%s\t%lf\n", s1.RollNo, s1.Name, s1.Marks);
		printf("Continue? Press 1 for Yes or 2 for No: ");
		int Answer;
		scanf("%d", &Answer);
		if(Answer == 2)
		{
			break;
		}
  }
	fclose(file);	
	return 0;
} */
// this section to read from a file
int main (void)
{
	Student s1,s2;
	FILE *file = fopen("students.txt", "r+");

	if (file == NULL)
	{
		printf("Can't read file");
		return 1;
	}

	while(1)
	{
		int cnt= fscanf(file, "%d\t%s\t%lf\n", &s1.RollNo, s1.Name, &s1.Marks);
		if (cnt == -1)
			break;
		printf("%d\t%s\t%lf\n", s1.RollNo, s1.Name, s1.Marks);
		
  }
	fclose(file);	
	return 0;
}