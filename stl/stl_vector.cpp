#include "stl_header.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void testvector()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //a.clear();
    //cout<<"after clear() vector size: "<<a.size()<<endl;
    //cout<<"after clear() vector capacity: "<<a.capacity()<<endl;
    vector<int>b;
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    a.resize(6);
    copy(b.begin(),b.end(),a.end()-b.size());
    cout<<"after clear() vector size: "<<a.size()<<endl;
    for(auto &x: a)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}