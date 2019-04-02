/**
 * Implementation of DirectedGraph class, which represents a directed graph ADT.
 * The graph is maintained with an adjacency list.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "directed_graph.h"

DirectedGraph::DirectedGraph():_vertex_count(0), _edge_count(0){}


DirectedGraph::~DirectedGraph(){}


/*Returns the number of vertices in the graph*/
int DirectedGraph::vertex_count(){
  return _vertex_count;
}


/*Returns the number of edges in the graph*/
int DirectedGraph::edge_count(){
  return _edge_count;
}


/*Returns the edge from vertex u to vertex v if one exists*/
/*DirectedGraph::edge DirectedGraph::get_edge(DirectedGraph::vertex *u, DirectedGraph::vertex *v){
  for(int i = 0; i < Adj_list[u].size()-1; i++){
    if(Adj_list[u][i].element == v->element){
      edge e;
      e.origin = u;
      e.destination = v;
      return e;
    }
  }
} */


/*Returns the number of outgoing edges incident to vertex v*/
/*int DirectedGraph::degree(vertex *v){
  return Adj_list[v].size();
} */


/*Creates and returns a new vertex storing element x*/
DirectedGraph::vertex DirectedGraph::insert_vertex(std::string x){
  DirectedGraph::vertex new_vertex;
  new_vertex.element = x;
  std::vector<vertex> adj;
  Adj_list.insert(make_pair(new_vertex, adj));
  _vertex_count++;
  return new_vertex;
}


/*Creates and returns a new edge from vertex u to vertex v, and weight w*/
DirectedGraph::edge DirectedGraph::insert_edge(DirectedGraph::vertex *u, DirectedGraph::vertex *v, int w){
  edge new_edge;
  new_edge.weight = w;
  new_edge.origin = u;
  new_edge.destination = v;
  Adj_list[*u].push_back(*v);
  _edge_count++;
  return new_edge;
}


/*Returns an array for vertices corresponding to the BFS order*/
std::vector<DirectedGraph::vertex> DirectedGraph::BFS(){
  std::vector<DirectedGraph::vertex> V;
  std::queue<DirectedGraph::vertex> Q;
  for(auto v : Adj_list){    //traverse Adj list
    if(!(v.first.explored)){
      v.first.explored = true;
      Q.push(v.first);
      for(auto vertex : v.second){
        if(!(vertex.explored)){
          vertex.explored = true;
          Q.push(vertex);
        }
      }
    }
    V.push_back(Q.front());
    Q.pop();
  }
  /*while(!Q.empty()){
    V.push_back(Q.front());
    Q.pop();
  }*/
  return V;
}