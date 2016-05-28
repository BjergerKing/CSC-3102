// Graph.cpp

#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <stack>


void Graph::add(char a, char b)
{
    Vertex *x = find(a);
    Vertex *y = find(b);
    
    if (x == nullptr)
    {
        x = new Vertex(a);
    }
    
    if (y == nullptr)
    {
        y = new Vertex(b);
    }
    
    // If x or y are not in the graph, insert them
    if (!isVertex(x))
    {
        insert(x);
    }
    
    if (!isVertex(y))
    {
        insert(y);
    }
    
    // If y is not already adjacent to x, add the edge
    if (!isAdjacent(x, y))
    {
        x->adjacent.push_back(y);
    }
    
}


// Remove an edge from the graph
void Graph::remove(char a, char b)
{
    Vertex *x = find(a);
    Vertex *y = find(b);
    
    // If either vertex was not found we can exit because the edge does not exist
    if (x == nullptr || y == nullptr) return;
    
    
    unsigned long size = x->adjacent.size();
    
    // If the edge (x,y) exists, find y in the x adjacency list and erase it
    if (isAdjacent(x, y))
    {
        for (int i = 0; i < size; i++)
        {
            if (x->adjacent[i] == y)
            {
                x->adjacent.erase(x->adjacent.begin() + i);
                return;
            }
        }
    }
}


// Search the graph for a vertex x
bool Graph::isVertex(Vertex *x)
{
    unsigned long size = G.size();
    
    for (int i = 0; i < size; i++)
    {
        if (G[i] == x)
            return true;
    }
    return false;
}


// Search the graph for a vertex label and return the vertex
Vertex* Graph::find(char x)
{
    unsigned long size = G.size();
    
    for (int i = 0; i < size; i++)
    {
        if (G[i]->label == x)
            return G[i];
    }
    
    // If we get here it was not found
    return nullptr;
}


// Check if vertex x is adjacent to vertex y
bool Graph::isAdjacent(Vertex *x, Vertex *y)
{
    unsigned long size = x->adjacent.size();
    
    for (int i = 0; i < size; i++)
    {
        if (x->adjacent[i] == y)
        {
            return true;
        }
    }
    return false;
}


// Mark all verticies as unvisited
void Graph::unvisitAll()
{
    unsigned long size = G.size();
    
    for (int i = 0; i < size; i++)
    {
        G[i]->visited = false;
    }
}


// Insert a single vertex to the graph
void Graph::insert(Vertex *x)
{
    G.push_back(x);
}


// Breadth-first graph traversal
void Graph::breadth(char a)
{
    Vertex *x = find(a);
    if (x == nullptr) return;
    
    
    unvisitAll();
    std::queue<Vertex*> Q;
    
    Q.push(x);
    while (!Q.empty())
    {
        Vertex *v = Q.front();
        std::cout << v->label << " ";
        Q.pop();
        v->visited = true;
        
        for (int i = 0; i < v->adjacent.size(); i++)
        {
            if (!v->adjacent[i]->visited)
            {
                Q.push(v->adjacent[i]);
            }
        }
    }
    std::cout << std::endl;
}


// Depth-first graph traversal
void Graph::depth(char a)
{
    Vertex *x = find(a);
    if (x == nullptr) return;
    
    unvisitAll();
    
    std::stack<Vertex*> S;
    
    S.push(x);
    while (!S.empty())
    {
        Vertex *v = S.top();
        std::cout << v->label << " ";
        S.pop();
        v->visited = true;
        
        for (int i = 0; i < v->adjacent.size(); i++)
        {
            if (!v->adjacent[i]->visited)
            {
                S.push(v->adjacent[i]);
            }
        }
    }
    std::cout << std::endl;
}
