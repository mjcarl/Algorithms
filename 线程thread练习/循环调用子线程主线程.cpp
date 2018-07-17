#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cond;   //std::condition_variable  ��������һ���߳�, ֱ���������.
int flag = 10;
void fun(int num) 
{
	for (int i = 0; i<5; i++) 
	{
		unique_lock<mutex> lok(m);   //A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
		while (flag != num)  //ifҲ�У�
		{
			cond.wait(lok);   //�ڵ���waitʱ��ִ��lok.unlock()   ������ǵȴ����ӽ���״̬.  ͨ�� notify_one(), notify_all()��α���ѽ����ȴ�
		}
			
		for (int j = 0; j<num; j++)
			cout << j << "  ";
		cout << endl;
		flag = (num == 10) ? 100 : 10;
		cond.notify_one();//���������̻߳��Ѻ�lok.lock()�ָ��ڵ���waitǰ��״̬
	}
}

int main() {
	thread child(fun, 10);   //���̴߳�ӡ10��
	fun(100);   //���̴߳�ӡ100��

	child.join();
	return 0;
}
