#include "task_mission.h"
#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <list>
#include <atomic>

using namespace std;
void test_task_about1();
void test_task_about()
{
    test_task_about1();
    return;
    mutex lock_num;
    mutex lock_ch;
    bool run = true;
    condition_variable valnum;
    condition_variable valch;
    list<int> linum;
    list<char> lich;
    thread([&](){
        while(run)
        {
            unique_lock<mutex> lk(lock_num);
            valnum.wait(lk);
            if(linum.size())
            {
                cout<<*(linum.begin())<<endl;
                linum.pop_front();
            }
            static int cnt = 0;
            if(cnt++ >40)
            {
                run = false;
                this_thread::sleep_for(chrono::milliseconds(100));
                valnum.notify_all();
            }
        }
    }).detach();

    thread([&](){
        while(run)
        {
            unique_lock<mutex> lk(lock_ch);
            valch.wait(lk);
            if(lich.size())
            {
                cout<<*(lich.begin())<<endl;
                lich.pop_front();
            }
        }
    }).detach();


    this_thread::sleep_for(chrono::milliseconds(200));
    int cnter = 0;
    while(run)
    {
        switch(cnter%2)
        {
            case 0:
            {
                static int data= 1;
                lock_num.lock();
                linum.push_back(data++);
                lock_num.unlock();
                valnum.notify_all();
            }
            break;
            case 1:
            {
                static char ch = 'a';
                lock_ch.lock();
                lich.push_back(ch++);
                lock_ch.unlock();
                valch.notify_all();
            }
            break;
        }
        ++cnter;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
}
void test_task_about1()
{
    atomic_int outstat;
    outstat.store(0);
    bool run = true;
    char outch = 'ch' - 1;
    int outnum = -1;;
    thread([&](){
        int cnter = 0;
        while(run)
        {
            if(outstat.load() == 1)
            {
                cout<<outnum<<" stat:"<<outstat.load()<<endl;
                outstat.store(0);
            }
        }
    }).detach();
    thread([&](){
        int cnter = 0;
        while(run)
        {
            if(outstat.load() == 2)
            {
                cout<<outch<<" stat:"<<outstat.load()<<endl;
                outstat.store(0);
            }
        }
    }).detach();

    while(run)
    {
        int cnter = 0;
        if(outstat.load() == 0)
        {
            switch(cnter %2)
            {
                case 0:
                {
                    ++outnum ;
                    outstat.store(1);
                }
                break;
                case 1:
                {
                    ++outch;
                    outstat.store(2);
                }
                break;
            }
            ++cnter;
            if(cnter > 50)
            {
                run = false;
            }
        }
    }

    this_thread::sleep_for(chrono::milliseconds(2000));
}