#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int Vertices;
	int TotalCost;
public:
	Graph()
	{
		TotalCost = 0;
		Vertices = 0;
	}
	Graph(int Vertices)
	{
		TotalCost = 0;
		this->Vertices = Vertices;	
	}
	int minDistance(bool Visited[] , int Distances[])
	{
		int min = INT_MAX;
		int min_index;
		
		for (int i = 0 ; i < Vertices ; i++)
		{
			if (Visited[i] == false && Distances[i] <= min)
			{
				min = Distances[i];
				min_index = i;
			}
		}
		return min_index;
	}
	void DijkstraAlgo(int Graph[9][9])
	{
		int edges = 0;
		int row , col;
		bool Visited[Vertices];
		int Distances[Vertices];
		for (int i = 0 ; i < Vertices ; i++)
		{
			Visited[i] = false;
			Distances[i] = INT_MAX;
		}
		
		Distances[0] = 0;
		
		for (int count = 0 ; count < Vertices - 1; count++)
		{
			int U = minDistance(Visited,Distances);
		
			Visited[U] = true;
			
			for (int i = 0 ; i < Vertices ; i++)
			{
				if ((!Visited[i]) && (Graph[U][i]) && (Distances[U] != INT_MAX) && (Distances[U] + Graph[U][i] < Distances[i]))
				{
					Distances[i] = Distances[U] + Graph[U][i];
				}
			}	
		}
		cout << "Vertex \t\t Distance from Source\n"; 
	    for (int i = 0; i < Vertices; i++) 
	        cout << i << " \t\t " << Distances[i] << endl;
		
	}
};
int main()
{
	int V;
	cout<<"Enter the number of vertices: ";
	cin >> V;
	Graph G(V);
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	G.DijkstraAlgo(graph); 		


}

