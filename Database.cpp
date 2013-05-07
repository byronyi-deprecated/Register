#include "Database.h"

bool Database::doInsertStudent(const Student& student)
{
    return studentRecord.insert(student);
}

bool Database::doInsertCourse(const Course& course)
{
    return courseRecord.insert(course);
}

bool Database::doInsertRegistration(const Registration& regRecord)
{
    Student* student_ptr = studentRecord.search(student);
    Course* course_ptr = courseRecord.search(course);

    Registration reg(student_ptr, course_ptr);

    bool ok = regRecord.insert(reg);

    Registration* reg_ptr = regRecord.search(reg);

    studentIndex.insert(StudentIdx(student_ptr, reg_ptr));
    courseIndex.insert(CourseIdx(course_ptr, reg_ptr));

    return ok;
}


bool Database::doDeleteStudent(const string& stuID)
{
    Student* student_ptr = studentRecord.search(student);

    if(!student_ptr) return false;

    StudentIdx idx(student_ptr);

    StudentIdx* idxPtr = studentIndex.search(idx);

    while(idxPtr)
    {
        regRecord.remove(*(idxPtr->reg));
        studentIndex.remove(idx);

        idxPtr = studentIndex.search(idx);
    }

    return true;
}

bool Database::doDeleteCourse(const string& code)
{
    Course* course_ptr = courseRecord.search(course);

    if(!course_ptr) return false;

    CourseIdx idx(course_ptr);

    CourseIdx* idxPtr = courseIndex.search(idx);

    while(idxPtr)
    {
        regRecord.remove(*(idxPtr->reg));
        courseIndex.remove(idx);

        idxPtr = courseIndex.search(idx);
    }

    return true;
}

bool Database::doDeleteRegistration(const string& stuID, const string& code)
{
    Registration* reg_ptr = regRecord.search()
}


Student Database::doQueryStudent(string stuID) const
{
    string studentError = "Student does not exist";

    Student* student = studentRecord.search(Student(stuID));

    if(!student) throw studentError;

    return *student;
}

Course Database::doQueryCourse(string code) const
{
    string courseError = "Course does not exist";

    Course* course = courseRecord.search(Course(code));

    if(!course) throw courseError;

    return *course;
}

Registration Database::doQueryRegistration(string stuID, string code) const
{
    string regError = "Registration does not exist";

    Registration* registration = regRecord.search(Registration(stuID, code));

    if(!registration) throw regError;
    return *registration;
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
