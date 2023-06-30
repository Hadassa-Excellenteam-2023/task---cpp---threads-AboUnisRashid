#ifndef PRODUCER_H
#define PRODUCER_H

#include <thread>
#include <mutex>
#include <condition_variable>

/**
 * The Producer class represents a producer that generates values.
 * Each producer runs in its own thread.
 */
class Producer {
private:
    std::thread::id threadId;
    double value;

public:
    /**
     * Constructs a Producer object with the given thread ID and value.
     *
     * @param id   The ID of the thread associated with the producer.
     * @param val  The initial value for the producer.
     */
    Producer(std::thread::id id, double val);

    /**
     * Runs the producer, generating values and performing actions based on them.
     * The producer continues generating values until the value becomes zero.
     * Once the value becomes zero, it signals completion and waits for other producers to finish.
     */
    void run();
};

#endif // PRODUCER_H
