#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#define EPSILON 0.01

double getRandomeNumber(int min, int max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}
int main()
{
    int score = 0;
    int level = 0;
    double x, y, result;

    srand(time(NULL));

    while (level <= 5)
    {
        system("cls");
        printf("\nYour Level: %d", level);
        printf("\nYour Score is: %d", score);
        printf("\n---------------------------\n");

        if (level == 0)
        {
            x = getRandomeNumber(1, 100);
            y = getRandomeNumber(1, 100);
            printf("(%.2lf) + (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x + y)) < EPSILON)
            {
                Beep(1500, 1000);
                printf("\nCorrect.\n\n");
                score++;
                if (score == 2)
                {
                    level++;
                }
            }
            else
            {
                Beep(300, 2000);
                printf("\nWrong, Correct Answer is: (%.2lf)", x + y);
                printf("\nLet's Try Next...");
            }
        }

        else if (level == 1)
        {
            x = getRandomeNumber(-100, 100);
            y = getRandomeNumber(-100, 100);
            printf("(%.2lf) + (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x + y)) < EPSILON)
            {
                printf("\nCorrect.\n\n");
                score++;
                if (score == 4)
                {
                    level++;
                }
            }
            else
            {
                printf("\nWrong, Correct Answer is: (%.2lf)", x + y);
                printf("\nLet's Try Next...");
            }
        }
        else if (level == 2)
        {
            x = getRandomeNumber(-100, 100);
            y = getRandomeNumber(-100, 100);
            printf("(%.2lf) - (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x - y)) < EPSILON)
            {
                printf("\nCorrect.\n\n");
                score++;
                if (score == 6)
                {
                    level++;
                }
            }
            else
            {
                printf("\nWrong, Correct Answer is: (%.2lf)", x - y);
                printf("\nLet's Try Next...");
            }
        }
        else if (level == 3)
        {
            x = getRandomeNumber(-100, 100);
            y = getRandomeNumber(-100, 100);
            printf("(%.2lf) - (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x - y)) < EPSILON)
            {
                printf("\nCorrect.\n\n");
                score++;
                if (score == 8)
                {
                    level++;
                }
            }
            else
            {
                printf("\nWrong, Correct Answer is: (%.2lf)", x - y);
                printf("\nLet's Try Next...");
            }
        }
        else if (level == 4)
        {
            x = getRandomeNumber(-100, 100);
            y = getRandomeNumber(-100, 100);
            printf("(%.2lf) * (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x * y)) < EPSILON)
            {
                printf("\nCorrect.\n\n");
                score++;
                if (score == 10)
                {
                    level++;
                }
            }
            else
            {
                printf("\nWrong, Correct Answer is: (%.2lf)", x * y);
                printf("\nLet's Try Next...");
            }
        }
        else if (level == 5)
        {
            x = getRandomeNumber(-100, 100);
            y = getRandomeNumber(-100, 100);
            printf("(%.2lf) * (%.2lf) = ?", x, y);
            printf("\nEnter your Anwer: ");
            scanf("%lf", &result);
            if (fabs(result - (x * y)) < EPSILON)
            {
                printf("\nCorrect.\n\n");
                score++;
                if (score == 10)
                {
                    level++;
                }
            }
            else
            {
                printf("\nWrong, Correct Answer is: (%.2lf)", x * y);
                printf("\nLet's Try Next...");
            }
        }
        getch();
    }

    return 0;
}