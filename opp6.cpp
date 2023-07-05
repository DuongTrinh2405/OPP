#include <iostream>
#include <vector>
#include <string>

class A_class {
public:
    class Student {
    private:
        std::string name, address;
        int id;
        float gpa;

    public:
        Student() : id(0), name(""), address(""), gpa(0.00) {}

        void inputStudentInformation() {
            std::cout << "Enter student ID: ";
            std::cin >> this->id;
            std::cin.ignore();  // Ignore the newline character in the input buffer
            std::cout << "Enter student name: ";
            getline(std::cin, this->name);
            std::cout << "Enter student address: ";
            getline(std::cin, this->address);
            std::cout << "Enter GPA of the student (out of 4): ";
            std::cin >> this->gpa;
        }

        void displayStudentInformation() const {
            std::cout << "Student ID: " << id << std::endl;
            std::cout << "Student Name: " << name << std::endl;
            std::cout << "Student Address: " << address << std::endl;
            std::cout << "Student GPA: " << gpa << std::endl;
        }

        int getID() const { return this->id; }
    };

private:
    std::vector<Student> students;

public:
    void inputStudents() {
        int n;
        std::cout << "Enter the number of students: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            std::cout << "Enter information for student " << i + 1 << ":" << std::endl;
            Student newStudent;
            newStudent.inputStudentInformation();
            students.push_back(newStudent);
            std::cout << std::endl;
        }
    }

    void removeStudent() {
        int studentID;
        std::cout << "Enter the ID of the student you want to remove: ";
        std::cin >> studentID;

        for (auto it = students.begin(); it != students.end(); it++) {
            if (it->getID() == studentID) {
                students.erase(it);
                std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
                return;
            }
        }

        std::cout << "No student found with ID " << studentID << "." << std::endl;
    }

    void displayAll() const {
        for (const auto& student : students) {
            student.displayStudentInformation();
            std::cout << std::endl;
        }
    }
};

int main() {
    A_class s;
    s.inputStudents();
    s.removeStudent();
    s.displayAll();

    return 0;
}
