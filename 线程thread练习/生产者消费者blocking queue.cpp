#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<array>
#include<boost/circular_buffer.hpp>
using namespace std;
mutex m;
condition_variable full,empty;
boost::circular_buffer<int> Q(10);// 缓冲区大小为10,缓冲区数据为int，这里充当blocking queue

bool flag=true;//一个简陋的设计，当不再生产时采用flag终止消费者线程
void put(int x){
    for(int i=0;i<x;i++){
        unique_lock<mutex> lk(m);
        while(Q.full())
            empty.wait(lk);  //等待消费者取完的信号
        assert(!Q.full());
        Q.push_back(i);
        cout<<"@ "<<i<<endl;//生产
        full.notify_all();
    }
    flag=false;
}
void take(){
    while(flag){
        unique_lock<mutex> lk(m);
        while(Q.empty())
            full.wait(lk);   //等待生产者放入的信号
        if(flag){
            assert(!Q.empty());
            cout<<"# "<<Q.front()<<endl;//消费
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
