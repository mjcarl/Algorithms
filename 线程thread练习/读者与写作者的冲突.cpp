#include<iostream>
#include<mutex>
#include<thread>
#include<memory>
#include<vector>
#include<assert.h>
using namespace std;

mutex m;
shared_ptr<vector<int>> ptr;
int loop=100;

void read()   //����
{
    while(1)
    {
        {   //���ڿ��ڿ���ʹ��ʱ����õ���ʱ����
            shared_ptr<vector<int>> temp_ptr;
            {
                unique_lock<mutex> lk(m);  //������ߺͶ���֮�䣬���ߺ�д��֮�䶼���⣬�����ٽ�����С���Բ��õ��Ķ��ߺͶ��߼�Ļ���
                temp_ptr=ptr;   //�����ʹ��������ü�����1
                assert(!temp_ptr.unique());   //�����������ش�������ֹ����ִ�С����temp_ptr�ǵ����ģ�����ֹ��
            }
            for(auto it=temp_ptr->begin();it!=temp_ptr->end();it++)//�������д�ߣ���ô���߷��ʵ��Ǿɵ�vector
                cout<<*it<<" ";
        }
    }
}

void write()    //д��
{
    for(int i=0;;i++)
    {
        {//��һ������ʹ��ʱ����ʱ�õ�����
            unique_lock<mutex> lk(m);   //д�ߺ�д��֮�䣬д�ߺͶ���֮�䶼Ҫ����
            if(!ptr.unique())   //�����������д�߻���ߣ�����Ҫ������ǰ��vector
                ptr.reset(new vector<int>(*ptr));
            assert(ptr.unique());   //���ptr��Ψһ��˵�����ܻ��ж����ڷ���
            ptr->push_back(i);
        }
    }
}

int main()
{
    ptr.reset(new vector<int>);   //reset �����ڲ����󲢽����µĶ��������Ȩ(���ʹ��ȱʡ�����Ļ���Ҳ����û���κζ��������Ȩ, ��ʱ�����ڲ������ͷ�, ����Ϊ��)
    thread one(read);
    thread two(read);
    write();
    one.join();
    two.join();
    return 0;
}
