/**
 * Implementation of DirectedGraph class, which represents a directed graph ADT.
 * The graph is maintained with an adjacency list.
*/
#include <iostream>
#include <vector>
#include "directed_graph.h"

DirectedGraph::DirectedGraph(){
  vertex_count = 0;
  edge_count = 0;
}


DirectedGraph::~DirectedGraph(){}


/*Returns the number of vertices in the graph*/
int DirectedGraph::vertex_count(){
  return vertex_count;
}


/*Returns the number of edges in the graph*/
int DirectedGraph::edge_count(){
  return edge_count;
}


/*Returns the edge from vertex u to vertex v if one exists*/
edge* DirectedGraph::get_edge(vertex *u, vertex *v){
  for(int i = 0; i < u->incident_out.size()-1; i++){
    if(u->incident_out[i]->destination == v)return u->incident_out[i];
  }
}


/*Returns the number of outgoing edges incident to vertex v*/
int DirectedGraph::degree(vertex *v){
  return v->incident_out.size();
}


/*Creates and returns a new vertex storing element x*/
vertex* DirectedGraph::insert_vertex(std::string x){
  vertex new_vertex = {x};
  Adj_list.push_back(&new_vertex);
  vertex_count++;
  return &new_vertex;
}


/*Creates and returns a new edge from vertex u to vertex v, and weight w*/
edge* DirectedGraph::insert_edge(vertex *u, vertex *v, int w){
  edge new_edge = {w, u, v};
  u->incident_out.push_back(&new_edge);
  v->incident_in.push_back(&new_edge);
  edge_count++;
  return &new_edge;
}


/*Removes vertex v and all its incident edges from the graph*/
void DirectedGraph::remove_vertex(vertex *v){
  for(int i = 0; i < v.incident_in.size()-1; i++){
    remove_edge(v.incident_in[i]);      //remove any incoming edge
  }
  vertex_count--;
  Adj_list.erase(v);
}


/*Remove edge e from the graph*/
void DirectedGraph::remove_edge(edge *e){
  delete e;
  edge_count--;
}