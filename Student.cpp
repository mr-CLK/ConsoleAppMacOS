#define _CRT_SECURE_NO_DEPRECATE						//A Preprocessor that eliminate warnings
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include "Student.h"
FILE* fp, * ft;											//File definition

struct Student e;
char xlast_name[50], xcourse[100], xid[20], another;
long int recsize = sizeof(e);
int switch_on;

void clearTheConsole(){    //pathetic, but works
    cout<< "Clearing the console"
           "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int Student::start_stream() {
    fp = fopen("users.txt", "rb+");						// Opens a file as a binary file for update(both for input and output).		r = read/update		b = binary		"+" means mixed mod

    if (fp == NULL)
    {
        fp = fopen("users.txt", "wb+");					// Creates an empty file as a binary file and open it for update (both for input and output)		w = write/update

        if (fp == NULL)
        {
            puts("File cannot be opened");
            return 0;
        }
    }
}

void Student::add_record() {
    fseek(fp, 0, SEEK_END); 								// Sets the position indicator associated with the stream to a new position
    another = 'Y';
    while (another == 'Y' || another == 'y')
    {
        cout << "\nEnter the first name: ";
        cin >> e.first_name;
        cout << "\nEnter the last name: ";
        cin >> e.last_name;
        cout << "\nEnter the ID: ";
        cin >> e.id;
        cout << "\nEnter the Course: ";
        cin >> e.course;
        cout << "\nEnter the Section: ";
        cin >> e.section;
        fwrite(&e, recsize, 1, fp);						// Write block of data to stream
        cout << "\n\nAdd Another Record (Y/N): ";
        fflush(stdin);									// Flushes the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)
        another = getchar();
    }
}

void Student::list_records() {
    clearTheConsole();
    rewind(fp);											// Sets the position indicator associated with stream to the beginning of the file
    cout << setw(65) <<"..:: All STUDENT RECORDS ::..";
    cout<<"\n--------------------------------------------------------------------------------------------------------------";
    cout << "\n";
    cout << "First Name" << setw(25) << "Last Name" << setw(25) << "Id" << setw(25) << "Courses" << setw(25) << "Section";
    while (fread(&e, recsize, 1, fp) == 1)				// A loop that reads records until element count reaches to size in file fp
    {
        cout << "\n";
        cout << "\n" << e.first_name;
        cout << setw(27) << e.last_name;
        cout << setw(36) << e.id;
        cout << setw(18) << e.course;
        cout << setw(19) <<e.section;
    }
    cout << "\n\n";

}

void Student::search_record() {
    clearTheConsole();
    cout << "You can search with: "
            "\n1- ID of the student."
            "\n2- Last name of the student."
            "\n3- Courses that the student takes."
            "\nTo search, enter the number of an operation: ";
    cin >> switch_on;

    rewind(fp);											// Sets the position indicator associated with stream to the beginning of the file
    while (fread(&e, recsize, 1, fp) == 1)				// A loop that reads records until element count reaches to size in file fp
    {
        switch (switch_on)								// Another switch statement for option handling
        {
            case 1:
                cout << "\n Enter the ID of the student: ";
                cin >> xid;

                if (strcmp(e.id, xid) == 0){				// It is nothing but comparing two strings
                    cout << "\n" << e.first_name
                    << setw(27) << e.last_name
                    << setw(36) << e.id
                    << setw(18) << e.course
                    << setw(19) << e.section
                    << endl;

                    fseek(fp, -recsize, SEEK_CUR);			// Sets the position indicator associated with the stream to a new position
                    fwrite(&e, recsize, 1, fp);				// Write block of data to stream
                    // Removed due to Unix problems. system("pause");			// Just stop the process and await user interaction
                }
                else cout << "No record has been found.";
                break;

            case 2:
                cout << "\n Enter the last name of the student: ";
                cin >> xlast_name;

                if (strcmp(e.last_name, xlast_name) == 0){
                    cout << "\n" << "First Name"
                         << setw(27) << "Last Name"
                         << setw(36) << "ID"
                         << setw(18) << "Course"
                         << setw(19) << "Section"
                         << endl;
                    cout << "\n" << e.first_name
                         << setw(27) << e.last_name
                         << setw(36) << e.id
                         << setw(18) << e.course
                         << setw(19) << e.section
                         << endl;

                    fseek(fp, -recsize, SEEK_CUR);
                    fwrite(&e, recsize, 1, fp);
                    //Removed due to Unix problems. system("pause");
                }
                else cout << "No record has been found.";
                break;

            case  3:
                cout << "\n Enter the course taken by the student: ";
                cin >> xcourse;

                while (strcmp(e.course, xcourse) == 0){
                    cout << "\n" << e.first_name
                         << setw(27) << e.last_name
                         << setw(36) << e.id
                         << setw(18)<< e.course
                         << setw(19)<< e.section
                         << endl;

                    fseek(fp, -recsize, SEEK_CUR);
                    fwrite(&e, recsize, 1, fp);
                    // Removed due to Unix problems. system("pause");
                }
                break;

            default: break;
        }
    }
    fflush(stdin);										// Flushes the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)
    cout << "\n\n";
    // Removed due to Unix problems. system("pause");									// Just stop the process and await user interaction
}

void Student::modify_record() {
    another = 'Y';
    while (another == 'Y' || another == 'y')
    {
        cout << "\n Enter the last name of the student : ";
        cin >> xlast_name;

        rewind(fp);										// Sets the position indicator associated with stream to the beginning of the file
        while (fread(&e, recsize, 1, fp) == 1)			// A loop that reads records until element count reaches to size in file fp
        {
            if (strcmp(e.last_name, xlast_name) == 0)
            {
                cout << "\nEnter new first name:";
                cin >> e.first_name;
                cout << "\nEnter new last name: ";
                cin >> e.last_name;
                cout << "\nEnter the ID: ";
                cin >> e.id;
                cout << "\nEnter new the Course: ";
                cin >> e.course;
                cout << "\nEnter new the Section: ";
                cin >> e.section;
                fseek(fp, -recsize, SEEK_CUR);
                fwrite(&e, recsize, 1, fp);
                break;
            }
            else cout << "No record has been found.";
        }
        cout << "\n Modify Another Record (Y/N) ";
        fflush(stdin);									// Flushes the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)
        another = getchar();
    }
}

void Student::delete_record() {
    another = 'Y';
    while (another == 'Y' || another == 'y')
    {
        cout << "\n Enter the last name of the student to delete: ";
        cin >> xlast_name;

        ft = fopen("temp.dat", "wb");					// Temporarily passing data to prevent unwanted packet loss and removing the record from file

        rewind(fp);										// Sets the position indicator associated with stream to the beginning of the file

        while (fread(&e, recsize, 1, fp) == 1)			// A loop that reads records until element count reaches to size in file users.txt to find matching last name on record that we want to remove
            if (strcmp(e.last_name, xlast_name) != 0){fwrite(&e, recsize, 1, ft);}				// Write block of data form users/txt to temp.dat file stream

            fclose(fp);										// Closing the user.txt connection
            fclose(ft);										// Closing the temp.dat connection
        remove("users.txt");
        rename("temp.dat", "users.txt");

        fp = fopen("users.txt", "rb+");					// Establishing the connection again with users.txt

        cout << "\nDelete another record? (Y/N)"<<endl;
        fflush(stdin);									// Flushes the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream)
        another = getchar();
    }
}

void Student::close_stream() {
    fclose(fp);
    exit(0);
}
