#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

/*
    Elias Posluk
    Högskolan Kristianstad
    C programming
    Lab 3, Task 1 option 2
    10/01/2017
*/


int practices[16] = {0};
int right_answer = 0;
char response_correct[7][100] = {"Very good!\n", "Excellent!\n", "Nice work!\n", "Well done!\n", "Great!\n", "Keep up the good work!\n"};
char response_wrong[5][100] = {"No. Please try again.\n", "Wrong. Try once again.\n", "Dont give up!\n", "No. Keep trying.\n"};
char questions[16][100] = {""};
int correct_answer[16];
int your_answer[16];
FILE *fp;

void pracitce_additions()// additions function, for practice
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("\n");
        int a, b, result, answer;
        srand(time(NULL));
        a = rand() % 30;
        b = rand() % 30;
        result = a + b;
        printf("%d. %d + %d = ", (i+1), a, b);
again:
        printf("\nEnter your answer: ");
        int correct = rand() % 5;
        int wrong = rand() % 3;
        scanf("%d", &answer);
        if(result == answer)
        {
            printf(response_correct[correct]);//Giving different positive responses
        }
        else
        {
            printf(response_wrong[wrong]);//Giving different negative responses
            goto again;
        }
    }
}

void pracitce_subtractions()// subtraction function, for practice
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("\n");
        int a, b, result, answer;
        srand(time(NULL));
        a = rand() % 30;
        b = rand() % 30;
        result = a - b;
        printf("%d. %d - %d = ", (i+1), a, b);
again:
        printf("\nEnter your answer: ");
        int correct = rand() % 5;
        int wrong = rand() % 3;
        scanf("%d", &answer);
        if(result == answer)
        {
            printf(response_correct[correct]);
        }
        else
        {
            printf(response_wrong[wrong]);
            goto again;
        }
    }
}

void practice_both()  // a combination of both subtraction and addition
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("\n");
        int a, b, c, result, answer, opera;
        srand(time(NULL));
        a = rand() % 30;
        b = rand() % 30;
        c = rand() % 30;
        opera = rand() % 2;
        if(opera == 0)
        {
            printf("%d. %d + %d = ", (i+1), b, c);
            result = b - c;
        }
        else if(opera == 1)
        {
            printf("%d. %d + %d = ", (i+1), a, b);
            result = a + b;
        }

again:
        printf("\nEnter your answer: ");
        int correct = rand() % 5;
        int wrong = rand() % 3;
        scanf("%d", &answer);
        if(result == answer)
        {
            printf(response_correct[correct]);
        }
        else
        {
            printf(response_wrong[wrong]);
            goto again;
        }
    }
}

void test_additions() //Test for only addition, every arithmetical question gets saved into the question[] array
{                         //as well as the input answer from the user and the correct answer gets saved into the array.
    int i = 0;
    for(i = 0; i < 15; i++)
    {
        printf("\n");
        int a, b, result, answer;
        srand(time(NULL));
        a = rand() % 30;
        b = rand() % 30;
        result = a + b;
        printf("%d. %d + %d = ", (i+1), a, b);
        printf("\nEnter your answer: ");
        scanf("%d", &answer);
        if(result == answer)
        {
            printf("Very good!\n");
            right_answer += 1;
        }
        char numbers[10];
        sprintf(numbers,"%d", a);
        strcat(questions[i], numbers);
        strcat(questions[i], "+");
        sprintf(numbers,"%d", b);
        strcat(questions[i], numbers);
        correct_answer[i] = result;
        your_answer[i] = answer;
    }
}

void test_subtractions()//test for only subtraction, every arithmetical question gets saved into the question[] array
{                        //as well as the input answer from the user and the correct answer gets saved into the array.
    int i = 0;
    for(i = 0; i < 15; i++)
    {
        printf("\n");
        int a, b, result, answer;
        srand(time(NULL));
        a = rand() % 30;
sub:
        b = rand() % 30;//A workaround to see that you never get out a negative number as a sum. a part of the requirment in assignment 3 in task2 option 2
        if(a < b)
        {
            goto sub;
        }
        result = a - b;
        printf("%d. %d - %d = ", (i+1), a, b);
        printf("\nEnter your answer: ");
        scanf("%d", &answer);
        if(result == answer)
        {
            printf("Very good!\n");
            right_answer += 1;
        }
        char numbers[10];
        sprintf(numbers,"%d", a);
        strcat(questions[i], numbers);
        strcat(questions[i], "-");
        sprintf(numbers,"%d", b);
        strcat(questions[i], numbers);
        correct_answer[i] = result;
        your_answer[i] = answer;
    }
}

