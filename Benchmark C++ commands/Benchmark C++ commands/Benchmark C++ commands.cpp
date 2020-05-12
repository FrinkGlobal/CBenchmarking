// Benchmark C++ commands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <atomic>
#include <future>

#include "Stopwatch.h"

#include <thread>
#include <mutex>          // std::mutex
#include <queue>
#include <functional>

#include "concurrentqueue.h"

std::mutex mtx;           // mutex for critical section

std::thread* m_thread;
std::mutex m_mutex;

//moodycamel::ConcurrentQueue<std::function<int()>> fncQueue;



int doNothing() {
    int i = 0;
    return i;
}

void testGoTo(int runs) {
    int i = 0;
start:
    if (i++ == runs)
        goto exit;
    goto start;
exit:
    return;
}

//typedef void (*varArgFnc)(...);
//
//varArgFnc functionLookupTable[1000];
//
//int vArgFnc(...) {
//    int i = 0;
//    return i;
//}
//
//void doZeroArg(...) {
//
//}
//
//void addFunctionsToLookupTable() {
//    functionLookupTable[0] = doZeroArg;
//}

const int ThreadMsgs = 1000000;
moodycamel::ConcurrentQueue<int> msgQueue;
void recieveMsgs() {
    Stopwatch sw;
    sw.start();
    int front;
    for (int i = 0; i < ThreadMsgs; ) {
        if (msgQueue.try_dequeue(front)) {
            i++;
        }
    }
    sw.stop();

    double Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;

    std::cout << "recieving thread messages took " << Cost << " us.\n" << std::endl;
}

std::queue<int> standardQueue;
void recieveMsgs_CQueue() {
    Stopwatch sw;
    sw.start();
    int front;
    for (int i = 0; i < ThreadMsgs; ) {
        if (!standardQueue.empty()) {
            std::lock_guard<std::mutex> lck(mtx);
            front = standardQueue.front();
            standardQueue.pop();
            i++;
        }
    }
    sw.stop();

    double Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;

    std::cout << "recieving thread messages from c-queue plus lock took " << Cost << " us.\n" << std::endl;
}

//void callFncInThread() {
//    Stopwatch sw;
//    sw.start();
//
//    //std::function<int()>
//    varArgFnc fnc;
//    for (int i = 0; i < ThreadMsgs; ) {
//        if (msgQueue.try_dequeue(fnc)) {
//            fnc();
//            i++;
//        }
//    }
//    sw.stop();
//
//    double Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;
//
//    std::cout << "calling custom async functions took " << Cost << " us.\n" << std::endl;
//}


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

    double forLoopCost = (double)sw.get_total_time_microseconds()/(double)forRuns;

    std::cout << "for took " << forLoopCost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////

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
    int k=0;
    sw.restart();
    for (int i = 0; i < assignRuns; i++) {
        k++;
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = sw.get_elapsed_time_microseconds() - forLoopCost;

    std::cout << "increment took " << Cost / assignRuns << " us.\n" << std::endl;

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
    const int malloc_runs = 20000;
    std::shared_ptr<int> shared_ptr_int;
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        shared_ptr_int = std::make_shared<int>(1000);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "shared_ptr_array loop took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<int> unique_ptr_int;
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        unique_ptr_int = std::make_unique<int>(1000);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "unique_ptr loop took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    int* malloc_me[malloc_runs];
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        malloc_me[i] = (int *)malloc(4000);
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
        malloc_me[i] = (int *)malloc(1000);
        free(malloc_me[i]);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "malloc-free loop took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        malloc_me[i] = (int*)_malloca(4000);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "alloca took " << Cost / malloc_runs << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        malloc_me[i] = (int*)malloc(1000);
        *malloc_me[i] = rand() * RAND_MAX;
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "fill array with rands took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
    int* memcopy_to_me[malloc_runs];

    sw.restart();
    for (int i = 0; i < malloc_runs; i++) {
        memcopy_to_me[i] = (int*)malloc(1000);
        memcpy(memcopy_to_me[i], malloc_me[i], 1000);
    }
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)malloc_runs - forLoopCost;

    std::cout << "memcpy array rands took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////

    //spawn recieving thread

    //send messages
    sw.restart();
    int msg = 5;
    for (int i = 0; i < ThreadMsgs; i++) {
        msgQueue.enqueue(msg);
        /*if (!msgQueue.try_enqueue(msg)) {
            i--;
        }*/
    }
    sw.stop();

    Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;

    std::cout << "sending thread messages took " << Cost << " us.\n" << std::endl;

    std::thread RunMsgThread(recieveMsgs);
    RunMsgThread.join();

    ///////////////////////////////////////////////////////////////////////////////////
    //spawn recieving thread

//send messages
    sw.restart();
    for (int i = 0; i < ThreadMsgs; i++) {
        std::lock_guard<std::mutex> lck(mtx);
        standardQueue.push(msg);
    }
    sw.stop();

    Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;

    std::cout << "sending thread messages from c-queue plus lock took " << Cost << " us.\n" << std::endl;

    std::thread RunMsgThread_Cstyle(recieveMsgs_CQueue);
    RunMsgThread_Cstyle.join();

    ///////////////////////////////////////////////////////////////////////////////////

    int lockRuns = 100000000;

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

    int gotoRuns = 1000000000;
    sw.restart();
    testGoTo(gotoRuns);
    sw.stop();

    //sw.print_elapsed_us("add");
    Cost = (double)sw.get_elapsed_time_microseconds() / (double)gotoRuns;
    std::cout << "goto took " << Cost << " us.\n" << std::endl;

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

    ///////////////////////////////////////////////////////////////////////////////////

    ////spawn recieving thread
    //std::thread RunFncThread(callFncInThread);

    ////call functions
    //sw.restart();
    //for (int i = 0; i < ThreadMsgs; i++) {
    //    varArgFnc fnc = vArgFnc;

    //    fncQueue.enqueue(fnc);
    //}
    //sw.stop();

    //RunFncThread.join();

    //Cost = (double)sw.get_total_time_microseconds() / (double)ThreadMsgs;

    //std::cout << "fast async took " << Cost << " us.\n" << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////
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
