#include "Database.h"
#include <iostream>
using namespace std;
Database::Database()
{
//    studentRecord = new HashTable<Student>(19);
//    courseRecord = new HashTable<Course>(19);
//    studentIndex = new HashTable<StudentIdx>(19);
//    courseIndex = new HashTable<CourseIdx>(19);
//    regRecord = new DoublyLinkedList<Registration>;
}

Database::~Database()
{
//    delete studentRecord;
//    delete courseRecord;
//    delete studentIndex;
//    delete courseIndex;
//    delete regRecord;
}

bool Database::doInsertStudent(const Student& student)
{
    cout << "haah";
    return studentRecord.insert(student);
}

bool Database::doInsertCourse(const Course& course)
{
    return courseRecord.insert(course);
}

bool Database::doInsertRegistration(const Registration& reg)
{
    if(!regRecord.insert(reg))
        return false;

    Registration* reg_ptr = regRecord.search(reg);

    StudentIdx* stu_idx_ptr = studentIndex.search(StudentIdx(reg.getID()));
    if(!stu_idx_ptr)
    {
        studentIndex.insert(StudentIdx(reg.getID()));
        stu_idx_ptr = studentIndex.search(StudentIdx(reg.getID()));
    }

    stu_idx_ptr->addReg(reg_ptr);

    CourseIdx* course_idx_ptr = courseIndex.search(CourseIdx(reg.getCode()));
    if(!course_idx_ptr)
    {
        courseIndex.insert(CourseIdx(reg.getCode()));
        course_idx_ptr = courseIndex.search(CourseIdx(reg.getCode()));
    }

    course_idx_ptr->addReg(reg_ptr);

    return true;
}


bool Database::doDeleteStudent(const string& stuID)
{
    bool ok = studentRecord.remove(Student(stuID));

    StudentIdx* idx_ptr = studentIndex.search(StudentIdx(stuID));

    if(!idx_ptr)
        return ok;

    for(list<Registration*>::iterator i = idx_ptr->reg.begin();
        i != idx_ptr->reg.end(); ++i) {

        regRecord.remove(**i);
        string courseCode = (*i)->getCode();

        CourseIdx* course_idx = courseIndex.search(CourseIdx(courseCode));
        course_idx->reg.remove(*i);

        if(course_idx->reg.empty())
            courseIndex.remove(*course_idx);

    }

    idx_ptr->reg.clear();
    studentIndex.remove(*idx_ptr);

    return true;
}

bool Database::doDeleteCourse(const string& code)
{
    bool ok = courseRecord.remove(Course(code));

    CourseIdx* idx_ptr = courseIndex.search(CourseIdx(code));

    if(!idx_ptr)
        return ok;

    for(list<Registration*>::iterator i = idx_ptr->reg.begin();
        i != idx_ptr->reg.end(); ++i) {

        regRecord.remove(**i);
        string stuID = (*i)->getID();

        StudentIdx* stu_idx = studentIndex.search(StudentIdx(stuID));
        stu_idx->reg.remove(*i);

        if(stu_idx->reg.empty())
            studentIndex.remove(*stu_idx);

    }

    idx_ptr->reg.clear();
    courseIndex.remove(*idx_ptr);

    return true;
}

bool Database::doDeleteRegistration(const string& stuID, const string& code)
{
    Registration* reg_ptr = regRecord.search(Registration(stuID, code));


    StudentIdx* stu_idx_ptr = studentIndex.search(StudentIdx(stuID));
    CourseIdx* course_idx_ptr = courseIndex.search(CourseIdx(code));

    stu_idx_ptr->reg.remove(reg_ptr);
    if(stu_idx_ptr->reg.empty())
        studentIndex.remove(*stu_idx_ptr);

    course_idx_ptr->reg.remove(reg_ptr);
    if(course_idx_ptr->reg.empty())
        courseIndex.remove(*course_idx_ptr);
}


Student Database::doQueryStudent(const string& stuID) const
{
    string studentError = "Student does not exist";

    Student* student = studentRecord.search(Student(stuID));

    if(!student) throw studentError;

    return *student;
}

Course Database::doQueryCourse(const string& code) const
{
    string courseError = "Course does not exist";

    Course* course = courseRecord.search(Course(code));

    if(!course) throw courseError;

    return *course;
}

Registration Database::doQueryRegistration(const string& stuID, const string& code) const
{
    string regError = "Registration does not exist";

    Registration* registration = regRecord.search(Registration(stuID, code));

    if(!registration) throw regError;
    return *registration;
}

bool Database::doModifyStudent(const string& stuID, const string& name,
                               const unsigned int& year, const char& gender)
{
    string studentError = "Student does not exist";

    Student* student = studentRecord.search(Student(stuID));

    if(!student) throw studentError;

    student->setName(name);
    student->setYear(year);
    student->setGender(gender);
}

bool Database::doModifyCourse(const string& courseCode, const string& name,
                              const unsigned int& credit)
{
    string courseError = "Course does not exist";

    Course* course = courseRecord.search(Course(courseCode));

    if(!course) throw courseError;

    course->setName(name);
    course->setCredit(credit);
}

bool Database::doModifyRegistration(const string& stuID, const string& code,
                                    const unsigned int& mark)
{
    string regError = "Registration does not exist";

    Registration* registration = regRecord.search(Registration(stuID, code));

    if(!registration) throw regError;

    registration->setMark(mark);
}

bool Database::WriteToBinary(string)
{

}

bool Database::ReadFromBinary(string)
{

}


bool Database::Write2HTML_Student()
{

}

bool Database::Write2HTML_Course()
{

}

bool Database::Write2HTML_StudentByCourse(Course)
{

}

bool Database::Write2HTML_CourseByStudent(Student)
{

}
