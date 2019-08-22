// DFSandBFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream> 
#include<list> 
#include <vector>

using namespace std;

// Graph class represents a directed graph 
// using adjacency list representation 

class Graph {
	int V;				// No. of vertices    
	list<int>* adj; // Pointer to an array containing adjacency lists
	void DFSUtil(int v, bool visited[]); // A recursive function used by DFS

public:
	Graph(int V);   // Constructor 
	void addEdge(int v, int w); // function to add an edge to graph 
	void DFS(); // prints DFS traversal of the complete graph 
	void BFS(int s); // prints BFS traversal from a given source s
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::DFSUtil(int v, bool visited[]) {
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;

	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// DFS traversal of the vertices 
// It uses recursive DFSUtil() 
void Graph::DFS() {

	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal 
	// starting from all vertices one by one 
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			DFSUtil(i, visited);

}



// Breadth First Search 
void Graph:: BFS(int s)
{
	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS 
	list<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

}



int main() {

	// Create a graph given in the above diagram 
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"<<endl;
	g.DFS();

	Graph gnew(4);

	gnew.addEdge(0, 1);
	gnew.addEdge(0, 2);
	gnew.addEdge(1, 2);
	gnew.addEdge(2, 0);
	gnew.addEdge(2, 3);
	gnew.addEdge(3, 3);

	cout << "\n" <<"Following is Breadth First Traversal" << endl;

	gnew.BFS(2);

	return 0;
    
}
