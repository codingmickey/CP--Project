#include <stdio.h>
#include <string.h>
struct Book
{
    char nameOfBook[50];
    int numberOfCopies;
    char description[200];
    int bookTaken;
};

int main()
{
    int fine = 0;
    struct Book Library[5];
    char bookNames[5][50] = {"A TIME TO KILL", "EAST OF EDEN", "VILE BODIES", "MOAB IS MY WASHPOT", "NOLI ME TANGERE"};
    char bookDescription[5][200] = {
        "This one is from 3:3 in the Ecclesiastes, again part of the Old Testament.",
        "Steinbeck apparently considered this 1952 novel to be his magnum opu",
        "Waugh took the title for his 1930 novel from Philippians, full name",
        "Undoubtedly an odd quotation; it comes from line 60:8 of the Book",
        "Rizal, one of the national heroes of the Philippines, wrote this"};
    int taskNumber, bookTaken = 0;
    char onceAgain;
    char dummy;

    for (int i = 0; i < 5; i++)
    {
        Library[i].numberOfCopies = 2;
        Library[i].bookTaken = 0;
        strcpy(Library[i].nameOfBook, bookNames[i]);
        strcpy(Library[i].description, bookDescription[i]);
    }
    do
    {
        printf("\nWelcome to the library\n\n");
        printf("Books Present in the Library: \n");
        for (int i = 0; i < 5; i++)
        {
            printf("%d. %s\n", i + 1, Library[i].nameOfBook);
            printf("Description: %s\n", Library[i].description);
        }
        printf("\nWhat do you want to do?\n");
        printf("1. Issue a book\n2. Return a book\n3. Show fine\nEnter the number(1/2/3): ");
        scanf("%d", &taskNumber);
        if (taskNumber == 1)
        {
            int temp;
            printf("\nWhich book do you want to issue?\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d. %s\n", i + 1, Library[i].nameOfBook);
                printf("Count: %d\n", Library[i].numberOfCopies);
            }
            printf("\nEnter the book number: ");
            scanf("%d", &temp);
            temp--;
            if (Library[temp].numberOfCopies == 0)
            {
                printf("Cannot issue this book as there are no copies avaliable!\n\n");
            }
            else
            {
                (Library[temp].numberOfCopies)--;
                printf("\nCopy Issued!\nNow only %d number of copies avaliable of that book.\n\n", Library[temp].numberOfCopies);
                Library[temp].bookTaken++;
                bookTaken++;
            }
        }
        else if (taskNumber == 2 && bookTaken > 0)
        {
            int bookNumber, numberOfDays;
            printf("\nWhich book do you want to return?\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d. %s\n", i + 1, Library[i].nameOfBook);
            }
            printf("\nEnter the book number: ");
            scanf("%d", bookNumber);
            bookNumber--;
            if (Library[bookNumber].bookTaken > 0)
            {
                printf("How many days ago the book was issued?\n-");
                scanf("%d", numberOfDays);
                if (numberOfDays > 7)
                {
                    fine += (numberOfDays - 7) * 10;
                }
                (Library[bookNumber].numberOfCopies)++;
                printf("\nBook Returned!\nNow %d copies avaliable of that book.\n\n", Library[bookNumber].numberOfCopies);
                bookTaken--;
                Library[bookNumber].bookTaken--;
            }
            else
            {
                printf("\nFirst Issue that book then return lol.\n\n");
            }
        }
        else if (taskNumber == 2 && !bookTaken)
        {
            printf("\nFirst Issue a book!\n\n");
        }
        else if (taskNumber == 3)
        {
            printf("\nYou have a fine of Rs.%d\n\n", fine);
        }
        else
        {
            printf("Enter a valid option!!\n");
        }
        printf("Do you want to continue?(Y/N)\n-");
        scanf("%c", &dummy);
        scanf("%c", &onceAgain);

    } while (onceAgain == 'y' || onceAgain == 'Y');

    return 0;
}