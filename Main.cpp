#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

#include <iostream>

using namespace std;

int main(){

    // start of the initial pipeline that loads the test case file stream from cin

    int numOfVertices;
    int numOfEdges;

    if(!cin.eof()){
        cin >> numOfVertices;
        cin >> numOfEdges;
    }
    else{
        cout<<"Input not found!"<<std::endl;
        return 1;
    }

    Graph* G = new Graph(numOfVertices,numOfEdges);
    Vertex* list[numOfVertices] = {nullptr};

    while(!cin.eof()){
        int startVertice;
        int endVertice;
        cin >> startVertice;
        cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object
        if(!list[startVertice]){
            Vertex* V = new Vertex(startVertice,1);
            list[startVertice] = V;
        }else list[startVertice]->setDegree(1+(list[startVertice]->getDegree())); 

        if(!list[endVertice]){
            Vertex* V = new Vertex(endVertice,1);
            list[endVertice] = V;
        }else list[endVertice]->setDegree(1+(list[endVertice]->getDegree()));

        G->setAdj(newEdge);
    }

    // And here is where you start working on the three tasks
    cout << "The adjacency matrix of G:" << endl;
    G->printGraph();    

    int numOdd = 1;
    int* arrOdd = (int*)malloc(numOdd*sizeof(int));
    cout << "The odd degree vertices in G:\nO = { ";
    for(int i=0; i<numOfVertices; ++i){
        int fer = list[i]->getDegree();
        if(1 == fer%2){
            printf("%i ",fer);
            arrOdd[numOdd-1] = fer;
            ++numOdd;
            arrOdd = (int*)realloc(arrOdd,numOdd*sizeof(int));
        }
    }
    cout << "}\n";
/*
    for(int j=0; j<numOdd; ++j){
        Dijkstra(arrOdd,G);
    }
*/
    free(arrOdd);
    return 0;
}
