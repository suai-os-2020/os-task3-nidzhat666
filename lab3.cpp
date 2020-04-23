//
// Created by Nidzhat on 21.04.2020.
//VER 1.2
#include <windows.h>
#include "lab3.h"

#define MAX_SEM_COUNT 13

HANDLE mutex;
HANDLE thread_a1,thread_c1,thread_b1,thread_g1,thread_d1,thread_f1,thread_h1,thread_k1,thread_m1,thread_n1, thread_p1;
//HANDLE semA, semC, semB, semE, semG, semD, semF, semH, semK, semI, semM, semN;
//HANDLE semC1;

HANDLE semA = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semC = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semB = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semB1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semE = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semG = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semD = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semD1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semF = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semF1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semH = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semK = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semK1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semI = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semM = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semM1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semN = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
HANDLE semP = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);

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
        sem_post(semB);
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
int lab3_init()
{
    DWORD IDThread;
//    HANDLE semA = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semC = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semC1 = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semB = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semE = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semG = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semD = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semF = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semH = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semK = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semI = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semM = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);
//    HANDLE semN = CreateSemaphore(NULL,0, MAX_SEM_COUNT, NULL);

    thread_a1 = CreateThread(NULL, 0, thread_a, 0, 0, &IDThread);
    if (thread_a1 == NULL)
        return GetLastError();
    thread_c1 = CreateThread(NULL, 0, thread_c, 0, 0, &IDThread);
    if (thread_c1 == NULL)
        return GetLastError();
    thread_g1 = CreateThread(NULL, 0, thread_g, 0, 0, &IDThread);
    if (thread_g1 == NULL)
        return GetLastError();
    thread_b1 = CreateThread(NULL, 0, thread_b, 0, 0, &IDThread);
    if (thread_g1 == NULL)
        return GetLastError();
    thread_f1 = CreateThread(NULL, 0, thread_f, 0, 0, &IDThread);
    if (thread_f1 == NULL)
        return GetLastError();
    thread_d1 = CreateThread(NULL, 0, thread_d, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();
    thread_h1 = CreateThread(NULL, 0, thread_h, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();
    thread_k1 = CreateThread(NULL, 0, thread_k, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();
    thread_m1 = CreateThread(NULL, 0, thread_m, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();
    thread_n1 = CreateThread(NULL, 0, thread_n, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();
    thread_p1 = CreateThread(NULL, 0, thread_p, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();

    //-------------------------
    wait_thread(thread_a1);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semC);
    sem_post(semD);

    sem_wait(semB1);
    sem_wait(semF1);
    sem_wait(semD1);
    wait_thread(thread_c1);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semD);
    sem_post(semE);

    sem_wait(semB1);
    wait_thread(thread_c1);
    wait_thread(thread_f1);
    wait_thread(thread_d1);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semG);
    sem_post(semM);


    sem_wait(semB1);
    sem_wait(semK1);
    sem_wait(semM1);
    wait_thread(thread_g1);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semM);
    sem_post(semH);

    sem_wait(semB1);
    wait_thread(thread_k1);
    wait_thread(thread_m1);
    wait_thread(thread_h1);
    //-------------------------
    sem_post(semB);
    sem_post(semN);

    wait_thread(thread_b1);
    wait_thread(thread_n1);
    //-------------------------
    sem_post(semP);
    wait_thread(thread_p1);


//    Close sem
    CloseHandle(semA);
    CloseHandle(semC);
    CloseHandle(semB);
    CloseHandle(semE);
    CloseHandle(semG);
    CloseHandle(semD);
    CloseHandle(semF);
    CloseHandle(semH);
    CloseHandle(semK);
    CloseHandle(semK);
    CloseHandle(semI);
    CloseHandle(semM);
    CloseHandle(semN);


    return 0;
}
