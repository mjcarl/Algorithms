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
	//��ͨ�����๹�캯����д��
	Derived(int b, int d) : Base(b), m_d(d)
	{ }
private:
	int m_d;
};

//��̳У����������
class Derivedd : public Base1, public Base2  //============================
{
public:
	Derivedd(int b, int b1, int b2, int d) : Base(b), Base1(b, b1), Base2(b, b2), m_d(d)  //��ҪдBase�࣬��̳е�Base1����������
	{ //ע��ð���﷨�����˳������ν����������ǰ�������ļ̳�����˳�������е�...
	}
private:
	int m_d;
};