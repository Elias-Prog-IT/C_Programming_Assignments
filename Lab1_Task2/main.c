
#include <stdio.h>
#include <stdlib.h>

/*
    C programming
    Lab_1 TASK_2
    Elias Posluk
    Student-id: elp0006
    @date 2017-09-25
    Kristianstad University
*/

int main()
{
    //Variables
    int inputNumber, randomNr, randomNr2, sumRand = 0;
    char choice =' ';

   printf("hello and welcome to addition calculator, \nwhere you will be given a randomized number to add togheter.");

   do
    {
        srand(time(NULL));//to be able to generate random numbers.

        randomNr = rand() % 100 +1;//randomnr and randomnr2gets a random generated number, up to a hundred.
        randomNr2 = rand() % 100 +1;

        sumRand = randomNr2 + randomNr;

        printf("\nhow much is %d + %d? ", randomNr, randomNr2);
        scanf("%d",&inputNumber); //user types in the input.


        if(sumRand == inputNumber)//if user input is equal to the sum of the two random numbers.
        {
            printf("well done, you got it right!");//It will print out a positive response and end the program.
            break;
        }

            printf("ah bugger, do you want to try again? y/n \n");//if the input from the user isn't equal to the sumRand, then
                                                                //you get an option to try again, or end the program.
            scanf(" %c",&choice);

     } while(choice == 'y'||choice == 'Y');//if user presses 'y' then the program starts over again, otherwise it stops.

    return 0;
 }
