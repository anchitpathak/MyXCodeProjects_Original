#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

enum class Direction { UP, DOWN, IDLE };

class Elevator {
private:
    int id;
    int currentFloor;
    int targetFloor;
    bool doorOpen;
    Direction direction;
    bool interrupted;
    thread elevatorThread;
    mutex mtx;
    condition_variable cv;

public:
    Elevator(int id): id(id), currentFloor(0), targetFloor(0), doorOpen(false), direction(Direction::IDLE), interrupted(false) {}

    void moveTo(int floor) {
        unique_lock<mutex> lock(mtx);
        targetFloor = floor;
        interrupted = false;

        if (elevatorThread.joinable())
            elevatorThread.join();

        elevatorThread = thread(&Elevator::run, this);
    }

    void run() {
        cout << "[Elevator " << id << "] Starting from floor " << currentFloor << " to floor " << targetFloor << endl;

        while (currentFloor != targetFloor) {
            {
                unique_lock<mutex> lock(mtx);
                if (interrupted) {
                    cout << "[Elevator " << id << "] Interrupted!" << endl;
                    stopAtNearestFloor();
                    return;
                }
            }

            this_thread::sleep_for(seconds(1));
            currentFloor += (targetFloor > currentFloor) ? 1 : -1;
            cout << "[Elevator " << id << "] Reached floor " << currentFloor << endl;
        }

        openDoor();
    }

    void openDoor() {
        doorOpen = true;
        cout << "[Elevator " << id << "] Door opened at floor " << currentFloor << endl;
        this_thread::sleep_for(seconds(2));
        closeDoor();
    }

    void closeDoor() {
        doorOpen = false;
        cout << "[Elevator " << id << "] Door closed" << endl;
    }

    void interrupt() {
        unique_lock<mutex> lock(mtx);
        interrupted = true;
        cv.notify_all();
    }

    void stopAtNearestFloor() {
        cout << "[Elevator " << id << "] Moving to nearest floor: " << currentFloor << endl;
        openDoor();
    }

    void joinThread() {
        if (elevatorThread.joinable())
            elevatorThread.join();
    }

    int getCurrentFloor() {
        return currentFloor;
    }

    bool isBusy() {
        unique_lock<mutex> lock(mtx);
        return direction != Direction::IDLE;
    }
};

class ElevatorSystem {
private:
    vector<Elevator*> elevators;

public:
    ElevatorSystem(int n) {
        for (int i = 0; i < n; ++i) {
            elevators.push_back(new Elevator(i));
        }
    }

    void requestElevator(int floor) {
        Elevator* chosen = elevators[0];
        int minDist = abs(elevators[0]->getCurrentFloor() - floor);

        for (auto& e : elevators) {
            int dist = abs(e->getCurrentFloor() - floor);
            if (dist < minDist) {
                minDist = dist;
                chosen = e;
            }
        }

        cout << "[System] Assigning Elevator " << floor << " to handle request" << endl;
        chosen->moveTo(floor);
    }

    void interruptAll() {
        cout << "\n[System] INTERRUPT triggered! Stopping all elevators.\n";
        for (auto& e : elevators) {
            e->interrupt();
        }
    }

    void waitAll() {
        for (auto& e : elevators)
            e->joinThread();
    }

    ~ElevatorSystem() {
        for (auto e : elevators)
            delete e;
    }
};

//int main() {
//    ElevatorSystem system(2); // 2 elevators
//
//    system.requestElevator(5);
//    this_thread::sleep_for(seconds(3));
//    system.requestElevator(2);
//
//    this_thread::sleep_for(seconds(2));
//    system.interruptAll();
//
//    system.waitAll();
//    return 0;
//}
