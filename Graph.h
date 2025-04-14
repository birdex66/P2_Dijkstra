#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"

class Graph{
    private:
        int numOfVertices;
        int numOfEdges;
        Edge*** G; //2d Array of Edge* pointers
    public:
        Graph(int,int);
        ~Graph();

        //Getter Methods
        int getVertices();
        int getEdges();
        Edge** getAdjRow(int);
        
        //Setter Methods
        void setVertices(int);
        void setEdges(int);
        void setAdj(Edge*);
        
        void initializeGraph(int);
        void printGraph();
};


#endif
