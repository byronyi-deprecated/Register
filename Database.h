#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"
#include "HashTable.h"
#include "DoublyLinkedList.h"

//==================================================================
//Although only one db instance is instanitiated for every execution
//of the program now , all the db manipulation methods are still
//encapsuled into this class, just in case for possible extension
//of the program to manipulating several databases simutaneously
//in the future.
//
//If do so, remember to remove all the static declaration!
//==================================================================

class Database
{
public:

    static bool doInsertStudent(Student&);
    static bool doInsertCourse(Course&);
    static bool doInsertRegistration(Registration&);

    static bool doDeleteStudent(Student*);
    static bool doDeleteCourse(Course*);
    static bool doDeleteRegistration(Registration*);

    static Student* doQueryStudent(string);
    static Course* doQueryCourse(string);
    static Registration* doQueryRegistration(Student*, Course*);

    static bool doModifyStudent(Student*);
    static bool doModifyCourse(Course*);
    static bool doModifyRegistration(Registration*);

    static bool WriteToBinary(string);
    static bool ReadFromBinary(string);

    static bool Write2HTML_Student();
    static bool Write2HTML_Course();
    static bool Write2HTML_StudentByCourse(Course*);
    static bool Write2HTML_CourseByStudent(Student*);

private:
    static HashTable<Student> studentRecord;
    static HashTable<Course> courseRecord;
    static DoublyLinkedList<Registration> regRecord;
};

#endif // DATABASE_H
