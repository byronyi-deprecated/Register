#ifndef DATABASE_H
#define DATABASE_H

#include "Record.h"
#include "HashTable.h"
#include "DoublyLinkedList.h"
#include <string>

class Database
{
public:

    Database();
    ~Database();

    bool doInsertStudent(const Student&);
    bool doInsertCourse(const Course&);
    bool doInsertRegistration(const Registration&);

    bool doDeleteStudent(const string& stuID);
    bool doDeleteCourse(const string& code);
    bool doDeleteRegistration(const string& stuID, const string& code);

    Student doQueryStudent(const string& stuID) const;
    Course doQueryCourse(const string& code) const;
    Registration doQueryRegistration(const string& stuID, const string& code) const;

    bool doModifyStudent(const string& stuID, const string& name,
                         const unsigned int& year, const char& gender);
    bool doModifyCourse(const string& courseCode, const string& name,
                        const unsigned int& credit);
    bool doModifyRegistration(const string& stuID, const string& code,
                              const unsigned int& mark);

    bool WriteToBinary(string);
    bool ReadFromBinary(string);

    bool Write2HTML_Student();
    bool Write2HTML_Course();
    bool Write2HTML_StudentByCourse(Course);
    bool Write2HTML_CourseByStudent(Student);

private:
    HashTable<Student> studentRecord;
    HashTable<Course> courseRecord;
    HashTable<StudentIdx> studentIndex;
    HashTable<CourseIdx> courseIndex;
    DoublyLinkedList<Registration> regRecord;
};

#endif // DATABASE_H
