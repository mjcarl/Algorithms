#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
using namespace std;

//�� lock_guard ������ʱ������� Mutex ����(����������� Mutex ����)�ᱻ��ǰ�߳���ס��
//��lock_guard ��������ʱ����������� Mutex ������Զ����������ڲ���Ҫ����Ա�ֶ����� lock �� unlock �� Mutex ���������ͽ���������
//�����Ҳ����򵥰�ȫ�������ͽ�����ʽ���������ڳ����׳��쳣����ǰ�ѱ������� Mutex ���������ȷ���н�������������ؼ��˳���Ա��д�� Mutex ��ص��쳣������롣

int cnt = 20;
mutex m;
void t1()
{
	while (cnt > 0)
	{
		lock_guard<mutex> lockGuard(m);   //C++11 �ж����ģ����. ��������ں�����Ƚϳ��������Ǵ��ڶ����֧��ʱ������á� 
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