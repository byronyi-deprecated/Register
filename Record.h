#ifndef RECORD_H
#define RECORD_H

#define MIN_StuID_LENGTH 8
#define MAX_StuID_LENGTH 8
#define MAX_StuName_LENGTH 32
#define MIN_StuYear 1
#define MAX_StuYear 3
#define MIN_CourseCode_LENGTH 7
#define MAX_CourseName_LENGTH 32
#define MAX_CourseCode_LENGTH 8
#define CourseCodePrefix_LENGTH 4
#define MIN_CREDIT 0
#define MAX_CREDIT 5
#define NA_EXAM_MARK 999
#define MIN_EXAM_MARK 0
#define MAX_EXAM_MARK 100

#include <string>
#include <list>
using namespace std;

class Record
{
public:
    virtual unsigned int getKey() const = 0;
};

class Student : public Record
{
public:
    Student(string id, string n, unsigned int y, char g) :
        ID(id), name(n), year(y), gender(g) {}

    void addCourse(Course* course) {courses.push_back(course);}

    unsigned int getKey() const {
        unsigned int sum = 0;
        for(unsigned int i = 0; i != ID.length(); ++i)
        {
            sum += (ID.c_str())[i];
        }
        return sum;
    }

    string getID() const {return ID;}
    string getName() const {return name;}
    unsigned int getYear() const {return year;}
    char getGender() const {return gender;}

    bool operator==(Student s) {return !ID.compare(s.ID);}
    bool operator!=(Student s) {return !((*this) == s);}
    bool operator<(Student s) {return ID.compare(s.ID) < 0;}

private:
    string ID;
    string name;
    unsigned int year;
    char gender;

    list<Course*> courses;
};

class Course : public Record
{
public:
    Course(string c, string n, unsigned int cd) :
        code(c), name(n), credit(cd) {}

    void addStudent(Student* student) {students.push_back(student);}

    unsigned int getKey() const {
        unsigned int sum = 0;
        for(unsigned int i = 0; i != code.length(); ++i)
        {
            sum += (code.c_str())[i];
        }
        return sum;
    }
    string getCode() const {return code;}
    string getName() const {return name;}
    unsigned int getCredit() const {return credit;}

    bool operator==(Course c) {return !code.compare(c.code);}
    bool operator!=(Course c) {return !((*this) == c);}
    bool operator<(Course c) {return code.compare(c.code) < 0;}

private:
    string code;
    string name;
    unsigned int credit;

    list<Student*> students;
};

class Registration
{
public:
    Registration(Student* s, Course* c, unsigned int m) :
        student(s), course(c), mark(m) {}

    string getID() const {return student->getID();}
    string getCode() const {return course->getCode();}
    unsigned int getMark() const {return mark;}

    bool operator==(Registration r) {return *student == *(r.student) && *course == *(r.course);}
    bool operator!=(Registration r) {return !((*this) == r);}
    bool operator<(Registration r) {
        if(*student < *(r.student)) return true;
        else if(*student == *(r.student) && *course < *(r.course)) return true;
        else return false;
    }

private:
    Student* student;
    Course* course;
    unsigned int mark;
};

#endif // RECORD_H
