#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

class SinhVien {
private:
    string id, ten, ns;
    double gpa;
    static int dem;

public:
    SinhVien();
    SinhVien(string, string, string, double);
    void nhap();
    void in();
    double getGpa();
    string getId();
    void setGpa(double);
    void tangDem();
    int getDem();
};
int SinhVien::dem = 0;
// Implementation
SinhVien::SinhVien() {
    id = ten = ns = "";
    gpa = 0;
}

void SinhVien::tangDem(){
    ++dem;
}
int SinhVien::getDem(){
    return dem;
}
SinhVien::SinhVien(string id, string ten, string ns, double gpa) {
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa;
}

void SinhVien::nhap() {
    cout << "nhap id:"; cin>>this->id;
    cin.ignore();
    cout << "nhap ten:"; getline(cin, this->ten);
    cout<< "nhap ns:"; cin>> this->ns;
    cout<<"nhap diem:"; cin >> this->gpa;
}

void SinhVien::in() {
    cout << id << " " << ten << " " << ns << " " << fixed << setprecision(2) << gpa << endl;
}

double SinhVien::getGpa() {
    return this->gpa;
}

bool cmp(SinhVien a,SinhVien b){
    return a.getGpa() > b.getGpa();
}

string SinhVien::getId(){
    return this -> id ;
}

void SinhVien::setGpa(double gpa){
    this->gpa = gpa;
}
int main() {
    //x.setGpa(2.10)
    SinhVien x;
    x.tangDem();
    x.tangDem();
    SinhVien y;
    cout << y.getDem()<<endl;
    
    return 0;
}
