#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Queue.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Dijkstra(int oddVertex,Vertex** list,Graph* G,int vertices);

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

    // cout << "Num of Vertices: " << numOfVertices << endl;
    // cout << "Num of Edges: " << numOfEdges << endl; 

    Graph* G = new Graph(numOfVertices,numOfVertices);
    Vertex* list[numOfVertices+1] = {nullptr};

    int i = 0;
    while(!cin.eof() && i<numOfEdges){
        int startVertice;
        int endVertice;
        cin >> startVertice;
        cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object

        if(!list[startVertice-1]){
            Vertex* V = new Vertex(startVertice,1);
            list[startVertice-1] = V;
            //cout << "new vertice: " << startVertice <<endl;
        }else{
            list[startVertice-1]->setDegree(1+(list[startVertice-1]->getDegree()));
            //printf("new degree for %i: %i\n",startVertice,list[startVertice-1]->getDegree());
        }

        if(!list[endVertice-1]){
            Vertex* V = new Vertex(endVertice,1);
            list[endVertice-1] = V;
            //cout << "new vertice: " << endVertice << endl;
        }else{
            list[endVertice-1]->setDegree(1+(list[endVertice-1]->getDegree()));
            //printf("new degree for %i: %i\n",endVertice,list[endVertice-1]->getDegree());
        }

        G->setAdj(newEdge);
        ++i;
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
            cout << i+1 << " ";
        }
    }
    cout << "}\n\n";

    for(int j=0; j<numOdd; ++j){
        Dijkstra(arrOdd[j]+1,list,G,numOfVertices);
    }
    
    free(arrOdd);
    return 0;
}

void Dijkstra(int oddVertex,Vertex** list,Graph* G,int vertices){

    //set all vertices to unvisited 
    for(int i=0; i<vertices; ++i){
        list[i]->setVisit(false);
    }

    int distance[vertices] = {0};
    distance[oddVertex] = 0;

    Queue* Q = new Queue();
    Q->enqueue(oddVertex);

    bool first = true;
    Edge** cur = G->getAdjRow(oddVertex);
    Edge** next;

    int dist = 1;
    while(!Q->isEmpty()){
        list[Q->getHead()]->setVisit(true);
        int l = 1;

        for(int k=0; k<vertices; ++k){
            //cout << k << " ";
            if(!list[k]->getVisit()){
                if(first && cur[k]->getWeight() == 1){
                    first = false;
                    Q->enqueue(k);
                    next = G->getAdjRow(k);
                }else{
                    distance[k] = dist;
                }
            }else ++l;
        }
        //cout << endl;

        if (l >= vertices-1){
            Q->dequeue();
            cout << "here" << endl;
        }
        ++dist;
        cur = next;
        first = true;
    }

    cout << "Single source shortest path lengths from node " << oddVertex << endl; 
    for(int l=0; l<vertices; ++l){
        cout << setw(3) << l+1 << ": " << distance[l] << endl;
    }
}
