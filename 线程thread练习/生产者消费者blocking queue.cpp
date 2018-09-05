#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<array>
#include<boost/circular_buffer.hpp>
using namespace std;
mutex m;
condition_variable full,empty;
boost::circular_buffer<int> Q(10);// ��������СΪ10,����������Ϊint������䵱blocking queue

bool flag=true;//һ����ª����ƣ�����������ʱ����flag��ֹ�������߳�
void put(int x){
    for(int i=0;i<x;i++){
        unique_lock<mutex> lk(m);
        while(Q.full())
            empty.wait(lk);  //�ȴ�������ȡ����ź�
        assert(!Q.full());
        Q.push_back(i);
        cout<<"@ "<<i<<endl;//����
        full.notify_all();
    }
    flag=false;
}
void take(){
    while(flag){
        unique_lock<mutex> lk(m);
        while(Q.empty())
            full.wait(lk);   //�ȴ������߷�����ź�
        if(flag){
            assert(!Q.empty());
            cout<<"# "<<Q.front()<<endl;//����
            Q.pop_front();
            empty.notify_all();
        }
    }
}
int main(){
    thread one(take);
    thread two(take);
    thread three(take);
    put(100);
    one.join();
    two.join();
    three.join();
    return 0;
}
