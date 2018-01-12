//
//  dynamic_array.cpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#include "dynamic_array.hpp"
#include <iostream>

using namespace std;

dynamic_array::dynamic_array() {
    this->arr = new int[size+1];
}

dynamic_array::~dynamic_array(){
    // Deconstructor
    //delete [] arr;
}

void dynamic_array::add(int element) {
    // Resize
    int* t_array = new int[this->size+1];
    copy(t_array);
    t_array[this->size] = element;
    delete [] arr;
    this->arr = t_array;
    //delete [] t_array; - WARNING do not do this as the compiler will reuse this space again
    this->size++;
}


void dynamic_array::pop_back() {
    // delete the last memory also
    this->size--;
    int* t_array = new int [this->size];
    copy(t_array);
    
    arr = t_array;
    delete [] t_array;
}

int dynamic_array::get(int i) {
    return arr[i];
}

/*
dynamic_array* dynamic_array::operator+(dynamic_array* other) {
    dynamic_array* result = new dynamic_array;
    result->size = this->size + other->size;
    int index = 0;
    for (int i = 0; i < this->size; i++, index++) result->arr[index] = this->arr[i];
    for (int i = 0; i < other->size; i++, index++) result->arr[index] = other->arr[i];
    
    return result;
}
*/

// Private methods
void dynamic_array::copy(int* t_array) {
    for (int i = 0; i < this->size; i++) {
        t_array[i] = arr[i];
    }
}

