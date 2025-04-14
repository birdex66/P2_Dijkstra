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

        // Getter Methods
        int getIndex();
        int getDegree();
        bool getVisit();

        // Setter Methods
        void setIndex(int);
        void setDegree(int);
        void setVisit(bool);
};


#endif
