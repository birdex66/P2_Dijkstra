#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

#include <iostream>

using namespace std;

void Dijkstra(int oddVertex,Vertex* list,Graph* G,int vertices);

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
    
    cout << "Num of Vertices: " << numOfVertices << endl;
    cout << "Num of Edges: " << numOfEdges << endl; 

    Graph* G = new Graph(numOfVertices,numOfEdges);
    Vertex* list[numOfVertices+1] = {nullptr};


    while(!cin.eof()){
        int startVertice;
        int endVertice;
        cin >> startVertice;
        cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object
       
        if(!list[startVertice-1]){
            Vertex* V = new Vertex(startVertice,1);
            list[startVertice-1] = V;
            cout << "new vertice: " << startVertice <<endl;
        }else{
            list[startVertice-1]->incDegree();
            printf("new degree for %i: %i\n",startVertice,list[startVertice-1]->getDegree());
        }

        if(!list[endVertice-1]){
            Vertex* V = new Vertex(endVertice,1);
            list[endVertice-1] = V;
            cout << "new vertice: " << endVertice << endl;
        }else{
            list[endVertice-1]->incDegree();
            printf("new degree for %i: %i\n",endVertice,list[endVertice-1]->getDegree());
        }

        G->setAdj(newEdge);
    }

    // And here is where you start working on the three tasks
    cout << "The adjacency matrix of G:" << endl;
    G->printGraph();    

    int numOdd = 0;
    int* arrOdd = NULL; 
    cout << "The odd degree vertices in G:\nO = { ";
    for(int i=0; i<numOfVertices; ++i){
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
          Dijkstra(arrOdd[j],list,G,numOfVertices);
       }
    */
    free(arrOdd);
    return 0;
}

void Dijkstra(int oddVertex,Vertex** list,Graph* G,int vertices){
/*    //set all vertices to unvisited 
    for(int i=0; i<vertices; ++i){
        list[i]->setVisit(false);
    }

    for(int j=0; j<vertices; ++j){
        
    }*/
}