void test_both()//Combination for both subtraction and addition, every arithmetical question gets saved into the question[] array
{               //as well as the input answer from the user and the correct answer gets saved into the array.
    int i = 0;
    for(i = 0; i < 15; i++)
    {
        printf("\n");
        int a, b, c, result, answer, opera;
        srand(time(NULL));
        a = rand() % 30;
        b = rand() % 30;
        c = rand() % 30;
        opera = rand() % 2;
        char numbers[10];
        if(opera == 0)
        {
            printf("%d. (%d + %d) - %d = ", (i+1), a, b, c);
            if ((a+b)< c) // Making sure that the user doesn't get a negative sum as answer, according to the assignment
            {
            result = a + b - c;
            }
            else
            {
            result = a + b - c;
            }
            sprintf(numbers,"%d", a);
            strcat(questions[i], numbers);
            strcat(questions[i], "+");
            sprintf(numbers,"%d", b);
            strcat(questions[i], numbers);
            strcat(questions[i], "-");
            sprintf(numbers,"%d", c);
            strcat(questions[i], numbers);
        }
        else if(opera == 1)
        {
            printf("%d. %d - (%d + %d) = ", (i+1), a, b, c);
            if ((a+c)<b)// Making sure that the user doesn't get a negative sum as answer, according to the assignment
            {
                result = b - (a+c);
            }
            else
            {
                result = (a + c) - b ;
            }
            sprintf(numbers,"%d", a);
            strcat(questions[i], numbers);
            strcat(questions[i], "-");
            sprintf(numbers,"%d", b);
            strcat(questions[i], numbers);
            strcat(questions[i], "+");
            sprintf(numbers,"%d", c);
            strcat(questions[i], numbers);
        }
        printf("\nEnter your answer: ");
        scanf("%d", &answer);
        if(result == answer)
        {
            printf("Very good!\n");
            right_answer += 1;
        }
        correct_answer[i] = result;
        your_answer[i] = answer;
    }
}

void result() //function that prints out the result
{
    int i;
    printf("Your score is: %f%c\n", (right_answer * 0.15), 37);
    printf("Detailed questions and answers: \n");
    printf("%-15s %-10s %-10s","Question", "Correct answer", "Your answer\n");
    for(i = 0; i < 15; i++)
    {
        printf("%d. %-10s   %-10d\t%-10d\n", (i+1), questions[i], correct_answer[i], your_answer[i]);
    }
}

void clrscr() // function that clears the screen
{
    system("@cls||clear");
}

// for writing into text file
// passing required variables
void writeToFile(int result, int type, char username[100])
{
    time_t t = time(NULL);
    const struct tm *tm = localtime(&t); // getting local time
    char s[64];
    strftime(s, sizeof(s), "%Y-%m-%d", tm); // converting current date to a format
    fprintf(fp, "%d,%d,%s,%s\n", result, type, username, s); // writing to the file

    fclose(fp); //  closing the file
}

