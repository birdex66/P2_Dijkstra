#include "Vertex.h"

Vertex::Vertex(){
    this->index = -1;
    this->degree = -1;
}

Vertex::Vertex(int i,int deg){
    this->index = i;
    this->degree = deg;
}
    
int Vertex::getIndex(){
    return this->index;
}

int Vertex::getDegree(){
    return this->degree;
}

void Vertex::setIndex(int index){
    this->index = index;
}

void Vertex::setDegree(int deg){
    this->degree = deg;
}
