#include "Graph.h"

Graph::Graph(){
	vertexCount = 0;
}

Graph::Graph(bool randomize, int vertices){
	vertexCount = 0;
	if (randomize){
	}
}

Graph::~Graph(){

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
}

int Graph::VertexCount() const{
	return vertexCount;
}

Vertex *Graph::GetVertex(int index) {
	return &vertices[index];
}

void Graph::AddVertex(int index, int x, int y){
	vertices[index].Set(index, x, y);
	vertexCount++;
}

void Graph::Connect(int vertex1, int vertex2, int weight){
	vertices[vertex1].AddEdge(vertex2, weight);
}