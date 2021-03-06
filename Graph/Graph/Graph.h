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
	bool Forward;
	bool Marked;
	bool Visited;

	bool Edge::operator<(Edge &other){
		return Weight < other.Weight;
	}
	bool Edge::operator>(Edge &other){
		return Weight > other.Weight;
	}
	bool Edge::operator==(Edge &other){
		return Weight == other.Weight;
	}
	bool Edge::operator<=(Edge &other){
		return Weight <= other.Weight;
	}
	bool Edge::operator>=(Edge &other){
		return Weight >= other.Weight;
	}
};

template<class T>
class Graph {
public:
	Graph();
	~Graph();
	void SetupMatrices();
	void LoadEdges(string filename);
	void LoadRandomEdges();
	int VertexCount() const;
	void AddVertex(int index, T type);
	Vertex<T> *GetVertex(int index);
	int GetEdgeWeight(int vertex1, int vertex2);
	bool GetEdgeMarked(int vertex1, int vertex2);
	void Prim(int vertex, System::Windows::Forms::ListBox::ObjectCollection ^&output);
	void Kruskal(System::Windows::Forms::ListBox::ObjectCollection ^&output);
	//Dijkstra's Algorithm using Breadth-first searches
	bool Dijkstra(int start, int end);
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
	bool **edgeVisitedMatrix;
	bool *inTreeMatrix;
	void VisitAllVertices(int vertex);
	bool AllVerticesReached();
	void VisitAllMarkedVertices(int vertex);
	bool AllReachableVerticesConnected();
	Vertex<T> vertices[MAX_VERTICES];
	list<Edge> spanningTreeEdges;
	int treeEdgeCount;
	int vertexCount;
	void PrimStep(System::Windows::Forms::ListBox::ObjectCollection ^&output);
	void DijkstraStep(int vertex, int end, int currentDist, bool &success);
	list<Edge> GetSortedEdges();
};

#include "Graph.template"