#include "Utils.h"

bool parseStuID(const string& ID)
{
    if(ID.length() > MAX_StuID_LENGTH || ID.length() < MIN_StuID_LENGTH)
        return false;

    const char* c_str = ID.c_str();
    const char numMin('0'), numMax('9');

    for(unsigned int i = 0; i != ID.length(); ++i)
    {
        if(c_str[i] < numMin || c_str[i] > numMax)
            return false;
    }

    return true;
}

bool parseStuName(const string& name)
{
    if(name.length() > MAX_StuName_LENGTH)
        return false;
    else
        return true;
}

bool parseCourseCode(const string& code)
{
    if(code.length() > MAX_CourseCode_LENGTH)
        return false;

    const char* c_str = code.c_str();
    const char upperCharMin('A'), upperCharMax('Z');

    for(unsigned int i = 0; i != CourseCodePrefix_LENGTH; ++i)
    {
        if(c_str[i] < upperCharMin || c_str[i] > upperCharMax)
            return false;
    }

    const char numMin('0'), numMax('9');

    for(unsigned int i = CourseCodePrefix_LENGTH; i != code.length(); ++i)
    {
        if(c_str[i] < numMin || c_str[i] > numMax)
            return false;
    }

    return true;
}

bool parseCourseName(const string& name)
{
    if(name.length() > MAX_CourseName_LENGTH || name.length() < MIN_CourseCode_LENGTH)
        return false;
    else
        return true;
}
