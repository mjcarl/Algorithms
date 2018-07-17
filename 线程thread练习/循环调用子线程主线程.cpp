#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cond;   //std::condition_variable  允许阻塞一个线程, 直到条件达成.
int flag = 10;
void fun(int num) 
{
	for (int i = 0; i<5; i++) 
	{
		unique_lock<mutex> lok(m);   //A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
		while (flag != num)  //if也行？
		{
			cond.wait(lok);   //在调用wait时会执行lok.unlock()   其参数是等待的子进程状态.  通过 notify_one(), notify_all()或伪唤醒结束等待
		}
			
		for (int j = 0; j<num; j++)
			cout << j << "  ";
		cout << endl;
		flag = (num == 10) ? 100 : 10;
		cond.notify_one();//被阻塞的线程唤醒后lok.lock()恢复在调用wait前的状态
	}
}

int main() {
	thread child(fun, 10);   //子线程打印10次
	fun(100);   //主线程打印100次

	child.join();
	return 0;
}
