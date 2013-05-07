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

    //============================================
    // All query and delete method will throw
    // an exception while given key doesn't exist
    // however, insert and modify method will not
    // throw any exception.
    //
    // So, make sure all the exceptions from
    // query and delete methods are properly
    // handled in your own codes.
    //============================================

    static bool doInsertStudent(const Student&);
    static bool doInsertCourse(const Course&);
    static bool doInsertRegistration(const Registration&);

    static bool doDeleteStudent(const string& stuID);
    static bool doDeleteCourse(const string& code);
    static bool doDeleteRegistration(const string& stuID, const string& code);

    static Student doQueryStudent(const string& stuID);
    static Course doQueryCourse(const string& code);
    static Registration doQueryRegistration(const string& stuID, const string& code);

    static bool doModifyStudent(const string& stuID, const string& name,
                                const unsigned int& year, const char& gender);
    static bool doModifyCourse(const string& courseCode, const string& name,
                               const unsigned int& credit);
    static bool doModifyRegistration(const string& stuID, const string& name,
                                     const unsigned int& mark);

    static bool WriteToBinary(string);
    static bool ReadFromBinary(string);

    static bool Write2HTML_Student();
    static bool Write2HTML_Course();
    static bool Write2HTML_StudentByCourse(Course*);
    static bool Write2HTML_CourseByStudent(Student*);

private:
    static HashTable<Student> studentRecord;
    static HashTable<Course> courseRecord;
    static HashTable<StudentIdx> studentIndex;
    static HashTable<CourseIdx> courseIndex;
    static DoublyLinkedList<Registration> regRecord;
};

#endif // DATABASE_H
