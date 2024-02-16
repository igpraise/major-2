#include <stdio.h>

int getNum(void);

void menuDisplay(void);

int powerCalculation(int base, int exponent);

int numberRangeChecker(int valueToCheck, int minNum, int maxNum);

int main(void)
{
    int choice = 0;
    int base = 1;
    int exponent = 1;

    while (choice != 4)
    {
        menuDisplay();
        choice = getNum();

        if (choice == 1)
        {

            printf(" Enter a base number between 1 and 30:");
            int userInputNumber = getNum();
            int range = numberRangeChecker(userInputNumber, 1, 30);

            if (range)
            {
                base = userInputNumber;
            }
            else
            {
                printf("Your entered base number is out of range");
            }


        }
        else if (choice == 2)
        {
            printf("Enter an exponent number between 1 and 6: ");
            int userInputNumber = getNum();
            int range = numberRangeChecker(userInputNumber, 1, 6);

            if (range)
            {
                exponent = userInputNumber;
            }
            else
            {
                printf("Your entered exponent number is out of range");
            }

        }
        else if (choice == 3)
        {
            printf("\n%d raised to the power of %d is %d\n", base, exponent, powerCalculation(base, exponent));
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("\nInvalid entry.\n");
        }
    }

    return 0;
}

// function to show user menu
void menuDisplay()
{
    printf("\n");
    printf("\n");
    printf("Menu:\n");
    printf("1. Change base \n");
    printf("2. Change exponent \n");
    printf("3. Display base raised to exponent \n");
    printf("4. Exit program \n");
    printf("Option? \n");
}

int powerCalculation(int base, int exponent)
{
    int power = 1;
    for (int i = 0; i < exponent; i++)
    {
        power *= exponent;
    }
    return power;
}

int numberRangeChecker(int value, int minimumNumber, int maximumNumber)
{

    if (value > maximumNumber || value < minimumNumber)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Function to get user input
#pragma warning(disable : 4996);
int getNum(void)
{
    /* we will see in a later lecture how we can improve this code */
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;
    /* NOTE to student: indent and brace this function consistent with

    your others */
    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to -1 */
        number = -1;
    }
    return number;
}

