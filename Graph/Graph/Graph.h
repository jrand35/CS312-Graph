#pragma once
#include "Vertex.h"
#include <string>
#include <fstream>
#include <list>
using namespace std;
using namespace System;

const int MAX_VERTICES = 50;

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

template<class T>
class Graph {
public:
	Graph();
	~Graph();
	void SetupMatrices();
	void LoadEdges(string filename);
	int VertexCount() const;
	void AddVertex(int index, T type);
	Vertex<T> *GetVertex(int index);
	int GetEdgeWeight(int vertex1, int vertex2);
	//Fix, Prim and Kruskal should ignore directions
	void Prim(int vertex);
	void Kruskal();
	void DepthFirstSearch(int vertex, String ^&result);
	void BreadthFirstSearch(int vertex, String ^&result);
	string GetEdgeWeights();
	void MarkEntireGraph(bool mark);
	void VisitEntireGraph(bool mark);
	bool CheckIsConnected();
	void HasCycle(Vertex<T> *startVertex, bool &result);
private:
	int **adjacencyMatrix;
	bool **edgeMarkedMatrix;
	Vertex<T> vertices[MAX_VERTICES];
	list<Edge*> spanningTreeEdges;
	int treeEdgeCount;
	int vertexCount;
	void PrimStep();
	void Connect(int vertex1, int vertex2, int weight);
};