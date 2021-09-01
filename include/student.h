#pragma once
#include <iostream>
#include <vector>
#include "computerroom.h"
#include "globalFile.h"
#include <fstream>
using namespace std;
#include "identity.h"
#include "reservationFile.h"

class Student :public Identity
{
public:
    Student();

    Student(int id, string name, string pwd);

    virtual void MenuOperation();

    void Reservation();

    void ShowMyReservation();

    void ShowAllReservation();

    void CancelReservation();

    int m_ID;

    vector<ComputerRoom> vCom;

};