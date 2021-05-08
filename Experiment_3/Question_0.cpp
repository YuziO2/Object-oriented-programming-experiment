/*实验：编写一个人员信息管理系统。这个系统的功能是：交互式的实现校园人员信息的录入与显示。
分析：
学校里，主要有四类人员：大学本科学生、教师、研究生和助教。
大学本科生每周有固定的学时数。教师除了固定的学时数外，还有每周的教学时数。
研究生除了固定的学时数外，每周还可以自由做一定的研究。助教生除了上课外，还要做研究和一定的教学工作。
人员的基本信息包括姓名、编号、性别、身份证号、总学时数以及每周固定学时数。
各个人员之间的关系： people类派生出student 类和teacher类，student 类派生出graduate类， graduate类和teacher类派生出TA类。*/
#include<iostream>
#include<string>
using namespace std;
class people
{
public:
    people();
    ~people(){}
    void basic_enter(int &n);
    void show();
protected:
    string name;
    int number;
    bool sex;
    long int id;
    int total_study_time, static_study_time;
};

people::people()
{
    int a = 0;
    bool b = 0;
    string c = "0";
    name = c;
    number = a;
    sex = b;
    id = a;
    total_study_time = a;
    static_study_time = a;
}

void people::basic_enter(int &n)
{
    cout << "Please enter the name,number,sex(0 for woman ,1 for man) and id :" << endl;
    cin >> name >> number >> sex >> id;
    n = number;
}

void people::show()
{
    cout << endl << "Name: " << name << " Number: " << number << " Sex: ";
    if (sex)
        cout << "male ";
    else
        cout << "female ";
    cout << "ID: " << id << endl;
    cout << "The total study time is " << total_study_time << " hour(s)" << endl;
    cout << "The weekly fixed study time is " << static_study_time << " hour(s)" << endl;
}

class student : virtual public people
{
public:
    student(){}
    ~student(){}
    void student_enter(int &n) { basic_enter(n) ;cout << "Please enter this student's study time :";cin >> study_time;}
    void calculate()
    {
        total_study_time = study_time;
        static_study_time = study_time;
    }

protected:
    int study_time;
};

class teacher : virtual public people
{
public:
    void teacher_enter(int &n)
    {
        basic_enter(n);
        cout << "Please enter this teacher's study time :";
        cin >> teacher_study_time;
        cout << "Please enter this teacher's teach time :";
        cin >> teach_time;
    }
    void calculate()
    {
        total_study_time = teacher_study_time+teach_time;
        static_study_time = teacher_study_time+teach_time;
    }

protected:
    int teach_time, teacher_study_time;
};

class graduate : virtual public student
{
public:
    void graduate_enter(int &n) 
    { 
        student_enter(n);
        cout << "Please enter this student's extra research time :";
        cin >> extra_research;
    }
    void calculate()
    {
        total_study_time = study_time + extra_research;
        static_study_time = study_time;
    }

protected:
    int extra_research;
};

class TA : public graduate, public teacher
{
public:
    void TA_enter(int &n)
    {
        graduate_enter(n);
        cout << "Please enter this TA's teach time :";
        cin >> teach_time;
    }
    void calculate()
    {
        total_study_time = study_time + teach_time + extra_research;
        static_study_time = study_time;
    }

private:
};

int main()
{
    people *p[65535],*display,*enter;
    student student;
    teacher teacher;
    graduate graduate;
    TA TA;
    cout << "Welcome to the Campus personnel information management system！" << endl;
    int chooser, n;
    while (1)
    {
        cout << "Enter 1 to input information, enter 2 to query information" << endl;
        cin >> chooser;
        if (chooser == 1)
        {
            cout << "Please select the type of people: 1.student 2.teacher 3.graduate 4.TA  :";
            cin >> chooser;
            switch (chooser)
            {
            case 1:
                student.student_enter(n);
                student.calculate();
                p[n] = &student;
                break;
            case 2:
                teacher.teacher_enter(n);
                teacher.calculate();
                p[n] = &teacher;
                break;
            case 3:
                graduate.graduate_enter(n);
                graduate.calculate();
                p[n] = &graduate;
                break;
            case 4:
                TA.TA_enter(n);
                TA.calculate();
                p[n] = &TA;
                break;
            default:
                cout << "Wrong input!! Please enter 1,2,3 or 4 !!" << endl;
                break;
            }
        }
        else
        {
            if (chooser==2)
            {
                cout << "Please enter the number of the person who you want to query : ";
                cin >> n;
                p[n]->show();
            }
            else
            {
                cout << "Wrong input!! Please enter 1 or 2!!" << endl;
            }
            
        }
        cout << "Enter 0 to quit, 1 to continue : ";
        cin >> chooser;
        if (chooser==0)
        {
            return 0;
        }
        }
}