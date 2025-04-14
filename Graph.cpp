#include <stdio.h>
#include "Graph.h"
#include <stdlib.h>

Graph::Graph(int nVert, int nEdge){
    this->numOfVertices = nVert;
    this->numOfEdges = nEdge;
    this->G = (Edge***)malloc(nVert*sizeof(Edge**));
    initializeGraph(nVert);
}

Graph::~Graph(){
    int len = this->numOfVertices;
    for(int i=0; i<len; ++i){
        free(this->G[i]);
    }
    delete this->G;
}

int Graph::getVertices(){
    return this->numOfVertices;
}

int Graph::getEdges(){
    return this->numOfEdges;
}

Edge** Graph::getAdjRow(int ref){
    return this->G[ref];
}

void Graph::setVertices(int nVert){
    this->numOfVertices = nVert;
}

void Graph::setEdges(int nEdge){
    this->numOfEdges = nEdge;
}
void Graph::setAdj(Edge* e){
    this->G[e->getStartVert()-1][e->getEndVert()-1]->setWeight(1);
    this->G[e->getEndVert()-1][e->getStartVert()-1]->setWeight(1);
}

void Graph::initializeGraph(int nVert){
    for(int i=0; i<nVert; ++i){
        this->G[i] = new Edge*[nVert];
        for(int j=0; j<nVert; ++j){
            this->G[i][j] = new Edge();
            this->G[i][j]->setWeight(0); 
        }
    }
}

void Graph::printGraph(){
    int len = this->numOfVertices;
    for(int i=0; i<len; ++i){
        for(int j=0; j<len; ++j){
            printf("%i ",this->G[i][j]->getWeight()); 
        }
        putchar('\n');
    }
    putchar('\n');
}
