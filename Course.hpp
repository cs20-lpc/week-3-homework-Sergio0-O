// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;

class Course {
private:
    string courseName;
    string location;

public:
    Course();
    Course(string n, string l);

    void setCourseName(string n);
    void setLocation(string l);

    string getCourseName() const;
    string getLocation() const;
};

#endif
