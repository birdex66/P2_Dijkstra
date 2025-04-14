#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"

class Graph{
    private:
        int numOfVertices;
        int numOfEdges;
        Edge*** G;
    public:
        Graph(int,int);
        ~Graph();

        int getVertices();
        int getEdges();
        Edge** getAdjRow(int);
        
        void setVertices(int);
        void setEdges(int);
        void setAdj(Edge*);
        
        void initializeGraph(int);
        void printGraph();
};


#endif
