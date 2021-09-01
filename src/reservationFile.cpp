#include "reservationFile.h"

ReservationFile::ReservationFile()
{
    ifstream ifs;
    ifs.open(RESERVATION_FILE, ios::in);

    string date;
    string interval;
    string stuID;
    string stuName;
    string roomID;
    string status;

    this->m_Size = 0;

    while (ifs >> date && ifs >> interval && ifs 
               >> stuID && ifs >> stuName && ifs 
               >> roomID && ifs >> status )
    {
        string key;
        string value;
        map<string, string> m;

        int pos = date.find(":");
        if (pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos);
            m.insert(make_pair(key, value));
        }

        pos = interval.find(":");
        if (pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos);
            m.insert(make_pair(key, value));
        }

        pos = stuID.find(":");
        if (pos != -1)
        {
            key = stuID.substr(0, pos);
            value = stuID.substr(pos + 1, stuID.size() - pos);
            m.insert(make_pair(key, value));
        }

        pos = stuName.find(":");
        if (pos != -1)
        {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos);
            m.insert(make_pair(key, value));
        }

        pos = roomID.find(":");
        if (pos != -1)
        {
            key = roomID.substr(0, pos);
            value = roomID.substr(pos + 1, roomID.size() - pos);
            m.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos);
            m.insert(make_pair(key, value));
        }

        this->m_RevData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }

    ifs.close();
}

void ReservationFile::updateReservation()
{
    if (this->m_Size == 0)
    {
        return;
    }

    ofstream ofs(RESERVATION_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_Size; i++)
    {
        ofs << "date:" << this->m_RevData[i]["date"] << " ";
        ofs << "interval:" << this->m_RevData[i]["interval"] << " ";
        ofs << "stuID:" << this->m_RevData[i]["stuID"] << " ";
        ofs << "stuName:" << this->m_RevData[i]["stuName"] << " ";
        ofs << "roomID:" << this->m_RevData[i]["roomID"] << " ";
        ofs << "status:" << this->m_RevData[i]["status"] << " ";
    }
    ofs.close();
}