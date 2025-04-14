#include "Edge.h"

Edge::Edge(){
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Edge::Edge(int start, int end){
    this->startVert = start;
    this->endVert = end;
    this->weight = 1;
}

/* Getter Methods */

int Edge::getWeight(){
    return this->weight;
}

int Edge::getStartVert(){
    return this->startVert;
}

int Edge::getEndVert(){
    return this->endVert;
}

/* Setter Methods */

void Edge::setStartVert(int sVert){
    this->startVert = sVert;
}

void Edge::setEndVert(int eVert){
    this->endVert = eVert;
}

void Edge::setWeight(int newWeight){
    this->weight = newWeight;
}

void Edge::incWeight(){
    ++(this->weight);
}

