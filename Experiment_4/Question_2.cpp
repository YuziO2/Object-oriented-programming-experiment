#include<iostream>
using namespace std;

template<typename T>
class maxer
{
private:
    T *a;
    int n;
public:
    maxer(int n)
    {
        a = new T[n];
        this->n = n;
    }
    ~maxer()
    {
        delete a;
    }
    void input()
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    T sum()
    {
        T Sum = 0;
        for (int i = 0; i < n; i++)
        {
            Sum = Sum + a[i];
        }
        return Sum;
    }

    T ave()
    {
        return sum() / n;
    }

    void show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }

};

int main()
{
    maxer<int> A(5);
    A.input();
    cout << A.ave() << endl;
    cout << A.sum() << endl;
    A.show();
    maxer<double> B(2);
    B.input();
    cout << B.ave() << endl;
    cout << B.sum() << endl;
    B.show();
}