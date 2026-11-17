#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string usn;
    int marks;
    static int count;

public:
   
    Student(string n, string u, int m) {
        name = n;
        usn = u;
        marks = m;
        count++;
    }

    
    friend void display(Student s);

    bool operator>(Student &s) {
        return this->marks > s.marks;
    }

   
    static int getCount() {
        return count;
    }
};


int Student::count = 0;


void display(Student s) {
    cout << "Name: " << s.name << ", USN: " << s.usn 
         << ", Marks: " << s.marks << endl;
}

int main() {
    Student s1("Alice", "1NT21EC001", 85);
    Student s2("Bob", "1NT21EC002", 90);

    display(s1);
    display(s2);

    if (s1 > s2)
        cout << s1.getCount() << ": " << "Alice has higher marks." << endl;
    else
        cout << s2.getCount() << ": " << "Bob has higher marks." << endl;

    cout << "Total Students: " << Student::getCount() << endl;
    return 0;
}
