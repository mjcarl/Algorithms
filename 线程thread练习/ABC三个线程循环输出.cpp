#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include<iostream>
using namespace std;

std::mutex mtx;
std::condition_variable cv;

int p = 0; char a;
void shuchu(int x)
{
	for (int i = 0; i < 10; i++)
	{
		unique_lock<mutex> lck(mtx);
		while (p % 3 != x)   //一定要用循环判断，若是if多个阻塞线程唤醒后同时处于临界区
		{
			cv.wait(lck);
		}
		a = 'A';  a += x;
		cout << a << " " ;
		p = (p + 1) % 3;
		cv.notify_all();
	}
	
}

int main()
{
	thread th0(shuchu, 0);
	thread th1(shuchu, 1);
	shuchu(2);

	cout << endl;
	th0.join();
	th1.join();

	return 0;
}