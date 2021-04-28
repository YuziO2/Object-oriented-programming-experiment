/*题目：定义一个score类，其中包括私有数据成员和公有成员函数，即
num          学号
Math           高等数学成绩
English           英语成绩
Programming    程序设计成绩
inscore()        输入学号和各科成绩，并且计算平均成绩
showscore()   输出学号和各科成绩
使用score类，输入某班n（事先不能确定）个学生的学号和各科成绩，
然后求各个学生的平均成绩，并输出所有学生的学号、各科成绩和平均成绩。*/
#include <iostream>
using namespace std;

class score
{
private:
    int num;
    double Math, English, Programming;
public:
    score(int,double);
    ~score();
    void inscore()
    {
        cout << "Please input num,math score,english score,programming score" << endl;
        cin >> num >> Math >> English >> Programming;
        cout << "The average score of this student is :" << (Math + English + Programming) / 3 << endl;
    }

    void showscore()
    {
        cout << "The num,math score,english score,programming score of this student is " << num << " " << Math << " " << English << " " << Programming << endl;
        cout << "The average score of this student is :" << (Math + English + Programming) / 3 << endl;
    }
};

score::score(int x=0,double y=0)
{
    num = x;
    Math = y;
    English = y;
    Programming = y;
}

score::~score()
{
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
        p[i].inscore();
    }
    for (int i = 0; i < n; i++)
    {
        p[i].showscore();
    }
}