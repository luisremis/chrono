#include <iostream>
#include "Chrono.h"

int main(int argc, char **argv)
{
    ChronoCpu test1("test1");
    ChronoCpu test2("test2");

    float a = 34.5434543;
    float b = 5435.45435;

    test1.tic();
    for (int i = 0; i < 1000; ++i)
    {
        test2.tic();
        for (int j = 0; j < 100000; ++j)
        {
            if (j%2 == 0)
                a = a * b;
            else
                a = a / b;
        }
        test2.tac();
    }

    std::cout << a << std::endl;

    test1.tac();

    test1.printTotalTime_us();

    test2.printAvgTime_us();
    test2.printLastTime_us();
    std::cout << "test2 standard deviation: "
              << test2.getSTD_us() << std::endl;

    return 0;
}
