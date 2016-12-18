#pragma once
const int MAX_EDGES = 20;

template<class T>
class Vertex {
public:
	Vertex();
	Vertex(int index, T type);
	~Vertex();
	void Set(int index, T type);
	void Mark(bool mark);
	void Visit(bool mark);
	void SetDistance(int dist);
	void SetPrevVertex(int prev);
	int GetDistance() const;
	int GetPrevVertex() const;
	bool IsMarked() const;
	bool IsVisited() const;
	int GetIndex() const;
	T GetT() const;
private:
	int index;
	T type;
	bool marked;
	bool visited;
	int distance;
	int prevVertex;
};

#include "Vertex.template"