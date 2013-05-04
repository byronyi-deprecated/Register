#include "Database.h"

bool Database::doInsertStudent(const Student& student)
{
    return studentRecord.insert(student);
}

bool Database::doInsertCourse(const Course& course)
{
    return courseRecord.insert(course);
}

bool Database::doInsertRegistration(const Student& student, const Course& course)
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


bool Database::doDeleteStudent(const Student& student)
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

bool Database::doDeleteCourse(const Course& course)
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

bool Database::doDeleteRegistration(const Student& student, const Course& course)
{

}


Student Database::doQueryStudent(const Student&) const
{
    return studentRecord.search(Student(stuID));
}

Course Database::doQueryCourse(const Course&) const
{
    return courseRecord.search(Course(code));
}

Registration Database::doQueryRegistration(const Registration&) const
{
    return regRecord.search(Registration(student, course));
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
