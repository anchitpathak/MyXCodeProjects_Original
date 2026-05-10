#pragma once
#include<string>
using namespace std;

class DocumentElement{
public:
    virtual string render() = 0;
};
