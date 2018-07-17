#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>    //头文件是<mutex>，mutex是用来保证线程同步的，防止不同的线程同时操作同一个共享数据。
                    //但是使用mutex是不安全的，当一个线程在解锁之前异常退出了，那么其它被阻塞的线程就无法继续下去。

using namespace std;

mutex mu;  //线程互斥对象

int totalNum = 100;

void thread01()
{
	while (totalNum > 0)
	{
		mu.lock(); //同步数据锁
		cout << "01 = " << totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();  //解除锁定
	}
}
void thread02()
{
	while (totalNum > 0)
	{
		mu.lock();
		cout <<"02 = "<< totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();
	}
}

int main()
{
	thread task01(thread01);
	thread task02(thread02);
	task01.detach();
	task02.detach();
	system("pause");
}