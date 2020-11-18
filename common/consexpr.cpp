#include "consexpr.h"
#include <iostream>
#include <librtmp/rtmp.h>
using namespace std;
int funcnt(){static int i =0; ++i; return i;}
void funtest(int,int,int,int);
inline int fund(){return 100;}
constexpr int fun(const int i){return i%10;}
void test_constexprfun()
{
    for(int i = 0 ; i < 100; ++ i)
    {
        switch(i)
        {
            case fun(1):
            {
                cout<<fun(1)<<endl;
            }
            break;
            default :break;
        }
    }

    funtest(funcnt(),funcnt(),funcnt(),funcnt());
}
void funtest(int a,int b,int c,int d)
{
    std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}