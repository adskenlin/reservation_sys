#pragma once
#include <iostream>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
#include <algorithm>
using namespace std;
#include "identity.h"

class Admin :public Identity
{
public:

    Admin();

    Admin(string name, string pwd);

    virtual void MenuOperation();

    void AddAccounts();

    void ShowAccounts();

    void ShowStatus();

    void Clean();

    void initVector();

    bool CheckRepeat(int id, int type);

    vector<Student> vStu;

    vector<Teacher> vTea;

    vector<ComputerRoom> vCom;
    
};