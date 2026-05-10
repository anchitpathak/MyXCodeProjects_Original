#include <iostream>
#include <thread>
#include <shared_mutex> // C++17
#include <vector>


std::shared_mutex smtx;
std::vector<int> data = {1, 2, 3, 4, 5};

void reader(int id) {
    std::shared_lock<std::shared_mutex> lock(smtx); // shared read
    std::cout << "Reader " << id << ": ";
    for (int val : data)
    {
        std::cout << val << " "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << std::endl;
}
void writer() {
    std::unique_lock<std::shared_mutex> lock(smtx); // exclusive write
    data.push_back(6);
    std::cout << "Writer: added 6" << std::endl;
    std::cout<<"Anchit Pathak";
}

//int main() {
//    std::thread r1(reader, 1);
//    std::thread r2(reader, 2);
//    std::thread w1(writer);
//    std::thread r3(reader, 3);
//
//    r1.join();
//    r2.join();
//    w1.join();
//    r3.join();
//
//    return 0;
//}
