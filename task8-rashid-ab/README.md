# Producer-Consumer Example

This project demonstrates a simple producer-consumer pattern using threads and futures in C++.
It includes a `Producer` class that generates values and a consumer thread that processes the generated values.

## Features

- Multiple producers generate values concurrently.
- The generated values are printed to the console.
- The consumer thread waits for the producers to finish before exiting.

## Requirements

- C++ compiler with C++11 support
- CMake (optional, for building the project)

## Build and Run

Follow these steps to build and run the project:

1. Clone the repository or download the source code files.
2. Navigate to the project directory in your terminal.

### Using CMake (Recommended)

3. Create a build directory: `mkdir build`
4. Navigate to the build directory: `cd build`
5. Generate the build files: `cmake ..`
6. Build the project: `cmake --build .`
7. Run the executable: `./ProducerConsumer`

### Manual Compilation

3. Compile the source files: `g++ -std=c++11 main.cpp Producer.cpp -o ProducerConsumer`
4. Run the executable: `./ProducerConsumer`







