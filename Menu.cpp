#include "Menu.h"

MainMenu::MainMenu()
{
    studentMenu = new StudentMenu;
    studentMenu->addItem(&insertStudent);
    studentMenu->addItem(&deleteStudent);
    studentMenu->addItem(&modifyStudent);
    studentMenu->addItem(&queryStudent);
    studentMenu->addItem(this);

    courseMenu = new CourseMenu;
    courseMenu->addItem(&insertCourse);
    courseMenu->addItem(&deleteCourse);
    courseMenu->addItem(&modifyCourse);
    courseMenu->addItem(&queryCourse);
    courseMenu->addItem(this);

    recordMenu = new RecordMenu;
    recordMenu->addItem(&insertRecord);
    recordMenu->addItem(&deleteRecord);
    recordMenu->addItem(&modifyRecord);
    recordMenu->addItem(&queryRecord);
    recordMenu->addItem(this);

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
    addItem(recordMenu);
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
    cout << "---------------------------------" << endl;
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
    cout << "--------------------------------------------" << endl;
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
}

void CourseMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Course Menu>" << endl;
    cout << "--------------------------------------------" << endl;
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
}

void RecordMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Registration Menu>" << endl;
    cout << "--------------------------------------------" << endl;
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

}

void ReportMenu::go()
{
    system("cls");
    cout << "HKUST Course Registration System <Report Menu>" << endl;
    cout << "--------------------------------------------" << endl;
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

    subItem[choice - 1]->go();
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
}

void InsertStudent::go()
{

}

void InsertCourse::go()
{

}

void InsertRecord::go()
{

}

void DeleteStudent::go()
{

}

void DeleteCourse::go()
{

}

void DeleteRecord::go()
{

}

void ModifyStudent::go()
{

}

void ModifyCourse::go()
{

}

void ModifyRecord::go()
{

}

void QueryStudent::go()
{

}

void QueryCourse::go()
{

}

void QueryRecord::go()
{

}

void ReportStudent::go()
{

}

void ReportCourse::go()
{

}

void ReportCourseByStudent::go()
{

}

void ReportStudentByCourse::go()
{

}

void SaveDatabase::go()
{

}

void LoadDatabase::go()
{

}
