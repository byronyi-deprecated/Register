#include "Menu.h"
using namespace Database;

MainMenu::MainMenu()
{
    studentMenu = new StudentMenu;
    studentMenu->addItem(&insertStudent);
    studentMenu->addItem(&modifyStudent);
    studentMenu->addItem(&deleteStudent);
    studentMenu->addItem(&queryStudent);
    studentMenu->addItem(this);

    courseMenu = new CourseMenu;
    courseMenu->addItem(&insertCourse);
    courseMenu->addItem(&modifyCourse);
    courseMenu->addItem(&deleteCourse);
    courseMenu->addItem(&queryCourse);
    courseMenu->addItem(this);

    registrationMenu = new RegistrationMenu;
    registrationMenu->addItem(&insertRegistration);
    registrationMenu->addItem(&deleteRegistration);
    registrationMenu->addItem(&modifyRegistration);
    registrationMenu->addItem(&queryRegistration);
    registrationMenu->addItem(this);

    reportMenu = new ReportMenu;
    reportMenu->addItem(&reportStudent);
    reportMenu->addItem(&reportCourse);
    reportMenu->addItem(&reportCourseByStudent);
    reportMenu->addItem(&reportStudentByCourse);
    reportMenu->addItem(this);

    fileMenu = new FileMenu;
    fileMenu->addItem(&reportStudent);
    fileMenu->addItem(&reportCourse);
    fileMenu->addItem(&reportCourseByStudent);
    fileMenu->addItem(&reportStudentByCourse);
    fileMenu->addItem(this);

    addItem(studentMenu);
    addItem(courseMenu);
    addItem(registrationMenu);
    addItem(reportMenu);
    addItem(fileMenu);
    addItem(&quit);
}

void Quit::go()
{
    exit(EXIT_SUCCESS);
}

void MainMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "1. Student Management" << endl;
    cout << "2. Course Management" << endl;
    cout << "3. Course Registration" << endl;
    cout << "4. Report Management" << endl;
    cout << "5. File Management" << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Enter your choice <1-6>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 6) {
        cout << "Invalid input, re-enter again <1-6>: ";
        cin >> choice;
    }

    subItem[choice - 1]->go();
}

void StudentMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Student Menu>" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "1. Insert Student Record" << endl;
    cout << "2. Modify Student Record" << endl;
    cout << "3. Delete Student Record" << endl;
    cout << "4. Query Student Record" << endl;
    cout << "5. Go Back to main menu" << endl;
    cout << endl;
    cout << "Enter your choice <1-5>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 5) {
        cout << "Invalid input, re-enter again <1-5>: ";
        cin >> choice;
    }

    subItem[choice - 1]->go();

    if(choice != 5)
    {
        cout << "Hit a key to continue..." << endl;
        char dummy;
        cin >> dummy;
        subItem[4]->go();
    }
}

void CourseMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Course Menu>" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "1. Insert Course Record" << endl;
    cout << "2. Modify Course Record" << endl;
    cout << "3. Delete Course Record" << endl;
    cout << "4. Query Course Record" << endl;
    cout << "5. Go Back to main menu" << endl;
    cout << endl;
    cout << "Enter your choice <1-5>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 5) {
        cout << "Invalid input, re-enter again <1-5>: ";
        cin >> choice;
    }

    subItem[choice - 1]->go();

    if(choice != 5)
    {
        cout << "Hit a key to continue..." << endl;
        char dummy;
        cin >> dummy;
        subItem[4]->go();
    }
}

void RegistrationMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Registration Menu>" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Add course" << endl;
    cout << "2. Drop course" << endl;
    cout << "3. Modify Exam Mark" << endl;
    cout << "4. Query Registration" << endl;
    cout << "5. Go Back to main menu" << endl;
    cout << endl;
    cout << "Enter your choice <1-5>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 5) {
        cout << "Invalid input, re-enter again <1-5>: ";
        cin >> choice;
    }

    subItem[choice - 1]->go();

    if(choice != 5)
    {
        cout << "Hit a key to continue..." << endl;
        char dummy;
        cin >> dummy;
        subItem[4]->go();
    }

}

void ReportMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Report Menu>" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "1. List all student information" << endl;
    cout << "2. List all course information" << endl;
    cout << "3. List all courses of a student" << endl;
    cout << "4. List all students of a course" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << endl;
    cout << "Enter your choice <1-5>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 5) {
        cout << "Invalid input, re-enter again <1-5>: ";
        cin >> choice;
    }

    try {subItem[choice - 1]->go();}
    catch(string err) {cout << err << endl << endl;}

    if(choice != 5)
    {
        cout << "Hit a key to continue..." << endl;
        char dummy;
        cin >> dummy;
        subItem[4]->go();
    }
}

void FileMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <File Menu>" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << "1. Save Database" << endl;
    cout << "2. Load Database" << endl;
    cout << "3. Go back to main menu" << endl;
    cout << endl;
    cout << "Enter your choice <1-3>: ";

    unsigned int choice = 0;
    cin >> choice;

    while(!choice || choice > 3) {
        cout << "Invalid input, re-enter again <1-3>: ";
        cin >> choice;
    }

    subItem[choice - 1]->go();
    if(choice != 2)
    {
        cout << "Hit a key to continue..." << endl;
        char dummy;
        cin >> dummy;
        subItem[2]->go();
    }
}

