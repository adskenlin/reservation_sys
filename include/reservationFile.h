#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "globalFile.h"
#include <string>
using namespace std;

class ReservationFile
{
public:
    ReservationFile();

    void updateReservation();

    map<int, map<string, string>> m_RevData;

    int m_Size;
};