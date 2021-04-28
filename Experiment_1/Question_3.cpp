#include<iostream>
using namespace std;

class imaginary
{
private:
    double x, y;
    static imaginary Answer;

public:
    imaginary(double,double);
    ~imaginary();
    static void show() { cout << Answer.x << " + " << Answer.y << " i" << endl; }
    friend void add(imaginary a, imaginary b) 
    {
        Answer.x = a.x + b.x;
        Answer.y = a.y + b.y;
    }
    friend void sub(imaginary a, imaginary b)
    {
        Answer.x = a.x - b.x;
        Answer.y = a.y - b.y;
    }
    friend void mul(imaginary a, imaginary b)
    {
        Answer.x = a.x * b.x - a.y * b.y;
        Answer.y = a.y * b.x + a.x * b.y;
    }
    friend void div(imaginary a, imaginary b)
    {
        //(a + bi) / (c + di) = (ac + bd) / (c2 + d2) + (bc - ad) / (c2 + d2) i
        Answer.x = (a.x * b.x + a.y * b.y) / (a.y * a.y + b.y * b.y);
        Answer.y = (a.y * b.x - a.x * b.y) / (a.y * a.y + b.y * b.y);
    }
};
imaginary a(0, 0);
imaginary imaginary::Answer = a;

imaginary::imaginary(double a,double b)
{
    x = a;
    y = b;
}

imaginary::~imaginary()
{
}

int main()
{
    imaginary A(3,4), B(5,6);
    cout << "A=3+4i,B=5+6i" << endl;
    cout << "A+B=";
    add(A, B);
    A.show();
    cout << "A-B=";
    sub(A, B);
    A.show();
    cout << "A*B=";
    mul(A, B);
    A.show();
    cout << "A/B=";
    div(A, B);
    A.show();
}