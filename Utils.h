#ifndef UTILS_H
#define UTILS_H

#include "Record.h"
using namespace std;

string getStuIDFromInput() const;
string getCodeFromInput() const;

string getStuNameFromInput(string _name = string()) const;
unsigned int getStuYearFromInput(unsigned _year = 99) const;
char getStuGenderFromInput(char _gender = '\0') const;

string getCourseNameFromInput(string _name = string()) const;
unsigned int getCourseCreditFromInput(unsigned int credit = 99) const;

unsigned int getExamMarkFromInput(unsigned int _mark = NA_EXAM_MARK) const;

bool parseStuID(const string&);
bool parseStuName(const string&);
bool parseStuYear(const unsigned int&);
bool parseStuGender(const char&);
bool parseCourseCode(const string&);
bool parseCourseName(const string&);
bool parseCourseCredit(const unsigned int&);
bool parseExamMark(const unsigned int&);

#endif // UTILS_H
