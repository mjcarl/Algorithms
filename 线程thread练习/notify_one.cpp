#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <cstdint>
#include <stdexcept>
#include <limits>
#include <utility> 
#include <mutex> 
#include <future>
#include <condition_variable>    
using namespace std;

std::mutex mtx;
std::condition_variable cv;

int cargo = 0; // shared value by producers and consumers

void consumer()
{
	std::unique_lock < std::mutex > lck(mtx);
	while (cargo == 0)
		cv.wait(lck);   //等cv.notify_one()后，判断条件，结束阻塞
	std::cout <<"consumer=="<< cargo << "  th_id_c = " << std::this_thread::get_id() << '\n';   //std::this_thread::get_id(),获取当前线程的线程id。
	cargo = 0;
}

void producer(int id)
{
	std::unique_lock < std::mutex > lck(mtx);
	cargo = id;

	std::cout << "producer==" << id <<"  th_id_p = "<< std::this_thread::get_id() << std::endl;
	cv.notify_one();
	
}

int main()
{
	std::thread consumers[10], producers[10];

	// spawn 10 consumers and 10 producers:
	for (int i = 0; i < 10; ++i) {
		consumers[i] = std::thread(consumer);
		producers[i] = std::thread(producer, i + 1);
	}

	// join them back:
	for (int i = 0; i < 10; ++i) {
		producers[i].join();
		consumers[i].join();
	}

	return 0;
}