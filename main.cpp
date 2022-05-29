#include "Vector.h"
#include <stdio.h>
#include <vector>
#include "Timer.h"

int main()
{
    
    unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;
    Timer timer;

    for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
    auto delay = timer.stop() / 1000;

    printf("%Lf\n", delay);
    // Baigti v1 užpildymo laiko matavimą

    // Pradėti v2 užpildymo laiko matavimą
    Timer timer2;
    Vector<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
    auto delay2 = timer2.stop() / 1000;
    printf("%Lf\n", delay2);
// Baigti v2 užpildymo laiko matavimą
    // std::vector<int> v;

    // Vector<int> vec(2);

    // vec.push_back(5);
    // vec.push_back(4);
    // vec.push_back(100);
    // vec.push_back(-11);
    // vec.erase(vec.getBegin() + 1);
    // vec.push_back(6);

    // printf("%d %d", vec[1], vec.at(4));
    return 0;
}