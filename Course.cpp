// TODO:  Course class methods implementation here.
#include "Course.hpp"

Course::Course() {
    courseName = "";
    location = "";
}

Course::Course(string n, string l) {
    courseName = n;
    location = l;
}

void Course::setCourseName(string n) { courseName = n; }
void Course::setLocation(string l) { location = l; }

string Course::getCourseName() const { return courseName; }
string Course::getLocation() const { return location; }
