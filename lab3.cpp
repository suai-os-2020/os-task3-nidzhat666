//
// Created by Nidzhat on 21.04.2020.
//VER 1.2
#include <windows.h>
#include "lab3.h"

#define MAX_SEM_COUNT 13

HANDLE mutex;
HANDLE thread_a1,thread_c1,thread_b1,thread_g1,thread_d1,thread_f1,thread_h1,thread_k1,thread_m1,thread_n1, thread_p1,thread_e1;
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
    thread_e1 = CreateThread(NULL, 0, thread_e, 0, 0, &IDThread);
    if (thread_d1 == NULL)
        return GetLastError();

    //-------------------------
    WaitForSingleObject(thread_a1, INFINITE);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semC);
    sem_post(semD);

    sem_wait(semB1);
    sem_wait(semF1);
    sem_wait(semD1);
    WaitForSingleObject(thread_c1, INFINITE);
    //-------------------------
    sem_post(semB);
    sem_post(semF);
    sem_post(semD);
    sem_post(semE);

    sem_wait(semB1);
    WaitForSingleObject(thread_e1, INFINITE);
    WaitForSingleObject(thread_f1, INFINITE);
    WaitForSingleObject(thread_d1, INFINITE);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semG);
    sem_post(semM);


    sem_wait(semB1);
    sem_wait(semK1);
    sem_wait(semM1);
    WaitForSingleObject(thread_g1, INFINITE);
    //-------------------------
    sem_post(semB);
    sem_post(semK);
    sem_post(semM);
    sem_post(semH);

    sem_wait(semB1);
    WaitForSingleObject(thread_k1, INFINITE);
    WaitForSingleObject(thread_m1, INFINITE);
    WaitForSingleObject(thread_h1, INFINITE);
    //-------------------------
    sem_post(semB);
    sem_post(semN);

    WaitForSingleObject(thread_b1, INFINITE);
    WaitForSingleObject(thread_n1, INFINITE);
    //-------------------------
    sem_post(semP);
    WaitForSingleObject(thread_p1, INFINITE);


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
    CloseHandle(thread_a1);
    CloseHandle(thread_c1);
    CloseHandle(thread_b1);
    CloseHandle(thread_e1);
    CloseHandle(thread_g1);
    CloseHandle(thread_d1);
    CloseHandle(thread_f1);
    CloseHandle(thread_h1);
    CloseHandle(thread_k1);
    CloseHandle(thread_m1);
    CloseHandle(thread_n1);
    CloseHandle(thread_p1);

    //close mutex
    CloseHandle(mutex);
//	system("pause");
	return 0;
}
