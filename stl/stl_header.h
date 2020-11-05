#ifndef  _STL_INTERFACE_
/*使用push_back时vector容器的size()每次+1，capacity()按照 0 1 2 4 8 ... 2^n向上增长，防止高频的重新申请内存*/
/*vector容器在定义时如果指定了容器内个数，则capacity()值等于size()值，即使size()不为2^n*/
void testvector();
void test_stl();
#endif // ! _STL_INTERFACE_