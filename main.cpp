#include <iostream>
#include <thread_pool.h>

template<typename F, typename... A>
void pluto(F&& function, A&&... args)
{
    auto x = std::bind(std::forward<F>(function), std::forward<A>(args)...);
    x();
}

float ser(float a, float b)
{
    std::cout << a + b << std::endl;
    return a + b;
}

double aaa(double a, double b, double c)
{
    std::cout << a + b * c << std::endl;
    return a + b * c;
}

void bbb(int& next)
{
    next += 1;
}

template<typename F, typename... A>
auto bbind(F&& func, A&&... args)
{
    return std::bind(std::forward<F>(func), std::forward<A>(args)...);
}


int main(int, char**) 
{
    pluto(ser, 5.0f, 6.0f);
    pluto(aaa, 1.0f, 2.0f, 3.0f);

    int i = 5;
    
    auto s = [](int& x){x += 2;};

    thread_pool tp{};
    auto i_f = tp.submit(std::bind(bbb, std::ref(i)));

    i_f.wait();
    std::cout << i << std::endl;

    auto x_f = tp.submit(bbind(bbb, std::ref(i)));
    
    x_f.wait();
    std::cout << i << std::endl;

    auto y_f = tp.submit(bbb, std::ref(i));
    y_f.wait();
    std::cout << i << std::endl;

    std::cout << "Hello, world!\n";
}
