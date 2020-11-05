#include "stl_header.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void testfind();
void testforeach();
void testrandomshuffle();
void testsort();
void test_stl()
{
    //testfind();
    //testforeach();
    //testrandomshuffle();
    testsort();
}

void testsort()
{
    //sort两个版本，默认为从小到大
    //可以指定第三个参数为比较大小的函数指针
    string str= "asdfghjqweryt123";
    for_each(str.begin(), str.end(),[](char ch){cout<<ch<<" ";});
    sort(str.begin(), str.end());
    cout<<endl<<"after sort(str.begin(), str.end());"<<endl;
    for_each(str.begin(), str.end(),[](char ch){cout<<ch<<" ";});

    str= "asdfghjqweryt123";
    sort(str.begin(), str.end(),[](char c1, char c2){return c1>=c2;});
    cout<<endl<<"sort(str.begin(), str.end(),[](char c1, char c2){return c1>=c2;});"<<endl;
    for_each(str.begin(), str.end(),[](char ch){cout<<ch<<" ";});
}

void testfind()
{
    vector<int> a(3);
    a[0] = 1;a[1]=10;a[2]=3;
    //find找到时返回指定值对应的迭代器值，未找到返回容器end()迭代器
    vector<int>::iterator itfind = find(a.begin(), a.end(),11);
    if(itfind == a.end())
    {
        cout<<"find failed"<<endl;
    }
    else
    {
        cout<<*itfind<<endl;    
    }
}

void testforeach()
{
    string str= "asdfghjqweryt123";
    for_each(str.begin(),str.end(),[](char &ch){cout<<ch<<" "; ch+=1;});
    cout<<endl<<"after all items+1: "<<endl;
    for_each(str.begin(),str.end(),[](char &ch){cout<<ch<<" "; });
    cout<<endl;
}

void testrandomshuffle()
{
    string str= "asdfghjqweryt123";
    //接收两个迭代器作为区间，乱序区间内元素
    for_each(str.begin(),str.end(),[](char &ch){cout<<ch<<" ";});
    random_shuffle(str.begin(), str.end());
    cout<<endl<<"after random_shuffle(str.begin(), str.end());"<<endl;
    for_each(str.begin(),str.end(),[](char &ch){cout<<ch<<" "; });
}