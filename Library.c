#include <stdio.h>
#include <string.h>
#include <time.h>

struct Book
{
    char nameOfBook[50];
    int numberOfCopies;
    char description[300];
    int bookTaken;
};

void setTimeOut(int n)
{
    time_t start_time, current_time;
    time(&start_time);
    while (time(&current_time))
    {
        if (difftime(current_time, start_time) == n)
        {
            break;
        }
    }
}

int main()
{
    int fine = 0;
    struct Book Library[5];
    char bookNames[7][50] = {
        "Concept of Physics Part-1",
        "2. Concept of Physics Part-2",
        "3. Gulliver's Travels",
        "4. Oliver Twist",
        "5. Encyclopedias",
        "6. Harry Potter series",
        "7. THE SECRET"};
    char bookDescription[7][300] = {
        "H C Verma s Concepts Of Physics is an all-inclusive book, which serves to detail out the ABC of physics",
        "H C Verma s Concepts Of Physics is an all-inclusive book, which serves to detail out the ABC of physics",
        "The travel begins with a short preamble in which Lemuel Gulliver gives a brief outline of his life and history before his voyages",
        "Oliver Twist is born into a life of poverty and misfortune, raised in a workhouse in the fictional town of Mudfog. follwed by a series of events in his life",
        "book or set of books giving information on many subjects or on many aspects of one subject and typically arranged alphabetically.",
        "Harry Potter is a series of seven fantasy novels written by British author J. K. Rowling. The novels chronicle the lives of a young wizard, Harry Potter, and his friends Hermione Granger and Ron Weasley, all of whom are students at Hogwarts School of Witchcraft and Wizardry.",
        "The Secret is a 2006 self-help book by Rhonda Byrne, based on the earlier film of the same name. It is based on the belief of the law of attraction, which claims that thoughts can change a person's life directly"};
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
        setTimeOut(0.5);
        printf("\nWelcome to the library\n\n");
        setTimeOut(1.5);
        printf("Books Present in the Library: \n");
        for (int i = 0; i < 5; i++)
        {
            printf("%d. %s\n", i + 1, Library[i].nameOfBook);
            printf("Description: %s\n", Library[i].description);
            setTimeOut(1.5);
        }
        setTimeOut(1.5);
        printf("\nWhat do you want to do?\n");
        setTimeOut(1.5);
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
            scanf("%d", &bookNumber);
            bookNumber--;
            if (Library[bookNumber].bookTaken > 0)
            {
                printf("How many days ago the book was issued?\n-");
                scanf("%d", &numberOfDays);
                if (numberOfDays > 7)
                {
                    int tempFine = (numberOfDays - 7) * 10;
                    printf("You have a fine Rs. %d (Regarding this book), which is added to the total fine of %d", tempFine, fine);
                    fine += tempFine;
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
            printf("\nYou have a total fine of Rs.%d\n\n", fine);
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
