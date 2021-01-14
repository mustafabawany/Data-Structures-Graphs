#include<bits/stdc++.h>
using namespace std;

//class Node{
//	friend class Graph;
//private:
//	Node *Adjacent;
//	int Data;
//	int Weight;
//public:
//	Node()
//	{
//		Adjacent = NULL;
//		Data = 0;
//		Weight = 0;
//	}
//	Node (int Data , int Weight)
//	{
//		Adjacent = NULL;
//		this->Data = Data;
//		this->Weight = Weight;
//	}
//};

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
	void PrimsAlgo(int Graph[5][5])
	{
		int edges = 0;
		int row , col;
		bool Visited[Vertices];
		for (int i = 0 ; i < Vertices ; i++)
		{
			Visited[i] = false;
		}
		
		Visited[0] = true;							//First is always visited
		cout << "Edge : Weight" << endl;
		
		while(edges < Vertices - 1)
		{
			int min = 1000;
			row = 0;
			col = 0;
			
			for (int i = 0 ; i < Vertices ; i++)
			{
				if (Visited[i] == true)
				{
					for (int j = 0 ; j < Vertices ; j++)
					{
						if (!Visited[j] && Graph[i][j])
						{
							if (min > Graph[i][j])
							{
								min = Graph[i][j];
								row = i;
								col = j;
							}
						}	
					}
				}
			}
			cout << row << " --> " << col << " : " << Graph[row][col] << endl;
			TotalCost += Graph[row][col];
			Visited[col] = true;
			edges++; 
		} 
		cout << endl << "Total Cost: " << TotalCost;
	}
};
int main()
{
	int V;
	cout<<"Enter the number of vertices: ";
	cin >> V;
	Graph G(V);
	int graph[5][5] = { { 0, 2, 0, 6, 0 },  
			            { 2, 0, 3, 8, 5 },  
			            { 0, 3, 0, 0, 7 },  
			            { 6, 8, 0, 0, 9 },  
			            { 0, 5, 7, 9, 0 } }; 
	G.PrimsAlgo(graph); 		


}

