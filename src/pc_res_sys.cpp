#include <iostream>
#include <fstream>
#include "identity.h"
#include <string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "administrator.h"
using namespace std;

void TeacherMenu(Identity * &t)
{
    while (true)
    {
        t->MenuOperation();

        Teacher* person = (Teacher*)t;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            person->ShowAllReservation();
        }
        else if (select == 2)
        {
            person->ProcessReservation();
        }
        else
        {
            delete t;
            cout << "Log out successfully!" << endl;
            system("pause");
            system("cls");
            return;
        }       
    }
}

void StudentMenu(Identity * &s)
{
    while (true)
    {
        s->MenuOperation();

        Student* person = (Student*)s;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            person->Reservation();
        }
        else if (select == 2)
        {
            person->ShowMyReservation();
        }
        else if (select == 3)
        {
            person->ShowAllReservation();
        }
        else if (select == 4)
        {
            person->CancelReservation();
        }
        else
        {
            delete s;
            cout << "Log out successfully!" << endl;
            system("pause");
            system("cls");
            return;
        }       
    }
}

void AdminMenu(Identity * &admin)
{
    while (true)
    {
        admin->MenuOperation();

        Admin* person = (Admin*)admin;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            cout << "Add Accounts" << endl;
            person->AddAccounts();
        }
        else if (select == 2)
        {
            cout << "Show Accounts" << endl;
            person->ShowAccounts();
        }
        else if (select == 3)
        {
            cout << "Show Reservation Status" << endl;
            person->ShowStatus();
        }
        else if (select == 4)
        {
            cout << "Clear All Reservation" << endl;
            person->Clean();
        }
        else
        {
            delete admin;
            cout << "log out successfully" << endl;
            system("pause");
            system("cls");
            return;
        }
        

    }
}

void Login(string filename, int type)
{
    Identity * person = NULL;

    ifstream ifs;
    ifs.open(filename, ios::in);

    if (!ifs.is_open())
    {
        cout << "File does not exist!" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1)
    {
        cout << "Please enter your student number: ";
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "Please enter your work number: ";
        cin >> id;
    }

    cout << "Please enter your username: " << endl;
    cin >> name;
    cout << "Please enter your password: " << endl;
    cin >> pwd;

    if (type == 1)
    {
        //student login
        int stuID;
        string stuName;
        string stuPwd;

        while (ifs >> stuID && ifs >> stuName && ifs >> stuPwd)
        {
            if (id == stuID && name == stuName && pwd == stuPwd)
            {
                cout << "Student logged in!" << endl;
                system("pause");
                system("cls");
                person = new Student(id, name, pwd);
                StudentMenu(person);
                return;
            }
        }
    }
    else if (type == 2)
    {
        //teacher login
        int workID;
        string workName;
        string workPwd;

        while (ifs >> workID && ifs >> workName && ifs >> workPwd)
        {
            if (id == workID && name == workName && pwd == workPwd)
            {
                cout << "Worker logged in!" << endl;
                system("pause");
                system("cls");
                person = new Teacher(id, name, pwd);
                TeacherMenu(person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        //admin login
        string adminName;
        string adminPwd;
        while (ifs >> adminName && ifs >> adminPwd)
        {
            if (name == adminName && pwd == adminPwd)
            {
                cout << "Administator logged in!" << endl;
                system("pause");
                system("cls");

                person = new Admin(name, pwd);
                AdminMenu(person);
                return;
            }
        }
    }

    cout << "Log in Failed!" << endl;

    system("pause");
    system("cls");
    return;    
}

int main()
{
    int select = 0;
    while (true)
    {
        cout << "Welcome to PC Reservation System!" << endl;
        cout << "You want to log in as: " << endl;
        cout << "\t\t--------------------------------\n";
        cout << "\t\t|       1. Student             |\n";
        cout << "\t\t|       2. Teacher             |\n";
        cout << "\t\t|       3. Administrator       |\n";
        cout << "\t\t|       0. Quit System         |\n";
        cout << "\t\t--------------------------------\n";
        cout << "Enter you choice here: ";

        cin >> select;
        
        switch (select)
        {
        case 1:
            Login(STUDENT_FILE, 1);
            break;
        case 2:
            Login(TEACHER_FILE, 2);
            break;
        case 3:
            Login(ADMIN_FILE, 3);
            break;
        case 0:
            cout << "SEE YOU !" << endl;
            system("pause");
            exit(0);
            break;
        
        default:
            cout << "Please enter a valid number!" << endl;
            system("pause");
            system("cls");
            break;
        }
    }

    cout << "Welcome to PC Reservation System!" << endl;
    cout << "You want to log in as: " << endl;
    cout << "\t\t--------------------------------\n";
    cout << "\t\t|       1. Student             |\n";
    cout << "\t\t|       2. Teacher             |\n";
    cout << "\t\t|       3. System Manager      |\n";
    cout << "\t\t|       0. Quit System         |\n";
    cout << "\t\t--------------------------------\n";
    cout << "Enter you choice here: ";
    
    system("pause");
    return 0;
}