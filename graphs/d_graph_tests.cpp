/**
 * Tests for Directed graph class implementation
*/
#include <iostream>
#include "directed_graph.h"

int main(){
  DirectedGraph DG = DirectedGraph();

  /*Create vertices*/
  DirectedGraph::vertex U = DG.insert_vertex("u");
  DirectedGraph::vertex V = DG.insert_vertex("v");
  DirectedGraph::vertex W = DG.insert_vertex("w");
  DirectedGraph::vertex Z = DG.insert_vertex("z");
  DirectedGraph::vertex A = DG.insert_vertex("a");
  DirectedGraph::vertex B = DG.insert_vertex("b");

  /*Create edges*/
  DirectedGraph::edge U_V = DG.insert_edge(&U, &V, 0);
  DirectedGraph::edge U_W = DG.insert_edge(&U, &W, 0);
  DirectedGraph::edge U_Z = DG.insert_edge(&U, &Z, 0);
  DirectedGraph::edge V_W = DG.insert_edge(&V, &W, 0);
  DirectedGraph::edge W_Z = DG.insert_edge(&W, &Z, 0);
  DirectedGraph::edge W_A = DG.insert_edge(&W, &A, 0);
  DirectedGraph::edge W_B = DG.insert_edge(&W, &B, 0);

  std::vector<DirectedGraph::vertex> BFS_order = DG.BFS();

  /*Print vertices in BFS order*/
  for(auto vertex : BFS_order){
    std::cout<<vertex.element <<", ";
  }
  std::cout<<std::endl;

}