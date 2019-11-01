#ifndef Student_H
#define Student_H


using namespace std;

struct Student
{
    char first_name[50], last_name[50], course[100], id[20];
    int section;

    int start_stream();
    static void add_record();
    static void list_records();
    static void search_record();
    static void modify_record();
    static void delete_record();
    void close_stream();
};
#endif // !Student_H

