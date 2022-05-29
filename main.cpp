#include "Vector.h"
#include <stdio.h>
#include <vector>
#include "Timer.h"

int main()
{
      // 100000, 1000000, 10000000, 100000000
    std::vector<int> v1;

    for(int iz= 100000 ; iz < 1000000000; iz *= 10)
    {
            Timer timer;
            for (int i = 1; i <= iz; ++i)
                v1.push_back(i);
            auto delay = timer.stop() / 1000;

            Timer timer2;
            Vector<int> v2;
            for (int i = 1; i <= iz; ++i)
                v2.push_back(i);

            auto delay2 = timer2.stop() / 1000;
            printf("index:%d:STD: %Lf mano: %Lf\n", iz, delay, delay2);
        // Baigti v2 užpildymo laiko matavimą
    }

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