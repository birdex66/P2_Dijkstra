#include "Vertex.h"

Vertex::Vertex(){
    this->index = -1;
    this->degree = -1;
}

Vertex::Vertex(int i,int deg){
    this->index = i;
    this->degree = deg;
    this->visited = false;
}
    
int Vertex::getIndex(){
    return this->index;
}

int Vertex::getDegree(){
    return this->degree;
}

bool Vertex::getVisit(){
    return this->visited;
}

void Vertex::setIndex(int index){
    this->index = index;
}

void Vertex::setDegree(int deg){
    this->degree = deg;
}

void Vertex::setVisit(bool visit){
    this->visited = visit;
}
