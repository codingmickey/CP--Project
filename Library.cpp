#include <iostream>
using namespace std;

struct Book
{
    string nameOfBook;
    int numberOfCopies = 2;
    string description;
    int bookTaken = 0;
};

int main()
{
    int fine = 0;
    struct Book Library[5];
    string bookNames[5] = {"A TIME TO KILL", "EAST OF EDEN", "VILE BODIES", "MOAB IS MY WASHPOT", "NOLI ME TANGERE"};
    string bookDescription[5] = {
        "This one is from 3:3 in the Ecclesiastes, again part of the Old Testament.",
        "Steinbeck apparently considered this 1952 novel to be his magnum opu",
        "Waugh took the title for his 1930 novel from Philippians, full name",
        "Undoubtedly an odd quotation; it comes from line 60:8 of the Book",
        "Rizal, one of the national heroes of the Philippines, wrote this"};
    int taskNumber, bookTaken = 0;
    char onceAgain;

    for (int i = 0; i < 5; i++)
    {
        Library[i].nameOfBook = bookNames[i];
        Library[i].description = bookDescription[i];
    }
    do
    {
        cout << "\nWelcome to the library\n\n";
        cout << "Books Present in the Library: \n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << Library[i].nameOfBook << "\n";
            cout << "Description: " << Library[i].description << "\n";
        }
        cout << "\nWhat do you want to do?\n";
        cout << "1. Issue a book\n2. Return a book\n3. Show fine\nEnter the number(1/2/3): ";
        cin >> taskNumber;
        if (taskNumber == 1)
        {
            int temp;
            cout << "\nWhich book do you want to issue?\n";
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ". " << Library[i].nameOfBook << "\n";
                cout << "Count: " << Library[i].numberOfCopies << "\n";
            }
            cout << "\nEnter the book number: ";
            cin >> temp;
            temp--;
            if (Library[temp].numberOfCopies == 0)
            {
                cout << "Cannot issue this book as there are no copies avaliable!\n\n";
            }
            else
            {
                (Library[temp].numberOfCopies)--;
                cout << "\nCopy Issued!\nNow only " << Library[temp].numberOfCopies << " number of copies avaliable of that book.\n\n";
                Library[temp].bookTaken++;
                bookTaken++;
            }
        }
        else if (taskNumber == 2 && bookTaken > 0)
        {
            int bookNumber, numberOfDays;
            cout << "\nWhich book do you want to return?\n";
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ". " << Library[i].nameOfBook << "\n";
            }
            cout << "\nEnter the book number: ";
            cin >> bookNumber;
            bookNumber--;
            if (Library[bookNumber].bookTaken > 0)
            {
                cout << "How many days ago the book was issued?\n-";
                cin >> numberOfDays;
                if (numberOfDays > 7)
                {
                    fine += (numberOfDays - 7) * 10;
                }
                (Library[bookNumber].numberOfCopies)++;
                cout << "\nBook Returned!\nNow " << Library[bookNumber].numberOfCopies << " copies avaliable of that book.\n\n";
                bookTaken--;
                Library[bookNumber].bookTaken--;
            }
            else
            {
                cout << "\nFirst Issue that book then return lol.\n\n";
            }
        }
        else if (taskNumber == 2 && !bookTaken)
        {
            cout << "\nFirst Issue a book!\n\n";
        }
        else if (taskNumber == 3)
        {
            cout << "\nYou have a fine of Rs." << fine << "\n\n";
        }
        else
        {
            cout << "Enter a valid option!!\n";
        }
        cout << "Do you want to continue?(Y/N)\n-";
        cin >> onceAgain;

    } while (onceAgain == 'y' || onceAgain == 'Y');

    return 0;
}