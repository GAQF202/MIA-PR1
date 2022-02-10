#include "../estructures/queue.h"
#include <iostream>
#include <string>
using namespace std;


//CONSTRUCTOR
queue::queue(){
    size = 0;
}


void queue :: push(parameter* element){
    this->cola[size] = element;
    this->size++;
}

void queue::append(queue* otherQueue){
    for(int i=0; i < otherQueue->size; i++){
        this->cola[this->size] = otherQueue->cola[i];
        this->size++;
    }
}
