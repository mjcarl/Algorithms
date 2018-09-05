#include <iostream>
#include <vector>
#include<string>
using namespace std;


class Base_A   //8 12 12 28
{
public:
	Base_A() :m_base_a(1) {}
	virtual ~Base_A() {}
	virtual void fun1() {}
private:
	int m_base_a;
};

class Derived_B : public Base_A
{
public:
	Derived_B() :m_derived_b(2) {}
	virtual ~Derived_B() {}
	virtual void fun2() {}
private:
	int m_derived_b;
};

class Derived_C : public Base_A
{
public:
	Derived_C() :m_derived_c(3) {}
	virtual~Derived_C() {}
	virtual void fun3() {}
private:
	int m_derived_c;
};

class Derived_D :public Derived_B, public Derived_C
{
public:
	Derived_D() :m_derived_d(4) {}
	virtual ~Derived_D() {}
	virtual void fun4() {}
private:
	int m_derived_d;
};

//------------------------------------------------------
class A {   //8 20 20 36
public:
	A() { printf("A create.\n"); }
	int a;
	virtual ~A() {};
	virtual void fun() {}
};

class B :virtual public A {
public:
	B() { printf("B create.\n"); }
	int b;
	virtual void fun1() {}
};

class C :virtual public A
{
public:
	int c;
	C() { printf("C create.\n"); }
	virtual void fun3() { printf("fun3 .\n"); }
};

class D :public C, public B {
public:
	int d;
	D() { printf("D create.\n"); }
	virtual void fun3() { printf("fun4 .\n"); }
};


int main() 
{
	//Derived_D D;
	//D.printA();

	cout << sizeof(Base_A) << endl;
	cout << sizeof(Derived_B) << endl;
	cout << sizeof(Derived_C) << endl;
	cout << sizeof(Derived_D) << endl;
	cout << "--------" << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(D) << endl;
	cout << "--------" << endl;
	//cout << sizeof(A1) << endl;
	return 0;
}