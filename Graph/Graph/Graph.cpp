#include "Graph.h"

template<class T>
Graph<T>::Graph(){
	vertexCount = 0;
	treeEdgeCount = 0;
}

template<class T>
Graph<T>::~Graph(){
	for (int i = 0; i < vertexCount; i++){
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

template<class T>
void Graph<T>::SetupMatrices(){
	//First index should be source vertex, second should be destination vertex
	adjacencyMatrix = new int*[vertexCount];
	edgeMarkedMatrix = new bool*[vertexCount];
	edgeVisitedMatrix = new bool*[vertexCount];
	for (int i = 0; i < vertexCount; i++){
		adjacencyMatrix[i] = new int[vertexCount];
		edgeMarkedMatrix[i] = new bool[vertexCount];
		edgeVisitedMatrix[i] = new bool[vertexCount];
		for (int j = 0; j < vertexCount; j++){
			adjacencyMatrix[i][j] = 0;
			edgeMarkedMatrix[i][j] = false;
			edgeVisitedMatrix[i][j] = false;
		}
	}
}

template<class T>
void Graph<T>::LoadEdges(string filename){
	ifstream file;
	file.open(filename);
	if (file.fail()) {
		file.close();
		System::Windows::Forms::Application::Exit();
	}
	while (!file.eof()) {
		string n1, n2, w;
		file >> n1 >> n2 >> w;
		if (n1 != "" && n1 != "Vertex")
		{
			adjacencyMatrix[n1][n2] = w;
		}
	}
	file.close();
}

template<class T>
int Graph<T>::VertexCount() const{
	return vertexCount;
}

template<class T>
void Graph<T>::AddVertex(int index, T type){
	vertices[vertexCount].Set(index, type);
	vertexCount++;
}

template<class T>
Vertex<T> *Graph<T>::GetVertex(int index) {
	return &vertices[index];
}

template<class T>
int Graph<T>::GetEdgeWeight(int vertex1, int vertex2){
	return adjacencyMatrix[vertex1][vertex2];
}

template<class T>
void Graph<T>::Prim(int vertex){
	spanningTreeEdges.clear();
	treeEdgeCount = 0;
	if (vertices[vertex].IsMarked()){
		return;
	}
	vertices[vertex].Mark(true);
	for (int i = 0; i < vertices[vertex].EdgeCount(); i++){
		spanningTreeEdges.push_back(vertices[vertex].GetEdge(i));
		Edge *e = vertices[vertex].GetEdge(i);
		treeEdgeCount++;
	}
	PrimStep();
}

template<class T>
void Graph<T>::PrimStep(){
	list<Edge*>::iterator it;
	Edge *smallestEdge = nullptr;
	Vertex *v = nullptr;
	int min = 99999;
	for (it = spanningTreeEdges.begin(); it != spanningTreeEdges.end(); it++){
		v = &vertices[(*it)->DestVertexIndex];
		if ((*it)->Weight < min && !v->IsMarked()){
			min = (*it)->Weight;
			smallestEdge = *it;
		}
	}
	if (min != 99999){
		v = &vertices[smallestEdge->DestVertexIndex];
		v->Mark(true);
		smallestEdge->Marked = true;

		//Add the edges connected to the vertex to the spanning tree
		for (int i = 0; i < v->EdgeCount(); i++){
			spanningTreeEdges.push_back(v->GetEdge(i));
			treeEdgeCount++;
		}
		PrimStep();
	}
	else{
		return;
	}
}

template<class T>
void Graph<T>::Kruskal(){
	list<Edge*>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++){
		(*it)->Marked = true;
		bool result = false;
		HasCycle(&vertices[(*it)->vertexIndex], result);
		if (result){
			(*it)->Marked = false;
		}
		if ((*it)->Marked){
			vertices[(*it)->vertexIndex].Mark(true);
			vertices[(*it)->DestVertexIndex].Mark(true);
		}
		VisitEntireGraph(false);
	}
}

template<class T>
void Graph<T>::DepthFirstSearch(int vertex, String ^&result){
	if (vertices[vertex].IsVisited())
		return;

	vertices[vertex].Visit(true);
	result += vertices[vertex].GetIndex().ToString() + " ";
	for (int i = 0; i < vertices[vertex].EdgeCount(); i++){
		DepthFirstSearch(vertices[vertex].GetEdge(i)->DestVertexIndex, result);
	}
}

template<class T>
void Graph<T>::BreadthFirstSearch(int vertex, String ^&result){
	if (vertices[vertex].IsVisited())
		return;

	vertices[vertex].Visit(true);
	for (int i = 0; i < vertices[vertex].EdgeCount(); i++){
		if (!vertices[vertices[vertex].GetEdge(i)->DestVertexIndex].IsMarked()){
			result += vertices[vertex].GetEdge(i)->DestVertexIndex.ToString() + " ";
			vertices[vertices[vertex].GetEdge(i)->DestVertexIndex].Mark(true);
		}
	}
	for (int i = 0; i < vertices[vertex].EdgeCount(); i++){
		BreadthFirstSearch(vertices[vertex].GetEdge(i)->DestVertexIndex, result);
	}
}

template<class T>
string Graph<T>::GetEdgeWeights(){
	list<Edge*>::iterator it;
	string str = "";
	for (it = edges.begin(); it != edges.end(); it++){
		str += to_string((*it)->Weight) + " ";
	}
	return str;
}

template<class T>
void Graph<T>::MarkEntireGraph(bool mark){
	for (int i = 0; i < vertexCount; i++){
		vertices[i].Mark(mark);
	}
	for (int i = 0; i < vertexCount; i++){
		for (int j = 0; j < vertexCount; j++){
			edgeMarkedMatrix[i][j] = false;
		}
	}
}

template<class T>
void Graph<T>::VisitEntireGraph(bool mark){
	for (int i = 0; i < vertexCount; i++){
		vertices[i].Visit(mark);
	}
	for (int i = 0; i < vertexCount; i++){
		for (int j = 0; j < vertexCount; j++){
			edgeVisitedMatrix[i][j] = false;
		}
	}
}

template<class T>
bool Graph<T>::CheckIsConnected() {
	bool connected = false;
	for (int i = 0; i < vertexCount; i++){
		connected = false;
		for (int j = 0; j < vertexCount; j++){
			if (adjacencyMatrix[i][j] != 0 || adjacencyMatrix[j][i] != 0){
				connected = true;
				continue;
			}
		}
		if (!connected)
			return false;
	}
	return true;
}

template<class T>
void Graph<T>::HasCycle(Vertex<T> *vertex, bool &result) {
	if (vertex->IsVisited()){
		result = true;
		return;
	}
	vertex->Visit(true);
	for (int i = 0; i < vertex->EdgeCount(); i++){
		if (!vertex->GetEdge(i)->Visited && vertex->GetEdge(i)->Marked){
			vertex->GetEdge(i)->Visited = true;
			HasCycle(&vertices[vertex->GetEdge(i)->DestVertexIndex], result);
		}
	}
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