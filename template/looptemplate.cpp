#include "looptemplate.h"
#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
void switchval(T &val, T &val1)
{
    T temp = val;
    val = val1;
    val1 = temp;
}

template<> void switchval<node>(node &val1, node& val2)
{
    int temp = val1.val;
    val1.val = val2.val;
    val2.val = temp;
}

template<typename T>
void printloop(T val)
{
    cout<<val<<endl;
}

template<typename T, typename ...Args >
void printloop( T val, Args ... args)
{
    cout<<val<<endl;
    printloop(args ...);
}

void testtemplate()
{
    int a = 10, b = 20;
    cout<<"before :"<<a<<" "<<b<<endl;
    switchval(a,b);
    cout<<"after :"<<a<<" "<<b<<endl;

    node  na ={1,{'a'}}, nb = {2,{'b'}};
    cout<<"before :"<<na.name<<": "<<na.val<<", "<<nb.name<<": "<<nb.val<<endl;
    switchval(na,nb);
    cout<<"after :"<<na.name<<": "<<na.val<<", "<<nb.name<<": "<<nb.val<<endl;

    printloop(1,"hello");

    //根据值(表达式)的类型,定义变量。auto要求有初始值
    decltype (na.name) x = "aaaaaaaaaa";
    cout<<x<<endl;
}