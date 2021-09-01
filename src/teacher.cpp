#include "teacher.h"

Teacher::Teacher()
{}

Teacher::Teacher(int id, string name, string pwd)
{
    this->m_TID = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

void Teacher::MenuOperation()
{
    cout << "You log in as Student successfully!" << endl;
    cout << "\t\t----------------------------------------\n";
    cout << "\t\t|       1. Show All Reservation        |\n";
    cout << "\t\t|                                      |\n";
    cout << "\t\t|       2. Process Reservation         |\n";
    cout << "\t\t|                                      |\n";
    cout << "\t\t|       0. Log Out                     |\n";
    cout << "\t\t----------------------------------------\n";
    cout << "Enter you choice here: ";
}

void Teacher::ShowAllReservation()
{
    ReservationFile rf;
    if (rf.m_Size == 0)
    {
        cout << "No reservation record!" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < rf.m_Size; i++)
    {
        cout << i + 1 << ". ";
        cout << "Reservation Date: " << rf.m_RevData[i]["data"];
        cout << " Time Interval: " << (rf.m_RevData[i]["interval"] == "1"? "8 am - 12 am":"1 pm - 5 pm");
        cout << " Name: " << rf.m_RevData[i]["stuName"];
        cout << " Room: " << rf.m_RevData[i]["roomID"];
        string status = " Status: ";
        if (rf.m_RevData[i]["status"] == "1")
        {
            status += "In Process";
        }
        else if (rf.m_RevData[i]["status"] == "2")
        {
            status += "Computer Reserved";
        }else if (rf.m_RevData[i]["status"] == "-1")
        {
            status += "Reservation Not Pass";
        }
        else
        {
            status += "Reservation Canceled";
        }
        cout << status << endl;
    }
    system("pause");
    system("cls");
}

void Teacher::ProcessReservation()
{
    ReservationFile rf;
    if (rf.m_Size == 0)
    {
        cout << "No reservation record!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "The reservation in process as follows:" << endl;

    vector<int> v;
    int index = 0;
    for (int i=0; i<rf.m_Size; i++)
    {
        if (rf.m_RevData[i]["status"] == "1")
        {
            v.push_back(i);
            cout << ++index << ". ";
            cout << "Reservation Date: " << rf.m_RevData[i]["data"];
            cout << " Time Interval: " << (rf.m_RevData[i]["interval"] == "1"? "8 am - 12 am":"1 pm - 5 pm");
            cout << " Name: " << rf.m_RevData[i]["stuName"];
            cout << " Room: " << rf.m_RevData[i]["roomID"];
            string status = " Status: ";
            if (rf.m_RevData[i]["status"] == "1")
            {
                status += "In Process";
            }
            cout << status << endl;
        }
    }

    cout << "Please enter the number fo reservation to process:(0 for returning to last step)" << endl;
    int select = 0;
    int ret = 0;

    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                cout << "Please enter your decision: " << endl;
                cout << "1. Pass" << endl;
                cout << "2. Reject" << endl;
                cin >> ret;

                if (ret == 1)
                {
                    rf.m_RevData[v[select-1]]["status"] = "2";
                }
                else
                {
                    rf.m_RevData[v[select-1]]["status"] = "-1";
                }
                rf.updateReservation();
                cout << "Processed!" << endl;
                break;
            }
        }
        cout << "Please enter a valid number!" << endl;
    }
    system("pause");
    system("cls");
    
}