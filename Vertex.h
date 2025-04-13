#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
    public:
        Vertex();
        Vertex(int,int);
        int getIndex();
        int getDegree();
        void setIndex(int);
        void setDegree(int);
};


#endif
