//
// Created by Nidzhat on 21.04.2020.
//VER 1.2
#include "lab3.h"
#include <windows.h>
#include <stdio.h>

#define MAX_SEM_COUNT 13
#define MAX_THREAD_COUNT 12

HANDLE mutex;
HANDLE Thread_list[MAX_THREAD_COUNT];
HANDLE semC, semB, semE, semG, semD, semF, semH, semK, semP, semM, semN;
HANDLE semB1, semD1, semF1, semK1, semM1;



unsigned int lab3_thread_graph_id()
{
    return 1;
}

const char* lab3_unsynchronized_threads()
{
    return "bcdf";
}

const char* lab3_sequential_threads()
{
    return "bkgm";
}

volatile int n;

void sem_wait (HANDLE sem){
    WaitForSingleObject(sem, INFINITE);
}

void sem_post (HANDLE sem){
    ReleaseSemaphore(sem, 1, NULL);
}
void mutex_lock(HANDLE mutx){
    WaitForSingleObject(mutx, INFINITE);
}
void mutex_unlock(HANDLE mutx){
    ReleaseMutex(mutx);
}
void wait_thread(HANDLE thr){
    WaitForSingleObject(thr, INFINITE);
}


DWORD WINAPI thread_a(LPVOID iNum)
{
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "a" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_c(LPVOID iNum)
{
    sem_wait(semC);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "c" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}

DWORD WINAPI thread_g(LPVOID iNum)
{
    sem_wait(semG);
    for (int i = 0; i < 3; ++i) {
        sem_wait(semG);
        mutex_lock(mutex);
        std::cout << "g" << std::flush;
        mutex_unlock(mutex);
        computation();
        sem_post(semM);
    };
    return 0;
}
DWORD WINAPI thread_b(LPVOID iNum)
{
    sem_wait(semB);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "b" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    sem_post(semB1);
    sem_wait(semB);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "b" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    sem_post(semB1);
    sem_wait(semB);
    sem_post(semB);
    for (int i = 0; i < 3; ++i) {
        sem_wait(semB);
        mutex_lock(mutex);
        std::cout << "b" << std::flush;
        mutex_unlock(mutex);
        computation();
        sem_post(semK);
    };
    sem_post(semB1);
    sem_wait(semB);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "b" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    sem_post(semB1);
    sem_wait(semB);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "b" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_f(LPVOID iNum)
{
    sem_wait(semF);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "f" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    sem_post(semF1);
    sem_wait(semF);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "f" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_d(LPVOID iNum)
{
    sem_wait(semD);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "d" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    sem_post(semD1);
    sem_wait(semD);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "d" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_h(LPVOID iNum)
{
    sem_wait(semH);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "h" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_k(LPVOID iNum)
{
    sem_wait(semK);
    for (int i = 0; i < 3; ++i) {
        sem_wait(semK);
        mutex_lock(mutex);
        std::cout << "k" << std::flush;
        mutex_unlock(mutex);
        computation();
        sem_post(semG);
    };
    sem_post(semK1);
    sem_wait(semK);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "k" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_m(LPVOID iNum)
{
    sem_wait(semM);
    for (int i = 0; i < 3; ++i) {
        sem_wait(semM);
        mutex_lock(mutex);
        std::cout << "m" << std::flush;
        mutex_unlock(mutex);
        computation();
        if(i<2){
            sem_post(semB);
        }
    };
    sem_post(semM1);
    sem_wait(semM);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "m" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_n(LPVOID iNum)
{
    sem_wait(semN);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "n" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_p(LPVOID iNum)
{
    sem_wait(semP);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "p" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
DWORD WINAPI thread_e(LPVOID iNum)
{
    sem_wait(semE);
    for (int i = 0; i < 3; ++i) {
        mutex_lock(mutex);
        std::cout << "e" << std::flush;
        mutex_unlock(mutex);
        computation();
    };
    return 0;
}
int lab3_init()
{
    DWORD IDThread;

    semC = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semB = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semB1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semE = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semG = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semD = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semD1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semF = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semF1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semH = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semK = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semK1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semM = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semM1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semN = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
    semP = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);

    Thread_list[0] = CreateThread(NULL, 0, thread_a, 0, 0, &IDThread);
    if (Thread_list[0] == NULL)
        return GetLastError();
    Thread_list[1] = CreateThread(NULL, 0, thread_c, 0, 0, &IDThread);
    if (Thread_list[1] == NULL)
        return GetLastError();
    Thread_list[2] = CreateThread(NULL, 0, thread_g, 0, 0, &IDThread);
    if (Thread_list[2] == NULL)
        return GetLastError();
    Thread_list[3] = CreateThread(NULL, 0, thread_b, 0, 0, &IDThread);
    if (Thread_list[3] == NULL)
        return GetLastError();
    Thread_list[4] = CreateThread(NULL, 0, thread_f, 0, 0, &IDThread);
    if (Thread_list[4] == NULL)
        return GetLastError();
    Thread_list[5] = CreateThread(NULL, 0, thread_d, 0, 0, &IDThread);
    if (Thread_list[5] == NULL)
        return GetLastError();
    Thread_list[6] = CreateThread(NULL, 0, thread_h, 0, 0, &IDThread);
    if (Thread_list[6] == NULL)
        return GetLastError();
    Thread_list[7] = CreateThread(NULL, 0, thread_k, 0, 0, &IDThread);
    if (Thread_list[7] == NULL)
        return GetLastError();
    Thread_list[8] = CreateThread(NULL, 0, thread_m, 0, 0, &IDThread);
    if (Thread_list[8] == NULL)
        return GetLastError();
    Thread_list[9] = CreateThread(NULL, 0, thread_n, 0, 0, &IDThread);
    if (Thread_list[9] == NULL)
        return GetLastError();
    Thread_list[10] = CreateThread(NULL, 0, thread_p, 0, 0, &IDThread);
    if (Thread_list[10] == NULL)
        return GetLastError();
    Thread_list[11] = CreateThread(NULL, 0, thread_e, 0, 0, &IDThread);
    if (Thread_list[11] == NULL)
        return GetLastError();

    //-------------------------
    wait_thread(Thread_list[0]);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semC);
    sem_post(semD);

    sem_wait(semB1);
    sem_wait(semF1);
    sem_wait(semD1);
    wait_thread(Thread_list[1]);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semD);
    sem_post(semE);

    sem_wait(semB1);
    wait_thread(Thread_list[11]);
    wait_thread(Thread_list[4]);
    wait_thread(Thread_list[5]);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semG);
    sem_post(semM);


    sem_wait(semB1);
    sem_wait(semK1);
    sem_wait(semM1);
    wait_thread(Thread_list[2]);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semM);
    sem_post(semH);

    sem_wait(semB1);
    wait_thread(Thread_list[7]);
    wait_thread(Thread_list[8]);
    wait_thread(Thread_list[6]);
    //-------------------------
    sem_post(semB);
    sem_post(semN);

    wait_thread(Thread_list[3]);
    wait_thread(Thread_list[9]);
    //-------------------------
    sem_post(semP);
    wait_thread(Thread_list[10]);


//    Close sem
    CloseHandle(semC);
    CloseHandle(semB);
    CloseHandle(semB1);
    CloseHandle(semE);
    CloseHandle(semG);
    CloseHandle(semD);
    CloseHandle(semD1);
    CloseHandle(semF);
    CloseHandle(semF1);
    CloseHandle(semH);
    CloseHandle(semK);
    CloseHandle(semK1);
    CloseHandle(semM);
    CloseHandle(semM1);
    CloseHandle(semN);
    CloseHandle(semP);

    //close thread
    for (int i= 0; i <  MAX_THREAD_COUNT; i++){
        CloseHandle(Thread_list[i]);
    }

    //close mutex
    CloseHandle(mutex);
//	system("pause");
    return 0;
}