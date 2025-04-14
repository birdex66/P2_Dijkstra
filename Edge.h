#ifndef EDGE_H
#define EDGE_H

class Edge{
    private:
        int startVert;
        int endVert;
        int weight;
    public:
        Edge();
        Edge(int,int);

        //Getter Methods
        int getWeight();
        int getStartVert();
        int getEndVert();
        
        //Setter Methods
        void setStartVert(int);
        void setWeight(int);
        void incWeight();
        void setEndVert(int);

};


#endif
