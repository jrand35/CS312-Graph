#include "Vertex.h"

Vertex::Vertex(){
	marked = false;
	index = 0;
	x = 0;
	y = 0;
	edgeCount = 0;
}

Vertex::Vertex(int index, int x, int y) {
	marked = false;
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

Edge *Vertex::AddEdge(int otherVertex, int weight) {
	edges[edgeCount].DestVertexIndex = otherVertex;
	edges[edgeCount].Weight = weight;
	edges[edgeCount].Marked = false;
	edgeCount++;
	return &edges[edgeCount - 1];
}

void Vertex::Mark(bool mark){
	marked = mark;
}

bool Vertex::IsMarked() const{
	return marked;
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
	return (edges + index);
}

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