#include "Graph.h"

Graph::Graph(bool randomize, int vertices){
	vertexCount = 0;
	if (randomize){
	}
}

Graph::~Graph(){

}

void Graph::Load(string filename){
	ifstream file;
	file.open("Small Graph.txt");
	if (file.fail()) {
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

void Graph::Connect(int vertex1, int vertex2, int weight){
	vertices[vertex1].AddEdge(vertex2, weight);
}