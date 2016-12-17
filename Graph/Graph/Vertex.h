#pragma once

const int MAX_EDGES = 20;

struct Edge {
	int Weight;
	int vertexIndex;
	int DestVertexIndex;
	bool Marked;
	bool Visited;
	bool operator<(Edge &other);
	bool operator>(Edge &other);
	bool operator==(Edge &other);
	bool operator<=(Edge &other);
	bool operator>=(Edge &other);
};

class Vertex {
public:
	Vertex();
	Vertex(int index, int x, int y);
	~Vertex();
	void Set(int index, int x, int y);
	Edge *AddEdge(int otherVertex, int weight);
	void Mark(bool mark);
	void Visit(bool mark);
	bool IsMarked() const;
	bool IsVisited() const;
	int GetIndex() const;
	int GetX() const;
	int GetY() const;
	int EdgeCount() const;
	Edge *GetEdge(int index);
private:
	int index;
	int edgeCount;
	Edge edges[MAX_EDGES];
	int x;
	int y;
	bool marked;
	bool visited;
};