#include<bits/stdc++.h>
using namespace std;

class SNode{
	friend class Stack;
private:
	SNode *Previous;
	int Data;
public:
	SNode ()
	{
		Previous = NULL;
		Data = 0;
	}
	SNode (int Data)
	{
		Previous = NULL;
		this->Data = Data;
	}
};

class Stack{
private:	
	SNode *Latest;
	int Size;
public:
	Stack ()
	{
		Size = 0;
		Latest = NULL;
	}
	void Push (int Value)
	{
		SNode *NewNode = new SNode(Value);
		NewNode->Previous = Latest;
		Latest = NewNode;
		Size++;
	}
	int Pop()
	{
		SNode *tempPtr = NULL;
		SNode *tempPtr2 = NULL;
		tempPtr2 = Latest;
		tempPtr = Latest->Previous;
		Latest->Previous = NULL;
		Latest = tempPtr;
		Size--;
		if (tempPtr == NULL)
		{
			cout << "\nStack is Empty" << endl;
			return 0;
		}
		return tempPtr2->Data;
	}
	bool IsEmpty()
	{
		if (Latest == NULL)
		{
			return true;
		}
		return false;
	}
	void DisplayList ()
	{
		SNode *tempPtr = new SNode();
		tempPtr = Latest;
		cout << "\nStack: ";
		while (tempPtr != NULL)
		{
			cout << tempPtr->Data << " " ;
			tempPtr = tempPtr->Previous;
		}
		cout << endl;
//		delete tempPtr;
	}
	int Get_Size()
	{
		return Size;
	}
	int Top()
	{
		return Latest->Data;
	}
};

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
//		L[NeighbouringEdge].InsertAtLast(Vertex);
	}

	void TopoLogicalSort()
	{
		Stack S1;
		for (int i = 0 ; i < Vertices ; i++)
		{
			if(i != 0 && i !=6)
			{
				if (Visited[i] == false)
				{
					TopologicalSortRecursion(S1 , i);
				}
			}
			
		}
		S1.DisplayList();
	}
	
	void TopologicalSortRecursion(Stack &S , int Vertex)
	{
		Visited[Vertex] = true;

		for (Node *tempPtr = L[Vertex].GetHead() ; tempPtr != NULL ; tempPtr = tempPtr->Next)
		{
			if(!Visited[tempPtr->Data])
			{
				TopologicalSortRecursion(S , tempPtr->Data);
			}
		}
		S.Push(Vertex);
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
	G.AddEdges(1,2);
	G.AddEdges(1,4);
	G.AddEdges(2,4);
    G.AddEdges(2,3);
    G.AddEdges(4,3);
    G.AddEdges(4,5);
	
	G.TopoLogicalSort();


}
