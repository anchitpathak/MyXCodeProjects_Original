#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Storage
{
public:
    virtual void save(string& data) = 0;
};
