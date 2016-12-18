#pragma once
const int MAX_EDGES = 20;

template<class T>
class Vertex {
public:
	Vertex();
	Vertex(int index, T type);
	~Vertex();
	void Set(int index, T type);
	//AddEdge(int otherVertex, int weight);
	void Mark(bool mark);
	void Visit(bool mark);
	bool IsMarked() const;
	bool IsVisited() const;
	int GetIndex() const;
	T GetT() const;
	//int EdgeCount() const;
	//Edge *GetEdge(int index);
private:
	int index;
	/*int edgeCount;
	Edge edges[MAX_EDGES];*/
	T type;
	bool marked;
	bool visited;
};

#include "Vertex.template"