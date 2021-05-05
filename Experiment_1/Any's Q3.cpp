//任务（3）
#include<iostream>
using namespace std;
class imaginary
{
private:
	int x;
	int y;
public:
	imaginary(int,int);
	friend void add(imaginary&a,imaginary&b);
	friend void sub(imaginary&a,imaginary&b);
	friend void mul(imaginary& a, imaginary& b);
	friend void div(imaginary& a, imaginary& b);
};
imaginary::imaginary(int a, int b)
{
	x = a;
	y = b;
}
void add(imaginary& a, imaginary& b)
{
	int A = a.x + b.x;
	int B = a.y + b.y;
	cout << "相加的结果是：" << "\n";
	cout << A << "i+" << B<<"\n";
}
void sub(imaginary& a, imaginary& b)
{
	int A = a.x - b.x;
	int B = a.y - b.y;
	cout << "相减的结果是：" << "\n";
	cout << A << "i+" << B << "\n";
}
void mul(imaginary& a, imaginary& b)
{
	int A = a.y * b.x + a.x * b.y;
	int B = a.x * b.x - a.y * b.y;
	cout << "相乘的结果是：" << "\n";
	cout << A << "i+" << B << "\n";
}
void div(imaginary& a, imaginary& b)
{
	int A = a.y * b.x - a.x * b.y / b.x * b.x + b.y + b.y;
	int B = a.x * b.x + a.y * b.y / b.x * b.x + b.y * b.y;
	cout << "相除的结果是：" << "\n";
	cout << A << "i+" << B << "\n";
}
int main()
{
	int c, d,e,f;
	cout << "请输入第一个数的实部与虚部：" << "\n";
	cin >> c >> d;
	cout << "\n";
	cout << "请输入第二个数的实部与虚部：" << "\n";
	cin >> e >> f;
	cout << "\n";
	imaginary A(c, d), B(e, f);
	add(A, B);
	sub(A, B);
	mul(A, B);
	div(A, B);
        return 0;
}