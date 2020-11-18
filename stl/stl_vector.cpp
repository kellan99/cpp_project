#include "stl_header.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <signal.h>
using namespace std;
void test_veccopy();
void testvector()
{
    test_veccopy();
    return;
    //capacity表示vector实际占用内存空间，size标识正在使用的空间
    //clear后size()为0，capacity()不变
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //a.clear();
    //cout<<"after clear() vector size: "<<a.size()<<endl;  //输出0
    //cout<<"after clear() vector capacity: "<<a.capacity()<<endl; //输出3
    vector<int>b(3,2);
    a.resize(a.size() + b.size());
    copy(b.begin(),b.end(),a.end()-b.size());

    ///////////////swap()////////////////
    cout<<"before swap"<<endl;
    cout<<"a "<<a.size()<<" "<<a.capacity()<<" "<<endl;
    cout<<"b "<<b.size()<<" "<<b.capacity()<<" "<<endl;
    a.swap(b);
    cout<<"after swap"<<endl;
    cout<<"a "<<a.size()<<" "<<a.capacity()<<" "<<endl;
    cout<<"b "<<b.size()<<" "<<b.capacity()<<" "<<endl;

    /**************erase()****************/
    cout<<"test erase"<<endl;
    cout<<"a.size(): "<<a.size()<<"; a.capacity(): "<<a.capacity()<<endl<<"a.items: ";
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    a.erase(a.begin(), a.begin() + 2);
    cout<<"after a.erase(a.begin(), a.begin() + 2)"<<endl;
    cout<<"a.size(): "<<a.size()<<"; a.capacity(): "<<a.capacity()<<endl<<"a.items: ";
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    /**************insert()****************/
    cout<<"test insert"<<endl;
    cout<<"a.size(): "<<a.size()<<"; a.capacity(): "<<a.capacity()<<endl<<"a.items: ";
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl<<"b items:";
    for(auto &x: b)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    a.insert(a.begin(), b.begin(),b.end());
    cout<<"after a.insert(a.begin(), b.begin(),b.end());"<<endl;
    cout<<"a.size(): "<<a.size()<<"; a.capacity(): "<<a.capacity()<<endl<<"a.items: ";
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    a.insert(a.end(), a.begin(),a.end());
    cout<<"after a.insert(a.end(), b.begin(),b.end());"<<endl;
    cout<<"a.size(): "<<a.size()<<"; a.capacity(): "<<a.capacity()<<endl<<"a.items: ";
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
void test_veccopy()
{
    vector<int> vec(1024*1024);  
    for(auto x = vec.begin(); x!= vec.end(); ++ x)
    {
        *x = x - vec.begin();
    }
    auto timebegin = std::chrono::steady_clock::now();
    vector<int> vec1(20);
    vec1 = std::move(vec);
    auto timeend = std::chrono::steady_clock::now();
    cout<<"copy timems: "<<chrono::duration_cast<chrono::microseconds>(timeend - timebegin).count();
    cout<<"vec sizes: "<<vec.size()<<" "<<vec1.size()<<endl;

    timebegin = std::chrono::steady_clock::now();
    vector<int> vec2;
    vec2.swap(vec);
    timeend = std::chrono::steady_clock::now();
    cout<<"copy timems: "<<chrono::duration_cast<chrono::microseconds>(timeend - timebegin).count();
    cout<<"vec sizes: "<<vec.size()<<" "<<vec2.size()<<endl;
}