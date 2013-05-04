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

    static bool doInsertStudent(const Student&);
    static bool doInsertCourse(const Course&);
    static bool doInsertRegistration(const Student&, const Course&);

    static bool doDeleteStudent(const Student&);
    static bool doDeleteCourse(const Course&);
    static bool doDeleteRegistration(const Student&, const Course&);

    static bool doQueryStudent(const Student&);
    static bool doQueryCourse(const Course&);
    static bool doQueryRegistration(const Student&, const Course&);

    static bool doModifyStudent(const Student&);
    static bool doModifyCourse(const Course&);
    static bool doModifyRegistration(const Student&, const Course&);

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
