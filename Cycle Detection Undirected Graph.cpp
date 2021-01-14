#include<bits/stdc++.h>
using namespace std;

class Node{
	friend class SingleLinkedList;
	friend class Graph;
private:
	Node *Next;
	int Data;
public:
	Node ()
	{
		Next = NULL;
		Data = 0;
	}
	Node (int Data)
	{
		Next = NULL;
		this->Data = Data;
	}
};

class SingleLinkedList{
private:	
	Node *Head;
	int Size;
public:
	SingleLinkedList ()
	{
		Size = 0;
		Head = NULL;
	}
	void InsertAtLast (int Value)
	{
		Node *n = new Node(Value);
		Node *tempPtr = new Node();
		tempPtr = Head;
		if (tempPtr == NULL)
		{
			Head = n;
		}
		else 
		{
			while (tempPtr->Next != NULL)												// Traversing
			{
				tempPtr = tempPtr->Next;
			}
			tempPtr->Next = n;				
		}
		Size++;
	}
	
	void DisplayList ()
	{
		Node *tempPtr = new Node();
		tempPtr = Head;
		cout << "\nLinked List: ";
		while (tempPtr != NULL)
		{
			cout << tempPtr->Data << " " ;
			tempPtr = tempPtr->Next;
		}
		cout << endl;
		delete tempPtr;

	}
	int Get_Size()
	{
		return Size;
	}
	Node* GetHead()
	{
		return Head;
	}
	Node* GetTail()
	{
		Node *tempPtr = Head;
		while(tempPtr->Next != NULL)
		{
			tempPtr = tempPtr->Next;
		}
		return tempPtr;
	}
};

class Graph{
private:
	int Vertices;
	bool *Visited;
	int *InDegree;
	SingleLinkedList *L;
public:	
	Graph(int V)
	{
		Vertices = V;
		L = new SingleLinkedList[Vertices];
		Visited = new bool[Vertices];
		InDegree = new int[Vertices];
		for(int i = 0 ; i < Vertices ; i++)
		{
			Visited[i] = false;
			InDegree[i] = 0;
		}
	}
	
	void AddEdges(int Vertex , int NeighbouringEdge)
	{
		L[Vertex].InsertAtLast(NeighbouringEdge);
		L[NeighbouringEdge].InsertAtLast(Vertex);
	}

	bool CycleDetection()
	{
		for (int i = 0 ; i < Vertices ; i++)
		{
			if (!Visited[i])
			{
				CycleDetectionRecursion(i , -1);
				return true;
			}
		}
		return false;
	}
	
	bool CycleDetectionRecursion(int Vertex , int Parent)
	{
		Visited[Vertex] = true;
		
		for (Node *tempPtr = L[Vertex].GetHead() ; tempPtr != NULL ; tempPtr = tempPtr->Next)
		{
			if(!Visited[tempPtr->Data])
			{
				if(CycleDetectionRecursion(Vertex,Parent))
				{
					return true;
				}	
			}
			else if (tempPtr->Data != Parent)
			{
				return true;
			}
		}
		return false;
	}
	void DisplayGraph()
	{
		for (int i = 0 ; i < Vertices ; i++)
		{
			Node *tempPtr = new Node();
			tempPtr = L[i].GetHead();
			cout << endl << "\nVertex " << i << ": ";
			for (int j = 0 ; j < L[i].Get_Size() ; j++)
			{
				cout << tempPtr->Data << " ";
				tempPtr = tempPtr->Next;
			}
			cout << endl;
		}
	}
};
int main()
{
	int V = 0 ,E = 0,N = 0,Option = 0;
	cout << "\nEnter number of vertices: ";
	cin >> V;
	Graph G(V);
	G.AddEdges(1,0);
	G.AddEdges(0,2);
	G.AddEdges(2,1);
    G.AddEdges(0,3);
    G.AddEdges(3,4);
//    G.AddEdges(3,3);
	
	if(G.CycleDetection()) 
        cout << "\nGraph contains cycle"; 
    else
        cout << "\nGraph doesn't contain cycle";

	
}
