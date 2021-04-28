/*题目：定义一个结构体score，结构体内的成员为：
num          学号
Math           高等数学成绩
English           英语成绩
定义两个函数：
inscore()        输入学号和各科成绩. 
showscore()   输出学号，各科成绩及每个学生的平均成绩。
函数的参数及返回值自己设定。

使用结构体score，输入某班n（事先不能确定）个学生的学号和各科成绩，然后求各个学生的平均成绩（调用inscore函数实现），
并输出学生的学号、各科成绩和每个学生的平均成绩（调用showscore函数实现）。*/
#include<iostream>
using namespace std;

struct score
{
    int num;
    double Math, English;
};

void inscore(score &a)
{
    cout << "Please input num,math score,english score" << endl;
    cin >> a.num >> a.Math >> a.English;
    cout << "The average score of this student is :" << (a.Math + a.English) / 2 << endl;
}

void showscore(score a)
{
    cout << "The num,math score,english score of this student is " << a.num << " " << a.Math << " " << a.English << endl;
    cout << "The average score of this student is :" << (a.Math + a.English) / 2 << endl;
}

int main()
{
    int n;
    cout << "Plsase input the number of students:";
    cin >> n;
    score *p;
    p = new score[n];
    for (int i = 0; i < n; i++)
    {
        inscore(p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        showscore(p[i]);
    }
    return 0;
}