#include <iostream>
#include <atomic>
#include <thread>
#include <condition_variable>

class PingPong
{
public:
	static constexpr std::size_t MAX = 3;

	void ping()
	{
		
    	std::unique_lock<std::mutex> lock(m_);
    	while (count_.load() < MAX)
    	{
			cv_.wait(lock, [this]{ return flag?true:false;});
        	std::cout << "Ping" << std::endl;
        	count_++;
        	flag = !flag;
        	cv_.notify_one();
    	}
 	}

	void pong()
	{
    	std::unique_lock<std::mutex> lock(m_);
    	while (count_.load() < MAX)
    	{
			cv_.wait(lock, [this]{ return flag?true:false;});
        	std::cout << "Pong" << std::endl;
        	count_++;
        	flag = !flag;
        	cv_.notify_one();
    	}
	}

private:
	std::atomic<std::size_t> count_ = 0;
	std::mutex m_;
	std::condition_variable cv_;
	bool flag = true;
};

int main()
{
	PingPong p;
	std::thread pingThread(&PingPong::ping, &p);
	std::thread pongThread(&PingPong::pong, &p);

	pingThread.join();
	pongThread.join();
}

