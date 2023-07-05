#include <iostream>
#include <vector>

class A_Class {
public:
    class Student {
    private:
        std::string id, name, address;
        float gpa;

    public:
        Student() : id(""), name(""), address(""), gpa(0.0) {}

        void inputStudentInformation() {
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter student address: ";
            std::getline(std::cin, address);
            std::cout << "Enter student GPA: ";
            std::cin >> gpa;
        }

        void displayStudentInformation() {
            std::cout << "Student ID: " << id << std::endl;
            std::cout << "Student Name: " << name << std::endl;
            std::cout << "Student Address: " << address << std::endl;
            std::cout << "Student GPA: " << gpa << std::endl;
        }

        std::string getID() const {
            return id;
        }
    };

private:
    std::vector<Student> students;

public:
    void inputStudents(int n) {
        for (int i = 1; i <= n; i++) {
            std::cout << "Enter information for student " << i << ":" << std::endl;
            Student newStudent;
            newStudent.inputStudentInformation();
            students.push_back(newStudent);
            std::cout << std::endl;
        }
    }

    void removeStudent() {
        std::string studentID;
        std::cout << "Enter the ID of the student you want to remove: ";
        std::cin >> studentID;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == studentID) {
                students.erase(it);
                std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
                return;
            }
        }

        std::cout << "Student with ID " << studentID << " does not exist." << std::endl;
    }
};

