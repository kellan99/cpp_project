#ifndef _RTTI_H_
#define _RTTI_H_
class rtti_base
{
private:
    /* data */
public:
    rtti_base(/* args */);
    ~rtti_base();
    virtual void showtime() = 0;
};

class rtti_derivea:public rtti_base
{
    int number;
    public:
        rtti_derivea();
        ~rtti_derivea();
        void showtime();
        void showderive();
        void setnumber(int);
};

class rtti_deriveb:public rtti_derivea
{
    public:
        rtti_deriveb();
        ~rtti_deriveb();
        void showtime();
        void showderive();
        void showderiveb();
};

#endif // !_RTTI_H_