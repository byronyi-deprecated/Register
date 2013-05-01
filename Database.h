#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"
class Database
{
public:
    Database();

    bool doInsertStudent(Student&);
    bool doInsertCourse(Course&);
    bool doInsertRecord(RegRecord&);

    bool doDeleteStudent(Student*);
    bool doDeleteCourse(Course*);
    bool doDeleteRecord(RegRecord*);

    Student* doQueryStudent(string);
    Course* doQueryCourse(string);
    RegRecord* doQueryRecord(Student*, Course*);

    bool doModifyStudent(Student*);
    bool doModifyCourse(Course*);
    bool doModifyRecord(RegRecord*);

    bool WriteToBinary(string);
    bool ReadFromBinary(ifstream);

    bool Write2HTML_Student();
    bool Write2HTML_Course();
    bool Write2HTML_StudentByCourse(Course&);
    bool Write2HTML_CourseByStudent(Student&);
};

#endif // DATABASE_H