int main()
{
    char results[100][10], type[100][3], date[100][20], username[100][50];
    fp = fopen("result.csv", "a"); // opening file to write in data
    printf("Enter your name: ");
    char name[100];
    int choice, choice2;
    gets(name);

    printf("Welcome, %s!", name);

menu:
    printf("\nYou can choose: \n");
    printf("\t1. do practices\n");
    printf("\t2. complete a test\n");
    printf("\t3. my test history\n");
    printf("\t4. top 5\n");
    printf("\t5. quit the program\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Now, you can choose to do practices on: \n");
        printf("\t1. Additions\n");
        printf("\t2. subtractions\n");
        printf("\t3. additions and subtractions\n");

        printf("Enter your choice: ");
        scanf("%d", &choice2);

        if(choice2 == 1)
        {
            printf("Now, you will be given 10 questions to solve: \n");
            pracitce_additions();
            clrscr();
            goto menu;
        }
        else if(choice2 == 2)
        {
            printf("Now, you will be given 10 questions to solve: \n");
            pracitce_subtractions();
            clrscr();
            goto menu;
        }
        else if(choice2 == 3)
        {
            printf("Now, you will be given 10 questions to solve: \n");
            practice_both();
            clrscr();
            goto menu;
        }
    }
    else if(choice == 2)
    {
        printf("Now, you can choose to do test on: \n");
        printf("\t1. Additions\n");
        printf("\t2. Subtractions\n");
        printf("\t3. Additions and Subtractions\n");

        printf("Enter your choice: ");
        scanf("%d", &choice2);

        if(choice2 == 1)
        {
            printf("Now, you will be given 15 addition questions to solve: \n");
            test_additions();
            result();
            writeToFile(right_answer, choice2, name);
            goto menu;
        }
        else if(choice2 == 2)
        {
            printf("Now, you will be given 15 subtraction questions to solve: \n");
            test_subtractions();
            result();
            writeToFile(right_answer, choice2, name);
            goto menu;
        }
        else if(choice2 == 3)
        {
            printf("Now, you will be given 15 questions of both addition and subtraction to solve: \n");
            test_both();
            result();
            writeToFile(right_answer, choice2, name);
            goto menu;
        }
    }
    else if(choice == 3)
    {
        char str[100];
        fclose(fp); // closing last file
        fp = fopen("result.csv", "r"); // opening the file again to read
        int i = 0, j;
        printf("\nMy results: \n");
        printf("Results    Test type    Date\n");
        while(fgets(str,100,fp)) // reading line by line
        {
            int n = 1;
            char *pch;
            pch = strtok(str, ","); // tokenize the line against comma operator
            while (pch != NULL)
            {
                if(n == 1)
                {
                    strcpy(results[i], pch); // copy into array element
                }
                else if(n == 2)
                {
                    strcpy(type[i], pch); // copy into array element
                }
                else if(n == 3)
                {
                    strcpy(username[i], pch); // copy into array element
                }
                else if(n == 4)
                {
                    strcpy(date[i], pch); // copy into array element
                }
                pch = strtok (NULL, ",");
                ++n;
            }
            i++;
        }
        // printing user test results
        for(j = 0; j < i; j++)
        {
            char namee[100];
            strcpy(namee,username[j]);
            if(strcmp(namee,name) == 0) // comparing name
            {
                printf("%s          %s            %s\n", results[j], type[j], date[j]);
            }
        }
        fclose(fp);
        goto menu;
    }
    else if(choice == 4)
    {
        char str[100];
        fclose(fp);
        fp = fopen("result.csv", "r");
        int i = 0, j;
        printf("User name    Test type  Result  Date\n");
        while(fgets(str, 100, fp))
        {
            int n = 1;
            char *pch;
            pch = strtok(str, ",");
            while (pch != NULL)
            {
                if(n == 1)
                {
                    strcpy(results[i], pch);
                }
                else if(n == 2)
                {
                    strcpy(type[i], pch);
                }
                else if(n == 3)
                {
                    strcpy(username[i], pch);
                }
                else if(n == 4)
                {
                    strcpy(date[i], pch);
                }
                pch = strtok (NULL, ",");
                ++n;
            }
            i++;
        }
        int n = i;
        int max;
        char temp[100];
        //getting top 5 result
        // here I am sorting all arrays
        for (i = 0; i < 5; i++)
        {
            max = i;
            for (j = i + 1; j < n; j++)
            {
                if(strcmp(results[j], results[max]) == 1)
                {
                    max = j;
                }
            }
            // swapping elements
            // swapping result
            strcpy(temp, results[i]);
            strcpy(results[i], results[max]);
            strcpy(results[max], temp);
            // swapping username
            strcpy(temp, username[i]);
            strcpy(username[i], username[max]);
            strcpy(username[max], temp);
            // swapping type
            strcpy(temp, type[i]);
            strcpy(type[i], type[max]);
            strcpy(type[max], temp);
            // swapping date
            strcpy(temp, date[i]);
            strcpy(date[i], date[max]);
            strcpy(date[max], temp);
        }
        // printing top 5 results
        for(j = 0; j < n; j++)
        {
            printf("%s\t\t %s\t %s\t %s\n", username[j], type[j], results[j], date[j]);
        }

        fclose(fp);
        goto menu;
    }
    else if(choice == 5)
    {
        return 0;
    }
    return 0;
}
