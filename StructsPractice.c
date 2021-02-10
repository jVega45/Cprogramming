/************************
This program is not finished.
Updates pending.
Date created: 09022021
**************************/
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 16
#define LIST_LENGTH 50

struct person
{
    char name[MAX_NAME_LENGTH];
    int age;
    char gender[12]; // NB - 'nonbinary', 'male', or 'female' are accepted genders
};

// Function prototypes below
int validateUsrInput(struct person*, int);

int main()
{
    struct person list[LIST_LENGTH];
    int usrListLength = 0;
    printf("\n======Welcome to the Create a List of People Program======\n");
    printf("\nEnter people's names, age, and gender in that order.\n\n");
    printf("Rules: \n1) name cannot exceed 16 characters\n2) acceptable input for gender includes");
    printf(" the following: \"NB\" or \"nonbinary\", \"male\", or \"female\"");
    printf("\n3) the MAX number of people you can have in your list is 50\n");
    printf("\n\n-----Please enter how many people will be on your list-----\n");
    scanf("%d", &usrListLength);
    while(usrListLength > 50 || usrListLength <= 0)
    {
        printf("Please enter a valid number of people on the list. Must be < 50 and greater than 0\n");
        scanf("%d", &usrListLength);
    }
    printf("\n\n-----Please enter the people to your list; name first, then age, and then gender-----\n\n");
     
    int i; 
    for(i = 0; i < usrListLength; ++i)
    {
        scanf("%s %d %s", list[i].name, &list[i].age, list[i].gender);
        while(validateUsrInput(list, i) == 0)
        {
            printf("\nError!...Please enter valid person entries by adhering to the rules\n");
            scanf("%s %d %s", list[i].name, &list[i].age, list[i].gender);
        }
        printf("\nThat is valid entry!\n");
        if(i < (usrListLength - 1)) { printf("\nEnter the info of your next person.\n\n"); }        
    }
    printf("\n\n-----Your List of People-----\n\n");
    for(i = 0; i < usrListLength; i++)
    {
        printf("Person %d on your list: %s\n", i, list[i].name);
    }

    return 0;
}

int validateUsrInput(struct person* data, int index)
{
    int valid = 0; // valid = 1, not valid = 0

    switch(data[index].gender[0])
    {
        case 'N':

        case 'n':
            if((strcmp(data[index].gender, "NB") == 0) || (strcmp(data[index].gender, "nonbinary") == 0))
            {
                valid = 1;
            }
            break;

        case 'M':

        case 'm':
            if((strcmp(data[index].gender, "Male") == 0) || (strcmp(data[index].gender, "male") == 0))
            {
                valid = 1;
            }
            break;

        case 'f':

        case 'F':
            if((strcmp(data[index].gender, "Female") == 0) || (strcmp(data[index].gender, "female") == 0))
            {
                valid = 1;
            }
            break;

        default:
            valid = 0;
    }
    return valid;
}