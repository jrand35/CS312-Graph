#pragma once
#include "Vertex.h"
#include <string>
#include <fstream>
using namespace std;

const int MAX_VERTICES = 50;

class Graph {
public:
	Graph(bool randomize, int vertices);
	~Graph();
	void Load(string filename);
private:
	Vertex vertices[MAX_VERTICES];
	int vertexCount;
	void Connect(int vertex1, int vertex2, int weight);
};