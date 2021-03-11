/*
 * @Author: Payne
 * @Date: 2021-03-09 19:41:42
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-09 19:59:21
 * @Description: 
 */
#include<iostream>
#include<thread>
#include<mutex>
#include<string_view>


void fun(std::string_view a, std::mutex & lock) { 
	std::unique_lock<std::mutex> lock_guard(lock);
	std::cout << "thread id = " << std::this_thread::get_id() << "\t " << a << "\n"; 
};
int main()
{
	std::mutex g_display_mutex;
	auto fun = [](std::string_view a, std::mutex & lock) { 
		std::unique_lock<std::mutex> lock_guard(lock);
		std::cout << "thread id = " << std::this_thread::get_id() << "\t " << a << "\n"; 
	};
	std::thread t(fun,"hello", std::ref(g_display_mutex));
	fun("world", g_display_mutex);
	t.join();
	return 0;
}
