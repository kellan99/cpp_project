#ifndef CLASS_COMMON_H
#define CLASS_COMMON_H
class cla
{
    int data;
    public:
        //只定义类对象时使用
        cla();
        //用一个对象去初始化另一个对象时(包括函数参数为非对象引用和指针时)
        cla(const cla& cl);
        //用一个值去
        cla(int);
        ~cla();
        cla & operator=(const cla &cl);
};

class cla_derive:public cla
{

};
void test_cla();
#endif