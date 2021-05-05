#include <iostream>
using namespace std;

class matrix
{
public:
    matrix(int, int);
    matrix(double **, int, int);
    matrix(const matrix &);
    ~matrix();
    friend matrix operator+(const matrix &, const matrix &);
    matrix &operator=(const matrix &);
    friend ostream &operator<<(ostream &output, const matrix &);
    friend istream &operator>>(istream &input, matrix &);

private:
    int m, n;
    double **a;
};

matrix::matrix(int m, int n)
{
    this->m = m;
    this->n = n;
    a = new double *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new double[n];
    }
}

matrix::matrix(const matrix &M)
{
    this->m = M.m;
    this->n = M.n;
    this->a = new double *[m];
    for (int i = 0; i < m; i++)
    {
        this->a[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            this->a[i][j] = M.a[i][j];
    }
}

matrix::matrix(double **T, int m, int n)
{
    this->m = m;
    this->n = n;
    a = T;
}

matrix::~matrix()
{
    for (int i = 0; i < m; i++)
    {
        if (a[i] != NULL)
        {
            delete[] a[i];
            a[i] = NULL;
        }
    }
    delete[] a;
    a = NULL;
}
matrix &matrix::operator=(const matrix &A)
{
    m = A.m;
    n = A.n;
    for (int i = 0; i < A.m; i++)
    {
        for (int k = 0; k < A.n; k++)
        {
            a[i][k] = A.a[i][k];
        }
    }
    return *this;
    // TODO: 在此处插入 return 语句
}

matrix operator+(const matrix &A, const matrix &B)
{
    matrix C(A.m, A.n);
    /*double** T;
	T = new double* [A.m];
	for (int i = 0; i < A.m; i++)
	{
		T[i] = new double[A.n];
	}*/
    for (int i = 0; i < A.m; i++)
    {
        for (int k = 0; k < A.n; k++)
        {
            C.a[i][k] = A.a[i][k] + B.a[i][k];
            //T[i][k] = A.a[i][k] + B.a[i][k];
        }
    }
    const matrix D = C;
    return D; //不能像注释部分这样写，因为一旦出了函数就会调用析构函数，就会导致赋值时出错！！！（找不到指针）
              //return matrix(T, A.m, A.n); //此处重载了构造函数
}

ostream &operator<<(ostream &output, const matrix &A)
{
    for (int i = 0; i < A.m; i++)
    {
        for (int k = 0; k < A.n; k++)
        {
            cout << A.a[i][k] << "  ";
        }
        cout << endl;
    }
    return output;
    // TODO: 在此处插入 return 语句
}

istream &operator>>(istream &input, matrix &A)
{

    for (int i = 0; i < A.m; i++)
    {
        for (int k = 0; k < A.n; k++)
        {
            cin >> A.a[i][k];
        }
    }
    return input;
    // TODO: 在此处插入 return 语句
}
int main()
{
    int m, n;
    cout << "enter m: ";
    cin >> m;
    cout << "enter n: ";
    cin >> n;
    matrix A(m, n);
    cout << "Please enter this " << m << " x " << n << " matrix" << endl;
    cin >> A;
    matrix B(m, n);
    cout << "Please enter this " << m << " x " << n << " matrix" << endl;
    cin >> B;
    cout << "C=A+B=" << endl;
    matrix C(m, n);
    C = (A + B);
    cout << (A + B) << endl;
}