#ifndef _TEMPLATE_LOOP_
#define _TEMPLATE_LOOP_
#include <iostream>
using namespace std;

struct node
{
    int val;
    char name[16];
};

template<typename T>
void switchval(T &val, T &val1);

//非模板函数>显式具体化>一般模板函数
//显式具体化，
template<> void switchval<node>(node &, node&);
void testtemplate();

//模板参数包
template<typename T>
void printloop(T type);
//循环展开是参数列表必须按照从左到右展开
template<typename T, typename ...Arg>
void printloop(T val, Arg ... args);


#endif