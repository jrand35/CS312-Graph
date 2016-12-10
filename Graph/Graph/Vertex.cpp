#include "Vertex.h"

Vertex::Vertex(){
	index = 0;
	x = 0;
	y = 0;
	edgeCount = 0;
}

Vertex::Vertex(int index, int x, int y) {
	Vertex::index = index;
	Vertex::x = x;
	Vertex::y = y;
	edgeCount = 0;
}

Vertex::~Vertex(){

}

void Vertex::Set(int index, int x, int y){
	Vertex::index = index;
	Vertex::x = x;
	Vertex::y = y;
}

void Vertex::AddEdge(int otherVertex, int weight) {
	edges[edgeCount].DestVertexIndex = otherVertex;
	edges[edgeCount].Weight = weight;
	edgeCount++;
}

void Vertex::Mark(bool mark){
	marked = mark;
}

int Vertex::GetIndex() const
{
	return index;
}

int Vertex::GetX() const{
	return x;
}

int Vertex::GetY() const{
	return y;
}

int Vertex::EdgeCount() const{
	return edgeCount;
}

Edge *Vertex::GetEdge(int index){
	return &edges[index];
}