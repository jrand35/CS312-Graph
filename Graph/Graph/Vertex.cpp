#include "Vertex.h"

Vertex::Vertex(int index) {
	Vertex::index = index;
	edgeCount = 0;
}

void Vertex::AddEdge(Vertex *other, int weight) {
	edges[edgeCount].DestVertex = other;
	edges[edgeCount].Weight = weight;
	edgeCount++;
}

int Vertex::GetIndex() const
{
	return index;
}
