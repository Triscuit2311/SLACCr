#pragma once
#include "../headers.h"
#include <queue>

class MutexPacketQueue{
public:
    Packet pop(){
        while (!isAvailable);
        isAvailable = false;

        if(queue->size() > 0){
            Packet p = queue->front();
            queue->pop();
            isAvailable = true;
            return p;
        }
        isAvailable = true;
        return Packet();
    }

    void push(Packet packet){
        while (!isAvailable);
        isAvailable = false;
        queue->push(packet);
        isAvailable = true;
    }

    MutexPacketQueue(){
        queue = new std::queue<Packet>();
    }
    
    bool isEmpty(){
        return queue->empty();
    }

    size_t size(){
        return queue->size();
    }

private:
    std::queue<Packet> * queue;
    bool isAvailable = true;
};