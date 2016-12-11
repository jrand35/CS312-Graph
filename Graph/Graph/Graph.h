#pragma once
#include "Vertex.h"
#include <string>
#include <fstream>
#include <list>
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
	void Prim(int vertex);
	bool Kruskal();
	string GetEdgeWeights();
	void MarkEntireGraph(bool mark);
	bool CheckIsConnected();
private:
	int **adjacencyMatrix;
	Vertex vertices[MAX_VERTICES];
	list<Edge*> edges;
	list<Edge*> spanningTreeEdges;
	int treeEdgeCount;
	int vertexCount;
	void PrimStep();
	void AddVertex(int index, int x, int y);
	void Connect(int vertex1, int vertex2, int weight);
	void SetupAdjacencyMatrix();
};