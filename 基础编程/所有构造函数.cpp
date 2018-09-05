#include<iostream>
#include<string>
using namespace std;


class Base
{
public:
    Base(int b) : m_b(b)
	{ }
private:
	int m_b;
};

class Derived : public Base  //===================
{
public:
	//普通派生类构造函数的写法
	Derived(int b, int d) : Base(b), m_d(d)
	{ }
private:
	int m_d;
};

//虚继承，避免二义性
class Derivedd : public Base1, public Base2  //============================
{
public:
	Derivedd(int b, int b1, int b2, int d) : Base(b), Base1(b, b1), Base2(b, b2), m_d(d)  //需要写Base类，虚继承的Base1有两个参数
	{ //注意冒号语法后面的顺序无所谓，创造基类是按照上面的继承声明顺序来进行的...
	}
private:
	int m_d;
};