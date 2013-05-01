#ifndef UTILS_H
#define UTILS_H

#include "Record.h"
using namespace std;

Student* getStudentFromInput();
Course* getCourseFromInput();

bool parseStuID(const string&);
bool parseStuName(const string&);
bool parseStuYear(const unsigned int&);
bool parseStuGender(const char&);
bool parseCourseCode(const string&);
bool parseCourseName(const string&);
bool parseCourseCredit(const unsigned int&);
bool parseExamMark(const unsigned int&);

#endif // UTILS_H
