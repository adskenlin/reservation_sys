#include "administrator.h"

Admin::Admin()
{}

Admin::Admin(string name, string pwd)
{
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
}

void Admin::MenuOperation()
{
    cout << "You log in as Administrator successfully!" << endl;
    cout << "\t\t----------------------------------------\n";
    cout << "\t\t|       1. Add Accounts                |\n";
    cout << "\t\t|       2. Show Accounts               |\n";
    cout << "\t\t|       3. Show Reservation Status     |\n";
    cout << "\t\t|       4. Clear All Reservation       |\n";
    cout << "\t\t|       0. Log Out                     |\n";
    cout << "\t\t----------------------------------------\n";
    cout << "Enter you choice here: ";
}

void Admin::AddAccounts()
{
    cout << "Please enter the type of account: " << endl;
    cout << "1. Student Account" << endl;
    cout << "2. Teacher Account" << endl;

    string filename;
    string tip;
    string errmsg;
    ofstream ofs;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        filename = STUDENT_FILE;
        tip = "Please enter student number: ";
        errmsg = "Student number exists, please enter an another number";
    }
    else
    {
        filename = TEACHER_FILE;
        tip = "Please enter worker number: ";
        errmsg = "Teacher number exists, please enter an another number";
    }
    
    ofs.open(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    cout << tip << endl;

    while (true)
    {
        cin >> id;

        bool ret = this->CheckRepeat(id, select);

        if (ret)
        {
            cout << errmsg << endl;
        }
        else
        {
            break;
        }

    }

    cout << "Please enter name: " << endl;
    cin >> name;

    cout << "Please enter password: " << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "Account Added!" << endl;

    system("pause");
    system("cls");

    ofs.close();

    this->initVector();

}

void printStudents(Student &s)
{
    cout << "Student Number: " << s.m_ID << "\tName: " << s.m_Name << "\tpassword: " << s.m_Pwd << endl;
}

void PrintTeachers(Teacher &t)
{
    cout << "Student Number: " << t.m_TID << "\tName: " << t.m_Name << "\tpassword: " << t.m_Pwd << endl;
}

void Admin::ShowAccounts()
{
    cout << "Please enter the type of accounts: " << endl;
    cout << "1. Students" << endl;
    cout << "2. Teachers" << endl;

    int select = 0;

    cin >> select;

    if (select == 1)
    {
        cout << "All students accounts: " << endl;
        for_each(vStu.begin(), vStu.end(), printStudents);
    }
    else
    {
        cout << "All Teachers accounts: " << endl;
        for_each(vTea.begin(), vTea.end(), PrintTeachers);
    }
    system("pause");
    system("cls");
}

void Admin::ShowStatus()
{}

void Admin::Clean()
{
    ofstream ofs(RESERVATION_FILE, ios::trunc);
    ofs.close();

    cout << "Reservation Clear!" << endl;
    system("pause");
    system("cls");
}

void Admin::initVector()
{
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }

    vStu.clear();
    vTea.clear();

    Student s;
    while (ifs >> s.m_ID && ifs >> s.m_Name && ifs >> s.m_Pwd)
    {
        vStu.push_back(s);
    }
    cout << "Currently we have " << vStu.size() << " students registered." << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.m_TID && ifs >> t.m_Name && ifs >> t.m_Pwd)
    {
        vTea.push_back(t);
    }
    cout << "Currently we have " << vTea.size() << " teachers registered." << endl;

    ifs.close();

    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom c;
    while(ifs >> c.m_ComID && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    cout << "Currently there are " << vCom.size() << " computer room(s)." << endl;
    
    ifs.close();
}

bool Admin::CheckRepeat(int id, int type)
{
    if (type == 1)
    {
        for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
        {
            if (id == it->m_ID)
            {
                return true;
            }
        }
    }
    else
    {
        for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
        {
            if (id == it->m_TID)
            {
                return true;
            }
        }
    }
    return false;
}