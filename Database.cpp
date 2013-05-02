#include "Database.h"

bool Database::doInsertStudent(Student& student)
{
    return studentRecord.insert(student);
}

bool Database::doInsertCourse(Course& course)
{
    return courseRecord.insert(course);
}

bool Database::doInsertRegistration(Registration& registration)
{
    return regRecord.insert(registration);
}


bool Database::doDeleteStudent(Student*)
{

}

bool Database::doDeleteCourse(Course*)
{

}

bool Database::doDeleteRegistration(Registration*)
{

}


Student* Database::doQueryStudent(string)
{

}

Course* Database::doQueryCourse(string)
{

}

Registration* Database::doQueryRegistration(Student*, Course*)
{

}


bool Database::doModifyStudent(Student*)
{

}

bool Database::doModifyCourse(Course*)
{

}

bool Database::doModifyRegistration(Registration*)
{

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

bool Database::Write2HTML_StudentByCourse(Course*)
{

}

bool Database::Write2HTML_CourseByStudent(Student*)
{

}
