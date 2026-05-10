#include "LiftController.h"

LiftController::LiftController(int count)
{
    for(int i = 0;i<count;i++)
    {
        lifts.emplace_back(i);
    }
}
void LiftController::requestLift(LiftDirection liftDirection, int floor)
{
    for(auto& lift : lifts)
    {
        if(lift.liftDirection == LiftDirection::IDLE)
        {
            //lift.destinationFloors.insert(floor);
            lift.addRequest(floor);
            cout<<"Lift "<<lift.id<<" is assigned"<<endl;
            return;
        }
    }
    lifts[0].addRequest(floor);
}
void LiftController::move()
{
    for(auto& lift : lifts)
    {
        lift.move();
    }
}
