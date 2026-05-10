#pragma once
#include<iostream>
#include "LiftDirection.h"
#include "Lift.h"
#include<vector>

class LiftController
{
public:
    vector<Lift> lifts;
    LiftController(int count);
    void requestLift(LiftDirection liftDirection, int floor);
    void move();
};
