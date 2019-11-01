#include <iostream>
#include <stdio.h>
#include "Student.h"
#include "Student.cpp"     //Including student structure and function prototypes
using namespace std;

int main() {
    Student stu;     //Creating student object to access non static functions
    string ChosenNumber;


    stu.start_stream();   //A function that creates a file and establishing the connection


    cout<<"                      .   *        .       .\n"
          "          .                .  *       - )-\n"
          "       .      *       o       .       *\n"
          " o                |\n"
          "           .     -O-\n"
          ".                 |        *      .     -0-\n"
          "                .           o\n"
          "        .---.      Welcome to Student Database Program\n"
          "  =   _/__~0_\\_     .  *     Hold on to your spaceship!\n"
          " = = (_________)             .\n"
          "                 .                        *\n"
          "       *               - ) -       *"
          "\n1. Enter a new student record."
          "\n2. List all records."
          "\n3. Modify a student."
          "\n4. Search by student ID, surname or taken courses"
          "\nTo enter an operation, type the ID of it."
          "\nMy number is: ";
    fflush(stdin);    //Flushes the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)

    while (true) {
        getline(cin, ChosenNumber);
        try {
            int parsed = stoi(ChosenNumber);
            if (parsed < 5) {
                break;
            }
        } catch (std::invalid_argument) {
            cout << "Wrong type of input has entered." << endl;
        }
        cout << "\nCan you just try again? But carefully?" << endl << "Enter the number again: ";
    }
    int choice = stoi(ChosenNumber);
    switch (choice) {
        case 1: {
            Student::add_record();
            break;
        }

        case 2: {
            Student::list_records();
            break;
        }
        case 3: {
            Student::search_record();
            break;
        }
        case 4: {
            Student::modify_record();
            break;
        }

    }
    return 0;
}
