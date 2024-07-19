#include <iostream>
#include <future>
#include <thread>

template<typename F>
auto async_deferred(F&& func) -> std::future<decltype(func())> {
    auto task = std::packaged_task<decltype(func())()>(std::forward<F>(func));
    auto future = task.get_future();
    std::thread(std::move(task)).detach();
    return std::move(future);
}

int main() {
    auto future = async_deferred([] { 
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 42; 
    });
    
    // Do other work here...
    
    std::cout << "Result: " << future.get() << std::endl; // Will wait until the task is done
    return 0;
}

