#include <stdio.h>
#include "Graph.h"
#include <stdlib.h>

Graph::Graph(int nVert, int nEdge){
    this->numOfVertices = nVert;
    this->numOfEdges = nEdge;
    //this->G = (Edge***)malloc(nVert*sizeof(Edge**)); // initalizes array with Edge** pointers
    this->G = new Edge**[nVert];
    initializeGraph(nVert);
}

Graph::~Graph(){
    int len = this->numOfVertices;
    for(int i=0; i<len; ++i){
        for(int j=0; j<len; ++j){
            delete this->G[i][j];
        }
        delete[] this->G[i]; //frees each row of Edge**
    }
    delete[] this->G; //frees Graph
}

/* Get Methods */

int Graph::getVertices(){
    return this->numOfVertices;
}

int Graph::getEdges(){
    return this->numOfEdges;
}

//returns row of Adjacency Matric
Edge** Graph::getAdjRow(int ref){
    return this->G[ref];
}


/* Setter Methods */

void Graph::setVertices(int nVert){
    this->numOfVertices = nVert;
}

void Graph::setEdges(int nEdge){
    this->numOfEdges = nEdge;
}

// Establishes edge connection
void Graph::setAdj(Edge* e){
    int start = e->getStartVert()-1;   
    int end = e->getEndVert()-1;

    if(start >= 0 && start < this->numOfVertices && end >=0 && end < this->numOfVertices){
        this->G[start][end]->setWeight(1);
        this->G[end][start]->setWeight(1);
    }else{
        return;
    }
}

void Graph::initializeGraph(int nVert){
    for(int i=0; i<nVert; ++i){
        this->G[i] = new Edge*[nVert]; // initalizes each array row with Edge* pointers
        for(int j=0; j<nVert; ++j){
            this->G[i][j] = new Edge();
            this->G[i][j]->setWeight(0); 
        }
    }
}

// Prints the Graph
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
