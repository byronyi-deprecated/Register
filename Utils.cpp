#include "Utils.h"
#include "Database.h"
#include <iostream>

Student* getStudentFromInput()
{
    cout << "Enter the student ID: ";
    string ID;
    cin >> ID;
    while(!parseStuID(ID))
        cin >> ID;

    return doQueryStudent(ID);
}

Course* getCourseFromInput()
{
    cout << "Enter the course code: ";
    string code;
    cin >> code;
    while(!parseCourseCode(code))
        cin >> code;

    return doQueryCourse(code);
}

bool parseStuID(const string& ID)
{
    if(ID.length() > MAX_StuID_LENGTH || ID.length() < MIN_StuID_LENGTH)
        return false;

    const char* c_str = ID.c_str();
    const char numMin('0'), numMax('9');

    for(unsigned int i = 0; i != ID.length(); ++i)
    {
        if(c_str[i] < numMin || c_str[i] > numMax)
        {
            cout << "Invalid input, re-enter again [student ID]: ";
            return false;
        }
    }

    return true;
}

bool parseStuName(const string& name)
{
    if(name.length() > MAX_StuName_LENGTH)
    {
        cout << "Invalid input, re-enter again [student name]: ";
        return false;
    }
    else
        return true;
}

bool parseStuYear(const unsigned int& year)
{
    if(year < MIN_StuYear || year > MAX_StuYear)
    {
        cout << "Invalid input, re-enter again [student year]: ";
        return false;
    }
    return true;
}

bool parseStuGender(const char& gender)
{
    if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
    {
        cout << "Invalid input, re-enter again [M,F]: ";
        return false;
    }
    return true;
}

bool parseCourseCode(const string& code)
{
    if(code.length() > MAX_CourseCode_LENGTH)
    {
        cout << "Invalid input, re-enter again [course code]: ";
        return false;
    }

    const char* c_str = code.c_str();
    const char upperCharMin('A'), upperCharMax('Z');

    for(unsigned int i = 0; i != CourseCodePrefix_LENGTH; ++i)
    {
        if(c_str[i] < upperCharMin || c_str[i] > upperCharMax)
        {
            cout << "Invalid input, re-enter again [course code]: ";
            return false;
        }
    }

    const char numMin('0'), numMax('9');

    for(unsigned int i = CourseCodePrefix_LENGTH; i != code.length(); ++i)
    {
        if(c_str[i] < numMin || c_str[i] > numMax)
        {
            cout << "Invalid input, re-enter again [course code]: ";
            return false;
        }
    }

    return true;
}

bool parseCourseName(const string& name)
{
    if(name.length() > MAX_CourseName_LENGTH || name.length() < MIN_CourseCode_LENGTH)
    {
        cout << "Invalid input, re-enter again [course name]: ";
        return false;
    }
    else
        return true;
}

bool parseCourseCredit(const unsigned int& credit)
{
    if(credit < MIN_CREDIT || credit > MAX_CREDIT)
    {
        cout << "Invalid input, re-enter again [course credit]: ";
        return false;
    }
    return true;
}

bool parseExamMark(const unsigned int& mark)
{
    if(mark < MIN_EXAM_MARK || mark > MAX_EXAM_MARK)
    {
        cout << "Invalid input, re-enter again [exam mark]: ";
        return false;
    }
    return true;
}
