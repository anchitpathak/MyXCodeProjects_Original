#include "LiftController.h"
#include<chrono>
#include<thread>

//int main()
//{
//    LiftController* liftController = new LiftController(2);
//    liftController->requestLift(LiftDirection::UP,5);
//    liftController->requestLift(LiftDirection::DOWN,7);
//    liftController->requestLift(LiftDirection::UP,8);
//    for(int i = 0;i<10;i++)
//    {
//        liftController->move();
//        this_thread::sleep_for(chrono::milliseconds(500));
//    }
//    return 0;
//}
