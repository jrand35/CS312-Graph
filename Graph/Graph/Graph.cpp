#include "Graph.h"

Graph::Graph(){
	vertexCount = 0;
	treeEdgeCount = 0;
}

Graph::Graph(bool randomize, int vertices){
	vertexCount = 0;
	treeEdgeCount = 0;
	if (randomize){

	}
}

Graph::~Graph(){
	for (int i = 0; i < vertexCount; i++){
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}

void Graph::LoadVertices(string filename){
	ifstream file;
	file.open(filename);
	if (file.fail()){
		file.close();
		System::Windows::Forms::Application::Exit();
	}
	while (!file.eof()){
		string n, x, y;
		file >> n >> x >> y;
		if (n == "")
			continue;
		else if (n[0] == 'T'){
			//May not be used
			continue;
		}
		else{
			AddVertex(stoi(n), stoi(x), stoi(y));
		}
	}
	file.close();
}

void Graph::LoadEdges(string filename){
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
			Connect(stoi(n1), stoi(n2), stoi(w));
		}
	}
	file.close();
	edges.sort();
	SetupAdjacencyMatrix();
}

int Graph::VertexCount() const{
	return vertexCount;
}

Vertex *Graph::GetVertex(int index) {
	return &vertices[index];
}

void Graph::Prim(int vertex){
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

void Graph::PrimStep(){
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

bool Graph::Kruskal(){
	return true;
}

string Graph::GetEdgeWeights(){
	list<Edge*>::iterator it;
	string str = "";
	for (it = edges.begin(); it != edges.end(); it++){
		str += to_string((*it)->Weight) + " ";
	}
	return str;
}

void Graph::MarkEntireGraph(bool mark){
	for (int i = 0; i < vertexCount; i++){
		vertices[i].Mark(mark);
	}
	for (list<Edge*>::iterator it = edges.begin(); it != edges.end(); it++){
		(*it)->Marked = mark;
	}
}

void Graph::AddVertex(int index, int x, int y){
	vertices[vertexCount].Set(index, x, y);
	vertexCount++;
}

void Graph::Connect(int vertex1, int vertex2, int weight){
	Edge *e = vertices[vertex1].AddEdge(vertex2, weight);
	edges.push_back(e);
}

void Graph::SetupAdjacencyMatrix(){
	//First index should be source vertex, second should be destination vertex
	adjacencyMatrix = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++){
		adjacencyMatrix[i] = new int[vertexCount];
		for (int j = 0; j < vertexCount; j++){
			adjacencyMatrix[i][j] = 0;
		}
	}
}