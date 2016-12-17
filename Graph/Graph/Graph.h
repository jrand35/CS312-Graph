#pragma once
#include "Vertex.h"
#include <string>
#include <fstream>
#include <list>
using namespace std;
using namespace System;

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
	//Fix, Prim and Kruskal should ignore directions
	void Prim(int vertex);
	void Kruskal();
	void DepthFirstSearch(int vertex, String ^&result);
	void BreadthFirstSearch(int vertex, String ^&result);
	string GetEdgeWeights();
	void MarkEntireGraph(bool mark);
	void VisitEntireGraph(bool mark);
	bool CheckIsConnected();
	void HasCycle(Vertex *startVertex, bool &result);
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