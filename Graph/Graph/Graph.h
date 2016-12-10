#pragma once
#include "Vertex.h"
#include <string>
#include <fstream>
using namespace std;

const int MAX_VERTICES = 50;

class Graph {
public:
	Graph();
	Graph(bool randomize, int vertices);
	~Graph();
	void LoadVertices(string filename);
	void LoadEdges(string filename);
	int VertexCount() const;
	Vertex *GetVertex(int index);
private:
	Vertex vertices[MAX_VERTICES];
	int vertexCount;
	void AddVertex(int index, int x, int y);
	void Connect(int vertex1, int vertex2, int weight);
};