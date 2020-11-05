#include"rtti_.h"
#include <iostream>
#include <typeinfo>
using namespace std;
rtti_base::rtti_base()
{
    cout<<"rtti_base construct"<<endl;
}

rtti_base::~rtti_base()
{
    cout<<"rtti_base destruct"<<endl;
}

rtti_derivea::rtti_derivea():rtti_base()
{
    cout<<"rtti_derivea construct"<<endl;
}

rtti_derivea::~rtti_derivea()
{
    cout<<"rtti_derivea destruct"<<endl;
}

void rtti_derivea::showtime()
{
    cout<<typeid(*this).name()<<" number:"<<number<<endl;
}

void rtti_derivea::setnumber(int a)
{
    number = a;
}

void rtti_derivea::showderive()
{
    cout<<"rtti_derivea showderive"<<endl;
}

rtti_deriveb::rtti_deriveb():rtti_derivea()
{
    cout<<"rtti_deriveb construct"<<endl;
}

rtti_deriveb::~rtti_deriveb()
{
    cout<<"rtti_deriveb destruct"<<endl;
}

void rtti_deriveb::showtime()
{
    rtti_derivea::showtime();
}

void rtti_deriveb::showderive()
{
    cout<<"rtti_deriveb showderive"<<endl;
}
void rtti_deriveb::showderiveb()
{
    cout<<"rtti_deriveb showderiveb"<<endl;
}