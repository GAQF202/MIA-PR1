#include "../abstract/command.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class queue{
    public:
        queue();
        void push(parameter* element);
        void append(queue* otherQueue);
        parameter* cola[100];
        int size;
};

#endif