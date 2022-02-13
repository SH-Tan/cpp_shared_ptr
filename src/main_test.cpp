#include <iostream>
#include "shared_ptr.hpp"
#include "unique_ptr.hpp"

struct A {
    A() { std::cout << "A() \n"; }
    ~A() { std::cout << "~A() \n"; }
};

struct B : A {
    B() { std::cout << "B() \n"; }
    ~B() { std::cout << "~B() \n"; }
};

void test_cast_shared() {
    B* a = new B;
    SharedPtr<B> ptr(a);
    {
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<A> b = static_pointer_cast<A>(ptr);
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<B> c = ptr;
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<B> d = ptr;
        std::cout << ptr.use_count() << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;
}

void test_simple_shared() {
    A* a = new A;
    SharedPtr<A> ptr(a);
    {
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<A> b = ptr;
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<A> c = ptr;
        std::cout << ptr.use_count() << std::endl;
        SharedPtr<A> d = std::move(b);
        std::cout << ptr.use_count() << std::endl;
    }
    std::cout << ptr.use_count() << std::endl;
}

void test_simple_unique() {
    A* a = new A;
    UniquePtr<A> ptr(a);
    UniquePtr<A> b(std::move(ptr));
}

int main() { 
    test_simple_shared(); 
    test_simple_unique();
}

