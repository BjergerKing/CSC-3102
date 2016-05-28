// Graph.hpp

#ifndef Graph_hpp
#define Graph_hpp

#include <vector>

struct Vertex
{
    char label;
    std::vector<Vertex*> adjacent;
    bool visited;
    
    Vertex(char a) {
        label = a;
        visited = false;
    }
};

class Graph
{
public:
    void add(char a, char b);
    void remove(char a, char b);
    bool isVertex(Vertex *x);
    Vertex* find(char x);
    bool isAdjacent(Vertex *x, Vertex *y);
    void unvisitAll();
    void insert(Vertex *x);
    void breadth(char a);
    void depth(char a);
private:
    std::vector<Vertex*> G;
};


#endif
