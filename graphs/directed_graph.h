#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>

class DirectedGraph{

  struct vertex{
    std::string label;
  };

  struct edge{
    int weight = 0;
    vertex *origin = nullptr;
    vertex *destination = nullptr;
  };

  public:
    int vertex_count();
    int edge_count();
    edge* get_edge(vertex*, vertex*);
    int degree(vertex*);
    void insert_edge(vertex*, vertex*, int);
    void remove_vertex(vertex*);
    void remove_edge(edge*);
    vertex* DFS();
    vertex* BFS();

  private:
    vertex* Adj;
    int vertex_count;
    int edge_count;
};

#endif