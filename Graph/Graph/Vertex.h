#pragma once

const int MAX_EDGES = 20;

struct Edge {
	int Weight;
	int DestVertexIndex;
};

class Vertex {
public:
	Vertex();
	Vertex(int index, int x, int y);
	~Vertex();
	void AddEdge(int otherVertex, int weight);
	int GetIndex() const;
	int GetX() const;
	int GetY() const;
private:
	int index;
	int edgeCount;
	Edge edges[MAX_EDGES];
	int x;
	int y;
};