void InsertStudent::go()
{
    string ID = getStuIDFromInput();

    if(!doInsertStudent(Student(ID)))
    {
        cout << "Student already exist" << endl << endl;
        return;
    }

    string name = getStuNameFromInput();
    unsigned int year = getStuYearFromInput();
    char gender = getStuGenderFromInput();

    if(doModifyStudent(ID, name, year, gender))
        cout << "Creation of student record successful" << endl << endl;
    else
        doDeleteStudent(ID);

    return;
}

void InsertCourse::go()
{
    string code = getCodeFromInput();
    if(!doInsertCourse(Course(code)))
    {
        cout << "Course already exist" << endl << endl;
        return;
    }

    string name = getCourseNameFromInput();
    unsigned int credit = getCourseCreditFromInput();

    if(doModifyCourse(code, name, credit))
        cout << "Creation of course record successful" << endl << endl;
    else
        doDeleteCourse(code);

    return;
}

void InsertRegistration::go()
{
    string ID = getStuIDFromInput();
    doQueryStudent(ID);

    string code = getCodeFromInput();
    doQueryCourse(code);

    if(doInsertRegistration(Registration(ID, code)))
        cout << "Creation of course record successful" << endl << endl;
    else
        cout << "The registration already exists" << endl << endl;
    return;
}

void DeleteStudent::go()
{
    string ID = getStuIDFromInput();
    doQueryStudent(ID);

    if(doDeleteStudent(ID))
        cout << "Deletion of student record successful" << endl << endl;

    return;
}

void DeleteCourse::go()
{
    Course course = getCourseFromInput();
    doQueryCourse(code);

    if(doDeleteCourse(code))
        cout << "Deletion of course record successful" << endl << endl;

    return;
}

void DeleteRegistration::go()
{
    string ID = getStuIDFromInput();
    doQueryStudent(ID);

    string code = getCodeFromInput();
    doQueryCourse(code);

    if(doDeleteRegistration(ID, code))
        cout << "Drop course successful" << endl << endl;

    return;
}

void ModifyStudent::go()
{
    string ID = getStuIDFromInput();
    Student student = doQueryStudent(ID);

    string name = getStuNameFromInput(student.getName());
    unsigned int year = getStuYearFromInput(student.getYear());
    char gender = getStuGenderFromInput(student.getGender());

    if(doModifyStudent(ID, name, year, gender))
        cout << "Modification of student record successful" << endl << endl;

    return;
}

void ModifyCourse::go()
{
    string code = getCodeFromInput();
    Course course = doQueryCourse(code);

    string name = getCourseNameFromInput(course.getName());
    unsigned int credit = getCourseCreditFromInput(course.getCredit());

    if(doModifyCourse(code, name, credit))
        cout << "Modification of course record successful" << endl << endl;

    return;
}

void ModifyRegistration::go()
{
    string ID = getStuIDFromInput();
    doQueryStudent(ID);

    string code = getCodeFromInput();
    doQueryCourse(code);

    Registration regRecord = doQueryRegistration(ID, code);

    unsigned int mark = getExamMarkFromInput(regRecord.getMark());

    if(doModifyRegistration(ID, code, mark))
        cout << "Modification of exam mark successful" << endl << endl;

    return;
}

void QueryStudent::go()
{
    string ID = getStuIDFromInput();
    Student student = doQueryStudent(ID);

    cout << endl;
    cout << "ID:     " << student.getID() << endl;
    cout << "Name:   " << student.getName() << endl;
    cout << "Year:   " << student.getYear() << endl;
    cout << "Gender: " << student.getGender() << endl;
    cout << endl;
    return;
}

void QueryCourse::go()
{
    string code = getCodeFromInput();
    Course course = doQueryCourse(code);

    cout << endl;
    cout << "Code:   " << course.getCode() << endl;
    cout << "Name:   " << course.getName() << endl;
    cout << "Credit: " << course.getCredit() << endl;
    cout << endl;
    return;
}

void QueryRegistration::go()
{
    string ID = getStuIDFromInput();
    doQueryStudent(ID);

    string code = getCodeFromInput();
    doQueryCourse(code);

    Registration regRecord = doQueryRegistration(ID, code);

    cout << endl;
    cout << "Student ID:  " << regRecord.getID() << endl;
    cout << "Course Code: " << regRecord.getCode() << endl;
    cout << "Exam Mark:   " << regRecord.getMark() << endl;
    cout << endl;

    return;
}

void ReportStudent::go()
{
    if(Write2HTML_Student())
        cout << "Output successful" << endl << endl;
}

void ReportCourse::go()
{
    if(Write2HTML_Course())
        cout << "Output successful" << endl << endl;
}

void ReportCourseByStudent::go()
{
    string ID = getStuIDFromInput();
    Student student = doQueryStudent(ID);
    else if(Write2HTML_CourseByStudent(student))
        cout << "Output successful" << endl << endl;
}

void ReportStudentByCourse::go()
{
    Course* course = getCourseFromInput();
    if(!course)
        cout << "Course not exist" << endl << endl;
    else if(Write2HTML_StudentByCourse(course))
        cout << "Output successful" << endl << endl;
}

void SaveDatabase::go()
{
    cout << "Enter the filename: ";
    char* filename;
    cin >> filename;
    if(WriteToBinary(string(filename)))
        cout << "Saving successful" << endl << endl;
}

void LoadDatabase::go()
{
    cout << "Enter the filename: ";
    char* filename;
    cin >> filename;
    if(ReadFromBinary(string(filename)))
        cout << "Loading successful" << endl << endl;
    else
        cout << "Error: Load File Error <File not exist / File Corrupted / Incorrect Format>" << endl << endl;
}
