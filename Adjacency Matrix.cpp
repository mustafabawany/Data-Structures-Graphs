#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
	int **Array;
	int Vertices;
public:
	Graph()
	{
		Array = 0;
		Vertices = 0;
	}
	Graph(int Vertices)
	{
		this->Vertices = Vertices;
		Array = new int* [Vertices];
		for (int i = 0 ; i < Vertices ; i++)
		{
			Array[i] = new int[Vertices];
		}
		for(int i = 0 ; i < Vertices ; i++)
		{
			for (int j = 0 ; j < Vertices ; j++)
			{
				Array[i][j] = 0;
			}
		}
	}
	void AddEdge(int vertex , int neighbouring)
	{
		Array[vertex][neighbouring] = 1;
		Array[neighbouring][vertex] = 1;
	}
	void Display()
	{
		for(int i = 0 ; i < Vertices ; i++)
		{
			for (int j = 0 ; j < Vertices ; j++)
			{
				cout << Array[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph G(6);
	G.AddEdge(0, 1);
    G.AddEdge(0, 2);
    G.AddEdge(1, 2);
    G.AddEdge(2, 0);
    G.AddEdge(2, 3);
    G.AddEdge(3, 3);
	G.Display();





}

