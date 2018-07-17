#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;

//在 lock_guard 对象构造时，传入的 Mutex 对象(即它所管理的 Mutex 对象)会被当前线程锁住。
//在lock_guard 对象被析构时，它所管理的 Mutex 对象会自动解锁，由于不需要程序员手动调用 lock 和 unlock 对 Mutex 进行上锁和解锁操作，
//因此这也是最简单安全的上锁和解锁方式，尤其是在程序抛出异常后先前已被上锁的 Mutex 对象可以正确进行解锁操作，极大地简化了程序员编写与 Mutex 相关的异常处理代码。

int cnt = 20;
mutex m;
void t1()
{
	while (cnt > 0)
	{
		lock_guard<mutex> lockGuard(m);   //C++11 中定义的模板类. 这个功能在函数体比较长，尤其是存在多个分支的时候很有用。 
		if (cnt > 0)
		{
			--cnt;
			cout << cnt << endl;
		}
	}
}
void t2()
{
	while (cnt > 0)
	{
		lock_guard<mutex> lockGuard(m);
		if (cnt > 0)
		{
			--cnt;
			cout << cnt << endl;
		}
	}
}

int main()
{

	thread th1(t1);
	thread th2(t2);

	th1.join();
	th2.join();

	return 0;
}