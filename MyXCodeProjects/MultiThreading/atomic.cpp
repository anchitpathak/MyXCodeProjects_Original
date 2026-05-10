#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

const int SIZE = 5;
atomic<int> arr[SIZE];   // atomic array

void increment(int index) {
    for (int i = 0; i < 1000; i++) {
        arr[index]++;   // atomic increment
    }
}

//int main() {
//
//    for (int i = 0; i < SIZE; i++)
//        arr[i] = 0;
//
//    thread t1(increment, 2);
//    thread t2(increment, 2);
//
//    t1.join();
//    t2.join();
//
//    cout << "arr[2] = " << arr[2] << endl;  // 2000
//
//    return 0;
//}
