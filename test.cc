#include "smart_ptr.h"

#include <iostream>

struct MyStruct {
    MyStruct() = default;
    MyStruct(int a, int b) : a(a), b(b) {}
    int a;
    int b;
};

int main(int argc, char *argv[]) {
    MyStruct *s = new MyStruct();
    s->a = 10;
    s->b = 20;

    smart_ptr<MyStruct> sp(s);

    std::cout << sp->a << std::endl;
    std::cout << sp->b << std::endl;
    std::cout << (*sp).a << std::endl;

    auto sp2 = make_smart<MyStruct>(100, 200);
    std::cout << sp2->a << std::endl;
    std::cout << sp2->b << std::endl;

    auto p = sp2.release();
    std::cout << p->a << std::endl;
    std::cout << p->b << std::endl;
    delete p;

    return 0;
}