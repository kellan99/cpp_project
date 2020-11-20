#include "class_common.h"
#include <iostream>
using namespace std;
cla::cla()
{
    cout<<"construct"<<endl;
}

cla::cla(const cla& cl)
{
    cout<<"copy class construct"<<endl;
}

cla::~cla()
{
    cout<<"destruct construct"<<endl;
}

cla & cla::operator=(const cla &cl)
{
    this->data = cl.data;
    cout<<"operator ="<<endl;
    return *this;
}

cla::cla(int val)
{
    cout<<"copy val construct"<<endl;
}

void test_class(cla cl)
{
}

void test_cla()
{
    cla cl;
    test_class(cl);
    test_class(1);

    cla cl1 = cl;
    cla cl2(cl);
    cla cl3(10);
    cl3 = cl;
}
