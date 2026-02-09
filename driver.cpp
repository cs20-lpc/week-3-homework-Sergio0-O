#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

bool isNumber(const string& s) {
    if (s.length() == 0)
        return false;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int toInt(const string& s) {
    int value = 0;
    for (size_t i = 0; i < s.length(); i++) {
        value = value * 10 + (s[i] - '0');
    }
    return value;
}

double toDouble(const string& s) {
    double value = 0.0;
    double factor = 1.0;
    bool decimal = false;

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            decimal = true;
            continue;
        }
        if (!decimal) {
            value = value * 10 + (s[i] - '0');
        } else {
            factor /= 10;
            value += (s[i] - '0') * factor;
        }
    }
    return value;
}

class LinkedList {
private:
    struct Node {
        Student value;
        Node* next;
        Node(Student s, Node* n = nullptr) : value(s), next(n) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { clear(); }

    void append(Student s) {
        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = newNode;
        }
    }

    bool remove(int id) {
        if (head == nullptr) return false;

        if (head->value.getId() == id) {
            Node* node = head;
            head = head->next;
            delete node;
            return true;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->value.getId() != id)
            curr = curr->next;

        if (curr->next == nullptr) return false;

        Node* node = curr->next;
        curr->next = node->next;
        delete node;
        return true;
    }

    Student* search(int id) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->value.getId() == id)
                return &curr->value;
            curr = curr->next;
        }
        return nullptr;
    }

    int count() const {
        int total = 0;
        Node* curr = head;
        while (curr != nullptr) {
            total++;
            curr = curr->next;
        }
        return total;
    }

    void display() const {
        cout << "Students in List:" << endl;

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->value.getId() << " "
                 << curr->value.getName() << " "
                 << curr->value.getGpa() << " ";
            curr->value.printCourses();
            cout << endl;
            curr = curr->next;
        }
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* node = curr;
            curr = curr->next;
            delete node;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList list;
    int choice = 0;

    cout << "1. Insert Student\n"
         << "2. Delete Student\n"
         << "3. Search Student\n"
         << "4. Display All\n"
         << "5. Count Students\n"
         << "6. Add a course\n"
         << "7. Exit\n";

    while (choice != 7) {
        string tempChoice;

        cout << "\nEnter choice: ";
        getline(cin, tempChoice);

        if (!isNumber(tempChoice)) {
            cout << "Invalid menu choice" << endl;
            continue;
        }

        choice = toInt(tempChoice);

        if (choice == 1) {
            string tempId, name, tempGpa;

            cout << "Enter ID: ";
            getline(cin, tempId);
            if (!isNumber(tempId)) {
                cout << "Invalid ID input" << endl;
                continue;
            }

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            getline(cin, tempGpa);

            bool validGpa = true;
            for (size_t i = 0; i < tempGpa.length(); i++) {
                if ((tempGpa[i] < '0' || tempGpa[i] > '9') && tempGpa[i] != '.') {
                    validGpa = false;
                }
            }

            if (!validGpa) {
                cout << "Invalid GPA input" << endl;
                continue;
            }

            int id = toInt(tempId);
            double gpa = toDouble(tempGpa);

            list.append(Student(id, name, gpa));
        }
        else if (choice == 2) {
            string tempId;
            cout << "Enter ID to delete: ";
            getline(cin, tempId);

            if (!isNumber(tempId)) {
                cout << "Invalid ID input" << endl;
                continue;
            }

            int id = toInt(tempId);
            if (list.remove(id))
                cout << "Deleted student with ID " << id << endl;
            else
                cout << "Student not found" << endl;
        }
        else if (choice == 3) {
            string tempId;
            cout << "Enter ID to search: ";
            getline(cin, tempId);

            if (!isNumber(tempId)) {
                cout << "Invalid ID input" << endl;
                continue;
            }

            int id = toInt(tempId);
            Student* s = list.search(id);

            if (s == nullptr) {
                cout << "Student not found" << endl;
            } else {
                cout << "Found: " << s->getId() << " "
                     << s->getName() << " "
                     << s->getGpa() << endl;
                cout << "Courses: ";
                s->printCourses();
                cout << endl;
            }
        }
        else if (choice == 4) {
            list.display();
        }
        else if (choice == 5) {
            cout << "Total students: " << list.count() << endl;
        }
        else if (choice == 6) {
            string tempId, cname, loc;
            cout << "Enter ID: ";
            getline(cin, tempId);

            if (!isNumber(tempId)) {
                cout << "Invalid ID input" << endl;
                continue;
            }

            int id = toInt(tempId);
            Student* s = list.search(id);

            if (s == nullptr) {
                cout << "Student not found" << endl;
            } else {
                cout << "Enter Course Name: ";
                getline(cin, cname);

                cout << "Enter location: ";
                getline(cin, loc);

                s->appendCourse(Course(cname, loc));
            }
        }
    }

    return 0;
}
