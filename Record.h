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

size_t hash(string key) const
{
    unsigned int sum = 0;
    for(unsigned int i = 0; i != key.length(); ++i)
    {
        sum += (key.c_str())[i];
    }
    return sum;
}

class Record
{
public:
    virtual size_t getKey() const = 0;
};

class Student : public Record
{
public:
    Student(string id, string n = string(), unsigned int y = 0, char g = 0) :
        ID(id), name(n), year(y), gender(g) {}

    size_t getKey() const {return hash(ID);}

    string getID() const {return ID;}
    string getName() const {return name;}
    unsigned int getYear() const {return year;}
    char getGender() const {return gender;}

    void setName(string n) {name = n;}
    void setYear(unsigned int y) {year = y;}
    void setGender(char g) {gender = g;}

    bool operator==(Student s) {return ID.compare(s.ID) == 0;}
    bool operator==(string student_id) {return ID.compare(student_id) == 0;}
    bool operator!=(Student s) {return !((*this) == s);}
    bool operator!=(string student_id) {return !((*this) == student_id);}
    bool operator<(Student s) {return ID.compare(s.ID) == -1;}

private:
    string ID;
    string name;
    unsigned int year;
    char gender;
};

class Course : public Record
{
public:
    Course(string c, string n = string(), unsigned int cd = 0) :
        code(c), name(n), credit(cd) {}

    size_t getKey() const {return hash(code);}
    string getCode() const {return code;}
    string getName() const {return name;}
    unsigned int getCredit() const {return credit;}

    void setCode(string c) {code = c;}
    void setName(string n) {name = n;}
    void setCredit(unsigned int c) {credit = c;}

    bool operator==(Course c) {return code.compare(c.code) == 0;}
    bool operator==(string course_code) {return code.compare(course_code) == 0;}
    bool operator!=(Course c) {return !((*this) == c);}
    bool operator!=(string course_code) {return !((*this) == course_code);}
    bool operator<(Course c) {return code.compare(c.code) == -1;}

private:
    string code;
    string name;
    unsigned int credit;
};

class Registration
{
public:
    Registration(string id, string c, unsigned int m  = NA_EXAM_MARK) :
        ID(id), code(c), mark(m) {}

    string getID() const {return ID;}
    string getCode() const {return code;}
    unsigned int getMark() const {return mark;}

    void setMark(unsigned int m) {mark = m;}

    bool operator==(Registration r) {return ID.compare(r.ID) == 0 && code.compare(r.ID) == 0;}
    bool operator!=(Registration r) {return !((*this) == r);}
    bool operator<(Registration r) {
        if(ID.compare(r.ID) == -1) return true;
        else if(ID.compare(r.ID) == 0 && code.compare(r.ID) == -1) return true;
        else return false;
    }

private:
    string ID;
    string code;
    unsigned int mark;
};

struct StudentIdx
{
    StudentIdx(string id, Registration* r = 0) : ID(id), reg(r) {}
    string ID;
    struct RegistrationPtr {
        Registration* r;

        RegistrationPtr(Registration* _r) : r(_r) {}
        bool operator==(RegistrationPtr ptr) {return r == ptr.r;}
        unsigned int getKey() const {return key_id(r->getID());}
    } reg;

    size_t getKey() const {return hash(ID);}

    bool operator==(StudentIdx idx) {return *this == idx.ID && *this == idx.reg;}
    bool operator==(string student_id) {return ID.compare(student_id) == 0;}
    bool operator==(RegistrationPtr r) {return r == reg;}
    bool operator!=(StudentIdx idx) {return !((*this) == idx);}
    bool operator!=(string student_id) {return !((*this) == student_id);}
    bool operator!=(RegistrationPtr r) {return !((*this) == r);}

    bool operator<(StudentIdx idx) {return ID.compare(idx.ID) == -1;}
};

struct CourseIdx
{
    CourseIdx(string c, Registration* r = 0) : code(c), reg(r) {}
    string code;
    struct RegistrationPtr {
        Registration* r;

        RegistrationPtr(Registration* _r) : r(_r) {}
        bool operator==(RegistrationPtr ptr) {return r == ptr.r;}
        unsigned int getKey() const {return key_code(r->getCode());}
    } reg;

    size_t getKey() const {return hash(code);}

    bool operator==(CourseIdx idx) {return *this == idx.code && *this == idx.reg;}
    bool operator==(string course_code) {return code.compare(course_code) == 0;}
    bool operator==(RegistrationPtr r) {return r == reg;}
    bool operator!=(CourseIdx idx) {return !((*this) == idx);}
    bool operator!=(string course_code) {return !((*this) == course_code);}
    bool operator!=(RegistrationPtr r) {return !((*this) == r);}

    bool operator<(CourseIdx idx) {return code.compare(idx.code) == -1;}
};

#endif // RECORD_H
