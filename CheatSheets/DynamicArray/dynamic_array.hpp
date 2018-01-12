//
//  dynamic_array.hpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#ifndef dynamic_array_hpp
#define dynamic_array_hpp

#include <stdio.h>
#include <iostream>

class dynamic_array {
public:
    int size = 0;
    int* arr;
    dynamic_array();
    ~dynamic_array();
    void add (int element);
    void pop_back ();
    int get(int i);
    //dynamic_array* operator+(dynamic_array* other); // Can be overloaded
private:
    void copy(int*);
};

#endif /* dynamic_array_hpp */
