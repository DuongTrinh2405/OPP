#include <iostream>
#include <vector>
#include <iomanip>


class Person {
private:
    float height, weight;

public:
    Person() : height(0.00), weight(0.00) {}

};

class IStudentInterface {
public:
    virtual void lean() = 0;
    virtual void dance() = 0;
};


class ParentActions {
public:
    virtual void eat() {
        std::cout << " rice rice rice " << std::endl;
    }

};

class Parent : public Person, public ParentActions {
public:
    void eat() {
        std::cout << " porridge porridge porridge " << std::endl;
    }
};

class A_class {
public:
    class Student : public Person, public IStudentInterface {
    private:
        std::string name, address;
        int id;
        float gpa;

    public:
        Student() : id(0), name(""), address(""), gpa(0.00) {}

        void inputStudentInformation() {
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Enter student NAME: ";
            std::getline(std::cin, name);
            std::cout << "Enter student ADDRESS: ";
            std::getline(std::cin, address);
            std::cout << "Enter student GPA: ";
            std::cin >> gpa;
        }

        void displayStudentInformation() const {
            std::cout << "Student ID: " << id << std::endl;
            std::cout << "Student NAME: " << name << std::endl;
            std::cout << "Student ADDRESS: " << address << std::endl;
            std::cout << "Student GPA: " << std::fixed << std::setprecision(2) << gpa << std::endl;
        }

        int getID() const {
            return id;
        }

        std::string getNAME() const {
            return name;
        }

        float getGPA() const {
            return gpa;
        }

        void lean() {
            std::cout << " a b c " << std::endl;
        }

        void dance() {
            std::cout << " la la la " << std::endl;
        }
    };

    std::vector<Student> vectorStudent;

public:
    void inputStudents() {
        int n;
        std::cout << "Enter the number of students: ";
        std::cin >> n;
        std::cin.ignore();

        for (int i = 0; i < n; i++) {
            Student newStudent;
            newStudent.inputStudentInformation();
            vectorStudent.push_back(newStudent);
            std::cout << std::endl;
        }
    }

    void removeStudent() {
        int studentIDToDelete;
        std::cout << "Enter the ID of the student you want to remove: ";
        std::cin >> studentIDToDelete;

        for (auto it = vectorStudent.begin(); it != vectorStudent.end(); ++it) {
            if (it->getID() == studentIDToDelete) {
                vectorStudent.erase(it);
                std::cout << "Student with ID " << studentIDToDelete << " has been removed." << std::endl;
                return;
            }
        }

        std::cout << "No student found with ID " << studentIDToDelete << std::endl;
    }

    void printAllStudentInformation() const {
        for (const auto& student : vectorStudent) {
            student.displayStudentInformation();
            std::cout << std::endl;
        }
    }

    void quickSortByGPA(int left, int right) {
        if (left < right) {
            int pivotIndex = partitionByGPA(left, right);
            quickSortByGPA(left, pivotIndex - 1);
            quickSortByGPA(pivotIndex + 1, right);
        }
    }

    int partitionByGPA(int left, int right) {
        float pivot = vectorStudent[right].getGPA();
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (vectorStudent[j].getGPA() > pivot) {
                i++;
                std::swap(vectorStudent[i], vectorStudent[j]);
            }
        }

        std::swap(vectorStudent[i + 1], vectorStudent[right]);
        return i + 1;
    }

    void bubbleSortByNAME() {
        int n = vectorStudent.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (vectorStudent[j].getNAME() > vectorStudent[j + 1].getNAME()) {
                    std::swap(vectorStudent[j], vectorStudent[j + 1]);
                }
            }
        }
    }
};

int main() {
    A_class s;
    s.inputStudents();
    // s.removeStudent();
    // s.printAllStudentInformation();
    // s.quickSortByGPA(0, s.vectorStudent.size() - 1);
    s.bubbleSortByNAME();
    s.printAllStudentInformation();

    return 0;
}
