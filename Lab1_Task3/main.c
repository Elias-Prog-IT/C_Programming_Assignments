#include <stdio.h>
#include <stdlib.h>

/*
    C programming
    Lab_1 TASK_3
    Elias Posluk
    Student-id: elp0006
    @date 2017-09-25
    Kristianstad University
*/
#define MAX  20

void printStars(int n) //function that prints the stars
{
    int i;
    for (i =1; i<=n; i++)
    {
        printf("*");
    }
}

void printSpace (int n) // function that prints spaces
{
    int i;
    for (i =1; i<=n; i++)
    {
        printf(" ");
    }
}

int main ( )
{
    //variables
    int size, numberOfStars, numberOfSpace;
    bool growing;

    do // User input in a do-while which checks if the input is inbetween the number 5 and 20
    {
        printf("Enter the number of rows in pyramid (5--%d):", MAX);
        scanf("%d", & size);//User input
    }
    while (size < 5 || size > MAX); //checks if its a valid size

    //initializes the variables
    growing = true;
    numberOfStars = 1;
    numberOfSpace = size -1;

    while (numberOfStars > 0 )
    {
        //calls the functions printSpace and printStars
       printSpace(numberOfSpace);
       printStars(numberOfStars);
       printf("\n");

       if (growing && (numberOfSpace < 1))
       {
           growing = false;
       }

       if (growing)//while its growing
       {
           numberOfSpace--;
           numberOfStars++;
       }
       if (!growing)//if it stops growing it will start shrinking
       {            // the output of stars and increase the output of space
           numberOfSpace++;
           numberOfStars--;
       }
    }
    return 0;
}
