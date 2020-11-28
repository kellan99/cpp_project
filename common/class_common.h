#ifndef CLASS_COMMON_H
#define CLASS_COMMON_H
class cla_derive
{
    public:
        int arr;
};
class cla
{
    public:
    int data;
        //只定义类对象时使用
        cla();
        //用一个对象去初始化另一个对象时(包括函数参数为非对象引用和指针时)
        cla(const cla& cl);
        //用一个值去
        cla(int);
        ~cla();
        cla & operator=(const cla &cl);
        //因为友元传递的是引用，所以调用过友元重载后，cla对象的data成员值变了
        friend void operator* (class cla &dcla, const cla_derive &cl)
        {
            dcla.data = cl.arr;
        }
};


void test_cla();
#endif