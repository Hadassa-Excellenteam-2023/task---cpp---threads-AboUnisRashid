#include "Producer.h"
#include <iostream>

std::mutex mtx;
std::condition_variable cv;
bool finished = false;

/**
 * Constructs a Producer object with the given thread ID and value.
 *
 * @param id   The ID of the thread associated with the producer.
 * @param val  The initial value for the producer.
 */
Producer::Producer(std::thread::id id, double val) : threadId(id), value(val) {}

/**
 * Runs the producer, generating values and printing them to the console.
 * Once the value becomes zero, it signals completion and waits for other producers to finish.
 */
void Producer::run() {
    std::unique_lock<std::mutex> lock(mtx);  // Acquire the unique lock on the mutex
    while (value != 0) {
        std::cout << std::hash<std::thread::id>{}(threadId) << " sent: " << value << std::endl;
        value /= 10;
    }
    std::cout << std::hash<std::thread::id>{}(threadId) << " finished" << std::endl;

    if (finished) {
        cv.notify_one();         // Notify one waiting thread (if any) that producers have finished
    } else {
        finished = true;
        cv.wait(lock, [] { return finished; });  // Wait until the finished flag is set by another thread
        cv.notify_one();         // Notify one waiting thread (if any) that all producers have finished
    }
}
