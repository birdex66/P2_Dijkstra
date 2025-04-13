#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
       bool visited;
    public:
        Vertex();
        Vertex(int,int);

        int getIndex();
        int getDegree();
        bool getVisit();

        void setIndex(int);
        void setDegree(int);
        void setVisit(bool);
};


#endif
