#include <iostream>
#include <vector>

class A_Class{
    private:
        string name, address, phone;
    public:

        class Student{
            private:
                int id;
                float gpa;
            public:
               Student(){
                    id = name = address = "";
                    gpa = 0;
               }
                void inputStudentInformation();
                void displayStudentInformation();


        };

};


int main(){

}