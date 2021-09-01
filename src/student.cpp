#include "student.h"

Student::Student()
{}

Student::Student(int id, string name, string pwd)
{
    this->m_ID = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom c;
    while (ifs >> c.m_ComID && ifs >> c.m_MaxNum)
    {
        vCom.push_back(c);
    }
    ifs.close();
}

void Student::MenuOperation()
{
    cout << "You log in as Student successfully!" << endl;
    cout << "\t\t----------------------------------------\n";
    cout << "\t\t|       1. Reserve Computer            |\n";
    cout << "\t\t|       2. Show My Reservation         |\n";
    cout << "\t\t|       3. Show All Reservation        |\n";
    cout << "\t\t|       4. Cancel Reservation          |\n";
    cout << "\t\t|       0. Log Out                     |\n";
    cout << "\t\t----------------------------------------\n";
    cout << "Enter you choice here: ";
}

void Student::Reservation()
{
    cout << "Computer Room is avaiable from Monday to Friday." << endl;
    cout << "Please choose a day for reservation: " << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if (date >= 1 && date <= 5)
        {
            break;
        }
        cout << "Please enter a valid number" << endl;
    }

    cout << "Please choose time interval for reservation: " << endl;
    cout << "1. 8 am - 12 am" << endl;
    cout << "2. 1 pm - 5 pm" << endl;

    while (true)
    {
        cin >> interval;
        if (interval >= 1 && interval <= 2)
        {
            break;
        }
        cout << "Please enter a valid number" << endl;
    }

    cout << "Please choose computer room for reservation: " << endl;
    cout << "1.Room has "<< vCom[0].m_MaxNum << " computers." << endl;
    cout << "2.Room has "<< vCom[1].m_MaxNum << " computers." << endl;
    cout << "3.Room has "<< vCom[2].m_MaxNum << " computers." << endl;

    while (true)
    {
        cin >> room;
        if (room >= 1 && room <= 3)
        {
            break;
        }
        cout << "Please enter a valid number" << endl;
    }

    cout << "Thanks for your reservation! Your teacher will process your application soon." << endl;

    ofstream ofs(RESERVATION_FILE, ios::app);
    ofs << "data:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuID:" << this->m_ID << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomID:" << room << " ";
    ofs << "status:" << 1 << endl;

    ofs.close();
    system("pause");
    system("cls");

}

void Student::ShowMyReservation()
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
        if (atoi(rf.m_RevData[i]["stuID"].c_str()) == this->m_ID)
        {
            cout << "Reservation Date: " << rf.m_RevData[i]["data"];
            cout << " Time Interval: " << (rf.m_RevData[i]["interval"] == "1"? "8 am - 12 am":"1 pm - 5 pm");
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
    }
    system("pause");
    system("cls");

}

void Student::ShowAllReservation()
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

void Student::CancelReservation()
{
    ReservationFile rf;
    if (rf.m_Size == 0)
    {
        cout << "No reservation record!" << endl;
        system("pause");
        system("cls");
        return;
    }

    cout << "Attention: Only the successful reservation and reservation in process could be canceled." << endl;

    vector<int> v;
    int index = 1;
    for (int i = 0; i < rf.m_Size; i++)
    {
        if (atoi(rf.m_RevData[i]["stuID"].c_str()) == this->m_ID)
        {
            if (rf.m_RevData[i]["status"] == "1" || rf.m_RevData[i]["status"] == "2")
            {
                v.push_back(i);
                cout << index++ << ". ";
                cout << "Reservation Date: " << rf.m_RevData[i]["data"];
                cout << " Time Interval: " << (rf.m_RevData[i]["interval"] == "1"? "8 am - 12 am":"1 pm - 5 pm");
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
        }
    }

    cout << "Please enter the number of reservation to cancal:(0 for returning to last step)" << endl;
    int select = 0;
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
                rf.m_RevData[v[select-1]]["status"] = "0";
                rf.updateReservation();
                cout << "Reservation Canceled" << endl;
                break;
            }
        }
        cout << "Please enter a valid number." << endl;
    }
    system("pause");
    system("cls");

}