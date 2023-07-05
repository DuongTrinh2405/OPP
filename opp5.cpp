#include <iostream>
#include <vector>

class A_Class {
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
            std::cin >> id;
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter student address: ";
            std::getline(std::cin, address);
            std::cout << "Enter student GPA: ";
            std::cin >> gpa;
        }

        void displayStudentInformation() const {
            std::cout << "Student ID: " << id << std::endl;
            std::cout << "Student Name: " << name << std::endl;
            std::cout << "Student Address: " << address << std::endl;
            std::cout << "Student GPA: " << gpa << std::endl;
        }

        int getID() const {
            return id;
        }
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

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == studentID) {
                students.erase(it);
                std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
                return;
            }
        }

        std::cout << "No student found with ID " << studentID << "." << std::endl;
    }

    // void displayAll() const {
    //     for (const auto& student : students) {
    //         student.displayStudentInformation();
    //         std::cout << std::endl;
    //     }
        // }
    void displayAll() const {
        int i = 0;
        while (i < students.size()) {
            students[i].displayStudentInformation();
            std::cout << std::endl;
            i++;
        }
    }


};

int main() {
    A_Class s;
    s.inputStudents();
    s.removeStudent();
    s.displayAll();

    return 0;
}
