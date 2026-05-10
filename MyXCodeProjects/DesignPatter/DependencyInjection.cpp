
//✅ Example: Printer depends on Message

#include <iostream>
#include <string>
using namespace std;

class Message {
public:
    string getMessage() {
        return "Hello from the Message class!";
    }
};

class Printer {
public:
    void print(Message& msg) {  // Printer depends on Message
        cout << msg.getMessage() << endl;
    }
};

//int main() {
//    Message m;
//    Printer p;
//    p.print(m);  // Using Message inside Printer
//    return 0;
//}
//🔍 What is the Dependency Here?
//Printer is dependent on Message:
//
//It uses the getMessage() method of Message.
//
//This is a "uses-a" relationship (not "has-a" or "is-a").


//✅ 1. Constructor Injection (Most Common)

class Service {
public:
    void doSomething() {
        cout << "Service working\n";
    }
};

class Client {
    Service& service;
public:
    Client(Service& s) : service(s) {} // Injection via constructor

    void execute() {
        service.doSomething();
    }
};

//int main() {
//    Service s;
//    Client c(s);  // Injecting dependency
//    c.execute();
//}
//✅ 2. Setter Injection (After object creation)

//class Client {
//    Service* service = nullptr;
//public:
//    void setService(Service* s) {  // Setter injection
//        service = s;
//    }
//
//    void execute() {
//        if (service)
//            service->doSomething();
//    }
//};
//
//int main() {
//    Service s;
//    Client c;
//    c.setService(&s);  // Injecting dependency
//    c.execute();
//}
//✅ 3. Interface (or Method) Injection
//Dependency is passed as a method parameter where it's needed.
//
//cpp
//Copy
//Edit
//class Client {
//public:
//    void execute(Service& s) {  // Method injection
//        s.doSomething();
//    }
//};

//int main() {
//    Service s;
//    Client c;
//    c.execute(s);  // Injecting dependency
//}
//Bonus: 💡 Using Smart Pointers (modern C++)
//For memory safety and ownership semantics, inject using std::shared_ptr or std::unique_ptr:
//
//cpp
//Copy
//Edit
//class Client {
//    std::shared_ptr<Service> service;
//public:
//    Client(std::shared_ptr<Service> s) : service(s) {}
//    void execute() { service->doSomething(); }
//};
