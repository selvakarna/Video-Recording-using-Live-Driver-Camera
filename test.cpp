/*
 * test.cpp
 *
 *  Created on: 11-Aug-2022
 *      Author: selva
 */
#include <stdio.h>
// #include "Cameopen.h"
#include "Cameopen.cpp"
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;

int main(int argc, char** argv){
    char** fac;
    int ret;
    
    if ( argc != 2 ) {
    printf("no args\n");
    return -1;
    }
    
    fac=argv;
    ret=Cameopen(fac);
    std::cout << "From main........:.........." << ret << std::endl;
    // cout<<"The result is"<<" "<<;
}