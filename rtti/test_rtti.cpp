#include "rtti_.h"
#include <stdlib.h>
#include <typeinfo>
#include <iostream>
using namespace std;
//dynamic可以:1.将基类的指针转化为指定类型的派生类指针(指针已指向派生对象);2.作用于对象，返回指定派生类对象的引用
void test_dynamic();
//typeid(obj)可以返回type_info类型的对象，该对象标识obj对象的类型()，obj不可以是类型名。type_info对象包含name()成员，字符串类型名称
void test_typeid();
void testrtti()
{
    //test_dynamic();
    test_typeid();
}

void test_typeid()
{
    rtti_base *base = new rtti_derivea();
    if(typeid(base) == typeid(rtti_derivea*))
    {
        cout<<"typeid(rtti_base *) == typeid(rtti_derivea*)"<<endl;
    }
    else
    {
        cout<<"typeid(rtti_base *) != typeid(rtti_derivea*)"<<endl;
    }
    //对象为派生类对象，返回类型为派生类的类型对象
    cout<<typeid(*base).name()<<endl;
}

void test_dynamic()
{
    //基类虽然为虚基类，但是可以通过派生类调用基类的构造函数
    rtti_base *base = new rtti_derivea();
    base->showtime();
    rtti_derivea *a=dynamic_cast<rtti_derivea*>(base);
    if(a != NULL)
    {
        a->showderive();
    }
    ((rtti_derivea*)base)->showderive();

    rtti_derivea &obja = dynamic_cast<rtti_derivea&> (*base);
    obja.showderive();

    //调用派生类的析构函数时，自动调用基类的析构函数
    delete a;
    //如果调用delete base，因为其为基类型指针，所以只能调用基类的析构函数
}