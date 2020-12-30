/*----------------------------------*/
/* This is my first Google Test     */
/*----------------------------------*/


#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*----------------------------------------------*/
/*  Command used to run test :                  */
/*  g++ Test.cpp -lgtest -lgtest_main -pthread  */
/*  ./a.out                                     */
/*----------------------------------------------*/
