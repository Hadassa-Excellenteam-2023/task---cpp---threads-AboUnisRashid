#include "Producer.h"
#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

/**
 * The main function of the program.
 *
 * It creates producer threads to generate values using the Producer class,
 * and a consumer thread that remains detached.
 *
 * @return 0 on successful execution.
 */
int main() {
    std::vector<double> values = {28312, 38348, 99341};
    std::vector<std::future<void>> producerFutures;      // Store futures of producer threads
    std::thread consumer([]() {});

    // Create producer threads for each value
    for (int i = 0; i < 3; ++i) {
        std::thread::id id = std::this_thread::get_id();
        // Lambda function to create a producer and run it with the given value
        auto producerFunc = [id](double val) {
            Producer producer(id, val);
            producer.run();
        };
        // Create producer threads for each value and store their futures
        for (const auto& val : values) {
            producerFutures.emplace_back(std::async(std::launch::async, producerFunc, val));
        }
    }

    consumer.detach();

    // Wait for each producer thread to finish and handle exceptions
    std::for_each(producerFutures.begin(), producerFutures.end(), [](std::future<void>& producerFuture) {
        try {
            producerFuture.get();
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    });

    return 0;
}
