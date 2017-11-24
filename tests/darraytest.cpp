#include "darray.cpp"
#include <iostream>
#include <stdlib.h>

/*
 * Simple C++ Test Suite
 */

void distanceOf5()
{
    const double expected = 5;
    darray a = {3, 0};
    darray b = {0, 4};
    
    const double actual = distance(a, b);
    
    if (expected == actual)
    {
        std::cout << "%TEST_PASSED% testname=distanceOf5 (darraytest) expected=5 actual=" << actual << std::endl;
    }
    else
    {
        std::cout << "%TEST_FAILED% testname=distanceOf5 (darraytest) expected=5 actual=" << actual << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% darraytest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% distanceOf5 (darraytest)" << std::endl;
    distanceOf5();
    std::cout << "%TEST_FINISHED% distanceOf5 (darraytest)" << std::endl;

    std::cout << "%SUITE_FINISHED%" << std::endl;

    return (EXIT_SUCCESS);
}

