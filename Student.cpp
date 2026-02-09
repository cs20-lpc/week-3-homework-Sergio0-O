// TODO:  Student class methods implementation here.
#include "Student.hpp"

Student::Student() {
    id = 0;
    name = "";
    gpa = 0.0;
    head = nullptr;
}

Student::Student(int i, string n, double g) {
    id = i;
    name = n;
    gpa = g;
    head = nullptr;
}

Student::~Student() {
    clearCourses();
}

void Student::setId(int i) { id = i; }
void Student::setName(string n) { name = n; }
void Student::setGpa(double g) { gpa = g; }

int Student::getId() const { return id; }
string Student::getName() const { return name; }
double Student::getGpa() const { return gpa; }

void Student::appendCourse(Course c) {
    Node* newNode = new Node(c, nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

bool Student::hasCourses() const {
    return head != nullptr;
}

void Student::printCourses() const {
    if (head == nullptr) {
        cout << "None";
        return;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->value.getCourseName() << " " << curr->value.getLocation();
        if (curr->next != nullptr) {
            cout << "\n         ";
        }
        curr = curr->next;
    }
}

void Student::clearCourses() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* node = curr;
        curr = curr->next;
        delete node;
    }
    head = nullptr;
}
