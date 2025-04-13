#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

#include <iostream>

using namespace std;

void Dijkstra(int oddVertex,Graph* G,int vertices);

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
    Vertex* list[numOfVertices+1] = {nullptr};


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
            //printf("new vertice: %i\n",startVertice);
        }else{
            list[startVertice]->setDegree(1+(list[startVertice]->getDegree()));
            //printf("new degree for %i: %i\n",startVertice,list[startVertice]->getDegree());
        }

        if(!list[endVertice]){
            Vertex* V = new Vertex(endVertice,1);
            list[endVertice] = V;
            //printf("new vertice: %i\n",endVertice);
        }else{
            list[endVertice]->setDegree(1+(list[endVertice]->getDegree()));
            //printf("new degree for %i: %i\n",endVertice,list[endVertice]->getDegree());
        }

        G->setAdj(newEdge);
    }

    // And here is where you start working on the three tasks
    cout << "The adjacency matrix of G:" << endl;
    G->printGraph();    

    int numOdd = 0;
    int* arrOdd = NULL; 
    cout << "The odd degree vertices in G:\nO = { ";
    for(int i=1; i<=numOfVertices; ++i){
        int degree = list[i]->getDegree();
        if(1 == degree%2){
            arrOdd = (int*)realloc(arrOdd,(numOdd+1)*sizeof(int));
            arrOdd[numOdd] = i;
            ++numOdd;
            cout << i << " ";
        }
    }
    cout << "}\n";
    /*
       for(int j=0; j<numOdd; ++j){
       Dijkstra(arrOdd[j],G,numOfVertices);
       }
       */
    free(arrOdd);
    return 0;
}

void Dijkstra(int oddVertex,Graph* G,int vertices){
    int chart[2][vertices];
}
