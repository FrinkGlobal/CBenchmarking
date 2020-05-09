// Benchmark C++ commands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atomic>
#include <future>

#include "Stopwatch.h"

#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

int doNothing() {
    int i = 0;
    return i;
}

int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";

    Stopwatch sw;

    const int forRuns = 100000000;

    sw.start();
    for (int i = 0; i < forRuns; i++) {

    }
    sw.stop();

    sw.print_elapsed_us("for loop");
    double forLoopCost = (double)sw.get_total_time_microseconds()/(double)forRuns;

    std::cout << "for took " << forLoopCost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();

    const int assignRuns = 1000000000;

    for (int i = 0; i < assignRuns; i++) {
        int k = 0;
    }
    sw.stop();

    //sw.print_elapsed_us("int creation");
    double Cost = sw.get_elapsed_time_microseconds()/ assignRuns - forLoopCost;

    std::cout << "int creation took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < assignRuns; i++) {
        int k = 1 + 2;
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = sw.get_elapsed_time_microseconds() - forLoopCost;

    std::cout << "add took " << Cost / assignRuns << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    int l = 1;
    for (int i = 0; i < assignRuns; i++) {
        l = 5;
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = sw.get_elapsed_time_microseconds() - forLoopCost;

    std::cout << "int assignment took " << Cost / assignRuns << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    const int malloc_runs = 100000;
    void* malloc_me[malloc_runs];
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        malloc_me[i] = malloc(1000);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "malloc took " << Cost / malloc_runs << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        free(malloc_me[i]);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "free took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        malloc_me[i] = malloc(1000);
        free(malloc_me[i]);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "malloc-free loop took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    int lockRuns = 10000000;

    sw.restart();
    for (int i = 0; i < lockRuns; i++) {
        mtx.lock();
        mtx.unlock();
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds()/(double)lockRuns - forLoopCost;

    std::cout << "mtx.lock/unlock took " << Cost / lockRuns << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < lockRuns; i++) {
        std::lock_guard<std::mutex> lck(mtx);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)lockRuns - forLoopCost;

    std::cout << "lockguard took " << Cost / lockRuns << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    int functionCallRuns = 1000000;

    sw.restart();
    for (int i = 0; i < functionCallRuns; i++) {
        int j = doNothing();
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    double fncCost = (double)sw.get_elapsed_time_microseconds()/(double)functionCallRuns - forLoopCost;
    std::cout << "function call took " << fncCost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    int AsyncRuns = 10000;
    
    sw.restart();
    for (int i = 0; i < AsyncRuns; i++) {
        auto handleAsync = std::async(doNothing);
        handleAsync.get();
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds()/(double)AsyncRuns - fncCost;

    std::cout << "async took " << Cost << " us.\n" << std::endl;

    //sw.print_elapsed_us("for loop");

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
