#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student{

    string name;
    string surname;
    string album_number;
    vector<float> grades;
public:
    void set_names(string n,string s)
    {
        name=n;
        surname=s;
    }
    bool set_album_number(string a)
    {
        if(a.size()==6)
        {
            album_number=a;
            return true;
        }
        return false;
    }
    void display_summary()
    {
        cout<<name<<" "<<surname<<" "<<album_number<<"| ";
        for(auto grade:grades)
        {
            cout<<grade<<" ";
        }
        cout<<endl;
    }
    bool add_grade(float grade)
    {
        if(grade>=2.0 and grade<=5.0)
        {
            grades.push_back(grade);
            return true;
        }
        return false;
    }
    float mean_grade()
    {
        return accumulate(grades.begin(),grades.end(), 0.0f)/grades.size();
    }
    bool semester_passed()
    {
        int twos=0;
        for(auto grade:grades)
        {
            if(grade==2.0)
                twos++;
            if(twos>1)
                return false;
        }
        if(mean_grade()>=3.0)
            return true;
        else
            return false;
    }

};
class Complex
{
    float real;
    float imaginary;
public:
    Complex(float r=0,float i=0)
    {
        real=r;
        imaginary=i;
    }
    void set_re(float r)
    {
        real=r;
    }
    void set_im(float i)
    {
        imaginary=i;
    }
    float real_part()
    {
        return real;
    }
    float imaginary_part()
    {
        return imaginary;
    }
    void print()
    {
        cout<<real;
        if(imaginary>0)
            cout<<"+"<<imaginary<<"i";
        else if(imaginary<0)
            cout<<imaginary<<"i";
    }
    Complex add(Complex &b)
    {
        float re=real+b.real_part();
        float im=imaginary+b.imaginary_part();
        return {re,im};
    }

};



int main()
{
//Student student;
//string n,s,a;
//int x;
//float g;
//cin>>n>>s;
//student.set_names(n,s);
//while(1)
//{
//    cin>>a;
//    if(student.set_album_number(a))
//        break;
//}
//student.set_album_number(a);
//cin>>x;
//for(int i=0;i<x;i++)
//{
//    while(1)
//    {
//        cin>>g;
//        if(student.add_grade(g))
//            break;
//    }
//}
//student.display_summary();
//cout<<student.mean_grade()<<" "<<student.semester_passed();

    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i

}
