#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function declarations
void showMainMenu();
void showHistory();
void learnCpp();
void readFile(string fileName);

int main()
{
    int choice;

    do
    {
        showMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            showHistory();
            break;

        case 2:
            learnCpp();
            break;

        case 3:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}

// Main menu
void showMainMenu()
{
    cout << "\n===== FOUNDATIONS AND HISTORY OF C++ =====" << endl;
    cout << "1. View History of C++" << endl;
    cout << "2. Learn About C++" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
}

// History section
void showHistory()
{
    int choice;

    cout << "\n===== HISTORY OF C++ =====" << endl;
    cout << "1. Origin of C++" << endl;
    cout << "2. Development of C++" << endl;
    cout << "3. Evolution of C++" << endl;
    cout << "Choose chapter: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nC++ was developed by Bjarne Stroustrup in 1979." << endl;
        break;

    case 2:
        cout << "\nC++ was created as an extension of the C language." << endl;
        break;

    case 3:
        cout << "\nC++ evolved with features like OOP, STL, and file handling." << endl;
        break;

    default:
        cout << "Invalid chapter!" << endl;
    }
}

// Learn C++ section
void learnCpp()
{
    int choice;

    cout << "\n===== LEARN C++ =====" << endl;
    cout << "1. Data Types" << endl;
    cout << "2. Control Flow" << endl;
    cout << "3. Loops" << endl;
    cout << "4. Arrays" << endl;
    cout << "5. File Streams" << endl;
    cout << "Choose topic: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nData types store different kinds of values." << endl;
        break;

    case 2:
        cout << "\nControl flow includes if, else, and switch statements." << endl;
        break;

    case 3:
        cout << "\nLoops repeat instructions. Examples: for, while, do-while." << endl;
        break;

    case 4:
        cout << "\nArrays store multiple values of the same type." << endl;
        break;

    case 5:
        readFile("filestream.txt");
        break;

    default:
        cout << "Invalid topic!" << endl;
    }
}

// File handling function
void readFile(string fileName)
{
    ifstream file(fileName);

    string line;

    if (file.is_open())
    {
        cout << "\n===== FILE STREAM CONTENT =====" << endl;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}