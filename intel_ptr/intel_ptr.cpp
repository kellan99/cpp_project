#include "intel_ptr.h"
#include "rtti/rtti_.h"
#include <iostream>
#include <memory>
using namespace std;
void sptr_param(shared_ptr<rtti_deriveb>);
//unique_ptr参数如果不为引用将错误,也不可以使用右值引用
void uptr_param(unique_ptr<rtti_derivea>&);
void test_intelptr()
{
    shared_ptr<rtti_deriveb> ptrb = make_shared<rtti_deriveb>();
    ptrb->setnumber(1);
    sptr_param(ptrb);
    ptrb->showtime();
    cout<<"!!!!!!!!!!!!!!!!!!!!"<<endl;

    unique_ptr<rtti_derivea> uptr = make_unique<rtti_derivea>();
    uptr->setnumber(3);
    uptr_param(uptr);
    uptr->showtime();

    //unique_ptr有数组的变体,可以申请数组
    unique_ptr<rtti_derivea []> arraya(new rtti_derivea[10]);
    cout<<typeid(arraya).name()<<endl;
    for(int i = 0; i< 10; ++i)
    {
        arraya[i].setnumber(i);
        arraya[i].showtime();
    }
}

void sptr_param(shared_ptr<rtti_deriveb> ptr)
{
    //复制构造函数使用的是浅复制
    ptr->setnumber(2);
    ptr->showtime();
}

void uptr_param(unique_ptr<rtti_derivea> &ptr)
{
    //赋值构造函数使用的深复制
    ptr->setnumber(4);
    ptr->showtime();
}