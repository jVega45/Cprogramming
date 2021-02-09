/************************
This program is not finished.
Updates pending.
Date created: 09022021
**************************/
#include <stdio.h>
#define MAX_NAME_LENGTH 16
#define LIST_LENGTH 50

struct person
{
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[12]; // NB - 'nonbinary', 'male', or 'female' are accepted genders
};


int main()
{
    struct person list[LIST_LENGTH];
    printf("\n======Welcome to the Create a List of People Program======\n");
    printf("\nEnter people's names, age, and gender in that order.\n\n");
    printf("Rules: \n1) name cannot exceed 16 characters\n2) acceptable input for gender includes");
    printf(" the following: \"NB\" or \"nonbinary\", \"male\", or \"female\"");
    printf("\n3) the MAX number of people you can have in your list is 50\n");

    printf("\n\n-----Please enter the first person to your list-----\n\n");
    scanf("%s %d %s", list[0].name, &list[0].age, list[0].gender);
    printf("Your first person on your list: %s %d %s", list->name, list->age, list->gender);

    return 0;
}