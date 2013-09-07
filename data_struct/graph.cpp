#include <vector>

class Vertex {
public:
  int data;
  Vertex(int d):data(d){
    _adjacents = new std::vector<Vertex*>();
  }
  ~Vertex(){delete _adjacents;};
  std::vector<Vertex*>* getAdjacens() {return _adjacents;}
protected:
  std::vector<Vertex*> *_adjacents;
};

class Edge {
public:
  int weight = 1;
  Edge(Vertex* start, Vertex* end):_start(start), _end(end){}
protected:
  Vertex* _start;
  Vertex* _end;
};

class Graph {
public:
  Graph(){
    _vertices = new std::vector<Vertex*>;
    _edges = new std::vector<Edge*>;
  }
  
  ~Graph(){delete _vertices; delete _edges;};
  
  std::vector<Vertex*>* getVertices(){return _vertices;}
  std::vector<Edge*>* getEdges(){return _edges;}
protected:
  std::vector<Vertex*> *_vertices;
  std::vector<Edge*> *_edges;
};
