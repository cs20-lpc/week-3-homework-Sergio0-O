// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "Course.hpp"
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;

    struct Node {
        Course value;
        Node* next;
        Node(Course c, Node* n = nullptr) : value(c), next(n) {}
    };

    Node* head;

public:
    Student();
    Student(int i, string n, double g);
    ~Student();

    void setId(int i);
    void setName(string n);
    void setGpa(double g);

    int getId() const;
    string getName() const;
    double getGpa() const;

    void appendCourse(Course c);
    void printCourses() const;
    bool hasCourses() const;

    void clearCourses();
};

#endif
