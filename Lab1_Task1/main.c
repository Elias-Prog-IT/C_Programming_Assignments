
#include <stdio.h>
#include <stdlib.h>

/*
    C programming
    Lab_1 TASK_1
    Elias Posluk
    Student-id: elp0006
    @date 2017-09-25
    Kristianstad University
*/

int main()
{
    //task 1
   int num = 0 , row = 0, cols = 0;

    printf("enter the desired size of the table: ");
    scanf("%d", &num);//get input from user

    for(row = 1; row <= num; row++)//counts from row which is 1, up to the user input which is num
    {
       for(cols = 1; cols <= num; cols++ )// this is from columns side, which will count up to num as well
       {
           printf("%i\t",   row * cols ); //prints out the product when multiplied.
       }
        printf("\n"); //printing out a new line for every new row
    }
    return 0;
}
