#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "reservationFile.h"
using namespace std;
#include "identity.h"

class Teacher :public Identity
{
public:

    Teacher();

    Teacher(int id, string name, string pwd);

    virtual void MenuOperation();

    void ShowAllReservation();

    void ProcessReservation();

    int m_TID;
    
};