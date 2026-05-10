#include <iostream>
#include <set>
using namespace std;

enum class Direction { UP, DOWN, IDLE };

class Elevator {
private:
    int currentFloor;
    Direction direction;
    
    set<int> upQueue;                // Floors above current
    set<int, greater<int>> downQueue; // Floors below current
    
public:
    Elevator(int startFloor = 0)
    : currentFloor(startFloor), direction(Direction::IDLE) {}
    
    void addRequest(int floor) {
        if (floor > currentFloor)
            upQueue.insert(floor);
        else if (floor < currentFloor)
            downQueue.insert(floor);
        else
            cout << "Already at floor " << floor << endl;
        
        if (direction == Direction::IDLE) {
            direction = (floor > currentFloor) ? Direction::UP : Direction::DOWN;
        }
    }
    
    void step() {
        switch (direction) {
            case Direction::UP:
                if (!upQueue.empty()) {
                    int next = *upQueue.begin();
                    moveTo(next);
                    upQueue.erase(next);
                } else if (!downQueue.empty()) {
                    direction = Direction::DOWN;
                } else {
                    direction = Direction::IDLE;
                }
                break;
                
            case Direction::DOWN:
                if (!downQueue.empty()) {
                    int next = *downQueue.begin();
                    moveTo(next);
                    downQueue.erase(next);
                } else if (!upQueue.empty()) {
                    direction = Direction::UP;
                } else {
                    direction = Direction::IDLE;
                }
                break;
                
            case Direction::IDLE:
                cout << "Elevator is idle at floor " << currentFloor << endl;
                break;
        }
    }
    
    void moveTo(int floor) {
        cout << "Moving from floor " << currentFloor << " to floor " << floor << endl;
        currentFloor = floor;
    }
    
    int getCurrentFloor() const { return currentFloor; }
    Direction getDirection() const { return direction; }
    
    bool hasPendingRequests() const {
        return !upQueue.empty() || !downQueue.empty();
    }
};
//int main() {
//    Elevator elevator(3); // Start at floor 3
//
//    elevator.addRequest(6);
//    elevator.addRequest(2);
//    elevator.addRequest(5);
//    elevator.addRequest(1);
//    elevator.addRequest(8);
//
//    for (int i = 0; i < 10; ++i) {
//        elevator.step();
//    }
//
//    return 0;
//}
