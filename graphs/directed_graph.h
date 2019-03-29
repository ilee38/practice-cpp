#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <vector>

class DirectedGraph{

  struct vertex{
    std::string element;
    std::vector<edge*> incident_out;    //list of incident outgoing edges
    std::vector<edge*> incident_in;     //list of incident incoming edges
  };

  struct edge{
    int weight = 0;
    vertex *origin = nullptr;
    vertex *destination = nullptr;
  };

  public:
    DirectedGraph();
    ~DirectedGraph();
    int vertex_count();
    int edge_count();
    edge* get_edge(vertex*, vertex*);
    int degree(vertex*);
    vertex* insert_vertex(std::string);
    edge* insert_edge(vertex*, vertex*, int);
    void remove_vertex(vertex*);
    void remove_edge(edge*);
    vertex* DFS();
    vertex* BFS();

  private:
    std::vector<vertex*> Adj_list;   //Adjacency list for the graph, containing the collection of Vertices
    int vertex_count;
    int edge_count;
};

#endif