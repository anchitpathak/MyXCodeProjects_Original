#pragma once
#include<iostream>
#include "LiftDirection.h"
#include<set>
using namespace std;

class Lift
{
public:
    int id;
    LiftDirection liftDirection;
    int currentFloor;
    set<int> destinationFloors;
    Lift(int id, int startFloor = 0);
    void addRequest(int floor);
    void move();
};
