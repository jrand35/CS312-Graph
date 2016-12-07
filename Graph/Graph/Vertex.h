#pragma once

const int MAX_EDGES = 20;

class Vertex {
public:
	Vertex(int);
	~Vertex();
	void AddEdge(Vertex*, int);
	int GetIndex() const;
private:
	int index;
	int edgeCount;
	Edge edges[MAX_EDGES];
};

struct Edge {
	int Weight;
	Vertex *DestVertex;
};