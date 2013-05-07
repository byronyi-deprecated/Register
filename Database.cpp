#include "Database.h"

bool Database::doInsertStudent(const Student& student)
{
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
        stu_idx_ptr = courseIndex.search(CourseIdx(reg.getCode()));
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
    else
        idx_ptr->reg.clear();

    return ;
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
