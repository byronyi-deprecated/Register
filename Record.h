#ifndef RECORD_H
#define RECORD_H

#define MIN_StuID_LENGTH 8
#define MAX_StuID_LENGTH 8
#define MAX_StuName_LENGTH 32
#define MIN_CourseCode_LENGTH 7
#define MAX_CourseName_LENGTH 32
#define MAX_CourseCode_LENGTH 8
#define CourseCodePrefix_LENGTH 4
#define MIN_EXAM_MARK 0
#define MAX_EXAM_MARK 100

#include <string>
using namespace std;

enum Year {first_year, second_year, third_year};
enum Gender {male, female};
enum Credit {zero, one, two, three, four, five};

class Record
{
public:
    virtual unsigned int getKey() const = 0;
};

class Student : public Record
{
public:
    Student(string id, string n, Year y, Gender g) :
        ID(id), name(n), year(y), gender(g) {}

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
    Year getYear() const {return year;}
    Gender getGender() const {return gender;}

    bool operator==(Student s) {return !ID.compare(s.ID);}
    bool operator!=(Student s) {return !((*this) == s);}
    bool operator<(Student s) {return ID.compare(s.ID) < 0;}

private:
    string ID;
    string name;
    Year year;
    Gender gender;
};

class Course : public Record
{
public:
    Course(string c, string n, Credit cd) :
        code(c), name(n), credit(cd) {}

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
    Credit getCredit() const {return credit;}

    bool operator==(Course c) {return !code.compare(c.code);}
    bool operator!=(Course c) {return !((*this) == c);}
    bool operator<(Course c) {return code.compare(c.code) < 0;}

private:
    string code;
    string name;
    Credit credit;
};

class RegRecord
{
public:
    RegRecord(Student* s, Course* c, unsigned int m) :
        student(s), course(c), mark(m) {}

    string getID() const {return student->getID();}
    string getCode() const {return course->getCode();}
    unsigned int getMark() const {return mark;}

    bool operator==(RegRecord r) {return *student == *(r.student) && *course == *(r.course);}
    bool operator!=(RegRecord r) {return !((*this) == r);}
    bool operator<(RegRecord r) {
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
