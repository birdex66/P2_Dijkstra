#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Queue.h"

#include <iostream>

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

    Graph* G = new Graph(numOfVertices,numOfEdges); // initalizes graph
    Vertex* list[numOfVertices+1] = {nullptr}; // list that tracks each vertice degree

    int i = 0;
    while(!cin.eof() && i<numOfEdges){
        int startVertice;
        int endVertice;
        cin >> startVertice;
        cin >> endVertice;
        Edge* newEdge = new Edge(startVertice, endVertice);
        // Here is where you load up the Graph object

        if(!list[startVertice-1]){ //makes new vertice and adds to list 
            Vertex* V = new Vertex(startVertice,1);
            list[startVertice-1] = V;
                //cout << "new vertice: " << startVertice <<endl;
        }else{ //updates degree
            list[startVertice-1]->setDegree(1+(list[startVertice-1]->getDegree()));
            //printf("new degree for %i: %i\n",startVertice,list[startVertice-1]->getDegree());
        }

        if(!list[endVertice-1]){  //makes new vertice and adds to list 
            Vertex* V = new Vertex(endVertice,1);
            list[endVertice-1] = V;
                //cout << "new vertice: " << endVertice << endl;
        }else{ //updates degree
            list[endVertice-1]->setDegree(1+(list[endVertice-1]->getDegree()));
            //printf("new degree for %i: %i\n",endVertice,list[endVertice-1]->getDegree());
        }

        G->setAdj(newEdge); //add to graph
        delete newEdge;
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
        if(1 == degree%2) { //checks if degree is odd
            arrOdd = (int*)realloc(arrOdd,(numOdd+1)*sizeof(int)); //reallocs extra element
            arrOdd[numOdd] = i;
            ++numOdd;
            cout << i+1 << " ";
        }
    }
    cout << "}\n\n";

    for(int j=0; j<numOdd; ++j){
        Dijkstra(arrOdd[j],list,G,numOfVertices); //Dijikstra for array of odd vertices
    }


    for(int k=0; k<numOfVertices; ++k){
        delete list[k];
    }
    
    free(arrOdd);
    delete G;
    return 0;
}

void Dijkstra(int oddVertex,Vertex** list,Graph* G,int vertices){

    //set all vertices to unvisited 
    for(int i=0; i<vertices; ++i){
        list[i]->setVisit(false);
    }

    int distance[vertices];
    for (int i = 0; i < vertices; ++i) distance[i] = -1; // array of unvisited vertices

    distance[oddVertex] = 0;
    list[oddVertex]->setVisit(true); //set root vertice to visited

    Queue* Q = new Queue(); // Priority Queue
    Q->enqueue(oddVertex);

    while(!Q->isEmpty()){
        int u = Q->dequeue(); //element taken off queue for checking routes 
        Edge** adj = G->getAdjRow(u); // get list of adjacency vertices
        for(int k=0; k<vertices; ++k){
            if(!list[k]->getVisit() && adj[k]->getWeight() == 1){ //if vertice isnt visited and is adjacent...
                distance[k] = distance[u]+1; //calculate distance offset and save in array
                list[k]->setVisit(true); // visited vertice
                Q->enqueue(k); // queues closest element (numerically)
            }
        }
    }

    cout << "Single source shortest path lengths from node " << oddVertex+1 << endl; 
    for(int l=0; l<vertices; ++l){
        cout << setw(3) << l+1 << ": " << distance[l] << endl;
    }

    delete Q;
}
