#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:
    virtual void MenuOperation() = 0;

    string m_Name;
    string m_Pwd;
    
};