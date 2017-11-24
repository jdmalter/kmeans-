#include "assignments.cpp"
#include "darray.cpp"
#include <iostream>
#include <stdlib.h>

/*
 * Simple C++ Test Suite
 */

void assign() {
    const int expected[7] = 
    {
        0,
        0,
        0,
        1,
        1,
        1,
        1,
    };
    int assignments[7] = 
    {
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };
    const darray vectors[7] = 
    {
        {1.0, 1.0},
        {1.5, 2.0},
        {3.0, 4.0},
        {5.0, 7.0},
        {3.5, 5.0},
        {4.5, 5.0},
        {3.5, 4.5},
    };
    const double* clusters[2] = 
    {
        {1.0, 1.0},
        {5.0, 7.0},
    };
    
    assign<2, 7, 2>(assignments, vectors, clusters);
    
    bool failed = false;
    for (int i = 0; i < 7; i++)
    {
        if (expected[i] != assignments[i])
        {
            std::cout << "%TEST_FAILED% testname=assign (assignmentstest) " << 
                    "expected[" << i << "]=" << expected[i] << 
                    " assignments[" << i << "]=" << assignments[i] << std::endl;
            failed = true;
        }
    }
    if (failed)
    {
        return;
    }
    
    std::cout << "%TEST_PASSED% testname=assign (assignmentstest)" << std::endl;
}

void update() {
    const double* expected[2] = 
    {
        {(1.0 + 1.5 + 3.0) / 3, (1.0 + 2.0 + 4.0) / 3},
        {(5.0 + 3.5 + 4.5 + 3.5) / 4, (7.0 + 5.0 + 5.0 + 4.5) / 4},
    };
    double* clusters[2] = 
    {
        {1.0, 1.0},
        {5.0, 7.0},
    };
    const darray vectors[7] = 
    {
        {1.0, 1.0},
        {1.5, 2.0},
        {3.0, 4.0},
        {5.0, 7.0},
        {3.5, 5.0},
        {4.5, 5.0},
        {3.5, 4.5},
    };
    const int assignments[7] = 
    {
        0,
        0,
        0,
        1,
        1,
        1,
        1,
    };
    
    update<2, 7, 2>(clusters, vectors, assignments);
    
    bool failed = false;
    for (int i = 0; i < 2; i++)
    {
        for (int  j = 0; j < 2; j++)
        {
            if (expected[i][j] != clusters[i][j])
            {
                std::cout << "%TEST_FAILED% testname=update (assignmentstest) " << 
                    "expected[" << i << "][" << j << "]=" << expected[i][j] << 
                    " clusters[" << i << "][" << j << "]=" << clusters[i][j] << std::endl;
                failed = true;
            }
        }
    }
    if (failed)
    {
        return;
    }
    
    std::cout << "%TEST_PASSED% testname=update (assignmentstest)" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% assignmentstest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% assign (assignmentstest)" << std::endl;
    assign();
    std::cout << "%TEST_FINISHED% assign (assignmentstest)" << std::endl;

    std::cout << "%TEST_STARTED% update (assignmentstest)" << std::endl;
    update();
    std::cout << "%TEST_FINISHED% update (assignmentstest)" << std::endl;

    std::cout << "%SUITE_FINISHED%" << std::endl;

    return (EXIT_SUCCESS);
}

