#include "Lift.h"

Lift::Lift(int id, int startFloor) :
id(id), currentFloor(startFloor), liftDirection(LiftDirection::IDLE){}
void Lift::addRequest(int floor)
{
    destinationFloors.insert(floor);
    liftDirection = (floor > currentFloor ? LiftDirection::UP : LiftDirection::DOWN);
}
void Lift::move()
{
    if(destinationFloors.empty())
    {
        liftDirection = LiftDirection::IDLE;
        return;
    }
    
    if(liftDirection == LiftDirection::UP) currentFloor++;
    else currentFloor--;
    
    if(destinationFloors.count(currentFloor))
    {
        cout<<"Elevator "<<id<<"stopped at floor "<<currentFloor<<"."<<endl;
        destinationFloors.erase(currentFloor);
        if(destinationFloors.empty())
            liftDirection = LiftDirection::IDLE;
    }
}
