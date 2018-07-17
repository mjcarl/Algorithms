#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>    //ͷ�ļ���<mutex>��mutex��������֤�߳�ͬ���ģ���ֹ��ͬ���߳�ͬʱ����ͬһ���������ݡ�
                    //����ʹ��mutex�ǲ���ȫ�ģ���һ���߳��ڽ���֮ǰ�쳣�˳��ˣ���ô�������������߳̾��޷�������ȥ��

using namespace std;

mutex mu;  //�̻߳������

int totalNum = 100;

void thread01()
{
	while (totalNum > 0)
	{
		mu.lock(); //ͬ��������
		cout << "01 = " << totalNum << endl;
		totalNum--;
		Sleep(100);
		mu.unlock();  //�������
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