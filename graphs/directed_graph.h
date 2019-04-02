#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class DirectedGraph{

  public:

    struct vertex{
      std::string element;
      bool explored = false;
    };

    struct edge{
      int weight = 0;
      struct vertex *origin = nullptr;
      struct vertex *destination = nullptr;
    };

    DirectedGraph();
    ~DirectedGraph();
    int vertex_count();
    int edge_count();
    //edge get_edge(vertex*, vertex*);
    //int degree(vertex*);
    vertex insert_vertex(std::string);
    edge insert_edge(vertex*, vertex*, int);

    //std::vector<vertex> DFS();
    std::vector<vertex> BFS();

  private:
    std::unordered_map<vertex, std::vector<vertex> > Adj_list;   //Adjacency list for the graph, containing the collection of Vertices
    int _vertex_count;
    int _edge_count;
};

#endif