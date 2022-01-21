//========================================
// Name        : LAB4.cpp
// Author      : ROHIT Saini
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 4, Ansi-style
// Erp: 1032200897	======================

#include <iostream>
using namespace std;

class stack
{
    int top;
    int data[100];
    public:
    stack()
    {
        top = -1;
    }
    void push(int);
    int pop();
    bool empty();
};
void stack::push(int temp)
{
    data[++top] = temp;
}
int stack::pop()
{
    return data[top--];
}
bool stack::empty()
{
    if(top==-1)
        return true;
    return false;
}

class queue
{
	int front, rear;
	int data[30];

public:
	queue();
	void insert(int v);
	int remove();
	int empty();
	friend class tree;
};

queue::queue()
{
	front = rear = -1;
}

void queue::insert(int v)
{
	rear++;
	data[rear] = v;
}

int queue::remove()
{
	front++;
	return (data[front]);
}

int queue::empty()
{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
class Gnode
{
    int vertex;
    Gnode *next;
    string name;
    friend class Graph;
public:
    Gnode()
    {
        next = nullptr;
    }
    Gnode(string n)
    {
        next = nullptr;
        name = n;
    }
};
class Graph
{
    private:
        Gnode **head;
        int *visited;
        int n;
    public:
    Graph()
    {
        string s;
        cout << "Enter Number of Vertices: ";
        cin >> n;
        head = new Gnode*[n];
        visited = new int[n];

        for (int i = 0; i < n; i++)
        {
            cout << "Name of Person " << i << ": ";
            cin >> s;
            head[i] = new Gnode(s);
            head[i]->vertex = i;
        }
    }
    void create()
    {
        Gnode *temp, *curr;
        char choice;
        int v;
        for (int i = 0; i < n; i++)
        {
            temp = head[i];
            do
            {
                cout << "Enter Adjacent Vertex of " << i << ": ";
                cin >> v;
                if(v==i)
                {
                    cout << "Self Loop Not Allowed!";
                }
                else
                {
                    curr = new Gnode(head[v]->name);
                    curr->vertex = v;
                    temp->next = curr;
                    temp = temp->next;
                }
                cout << "Choice(y/n): ";
                cin >> choice;
            } while (choice =='Y'||choice =='y');
            
        }
    }
    void DFS_nr(int v)
    {
        stack s;
        Gnode *temp;
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        s.push(v);
        visited[v] = 1;
        int w;
        do
        {
            v = s.pop();
            visited[v] = 1;
            temp = head[v];
            cout << " -> " << v << " - " << temp->name ;
            while(temp!=nullptr)
            {
                w = temp->vertex;
                if(!visited[w])
                {
                    s.push(w);
                    visited[w] = 1;
                }
                temp = temp->next;
            }

        } while (!s.empty());   
    }
    void BFS()
    {
        int v;
        cout << "Enter node to start the BFS From: ";
        cin >> v;
        cout << "BFS is: " << endl
             << v << " - " << head[v]->name;
        BFS(v);
        cout << endl;
    }
    void BFS(int v)
    {
        Gnode *temp;
        int w;
        for (int i = 0; i < n; i++)
            visited[i] = 0;
        queue q;
        q.insert(v);
        while(!q.empty())
        {
            v = q.remove();
            visited[v] = 1;
            temp = head[v]->next;
            while(temp!=nullptr)
            {
                w = temp->vertex;
                if(!visited[w])
                {
                    cout << " ->" << w << " - "<< temp->name ;
                    q.insert(w);
                    visited[w] = 1;
                }
                temp = temp->next;
            }
            
        }
    }
    void DFS()
    {
        int v;
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        cout << "Starting Vertex: ";
        cin >> v;
        cout << "DFS is : " << v <<" - " << head[v]->name;
        visited[v] = 1;
        DFS(v);
    }    
    void DFS(int v)
    {
        Gnode *temp;
        int w;
        if(!visited[v])
        cout << " -> " << v << " - " << head[v]->name ;
        visited[v] = 1;
        temp = head[v]->next;
            while(temp!=nullptr)
            {
                w = temp->vertex;
                if(!visited[w])
                    DFS(w);
                temp = temp->next;
            }
    }
    void Show()
    {
        Gnode *temp;
        for( int i = 0; i < n; i++)
        {
            temp = head[i]->next;
            cout << "Head " << i << " " << head[i]->name << "  -> ";
            while ( temp != nullptr )
            {
                cout << temp->vertex << " " << temp->name << "  -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};


int main() 
{
    Graph g;
    int ch;
    int v;
    do
    {
        cout << "\n\tMenu\n1.Create\n2.Display\n3.DFS[r]\n4.DFS[nr]\n5.BFS\n6.Exit\nChoice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.Show();
            break;
        case 3:
            g.DFS();
            break;
        case 4:
            cout << "Starting Vertex: ";
            cin >> v;
            g.DFS_nr(v);
            break;
        case 5:
            g.BFS();
            break;
        default:
            break;
        }
    } while (ch != 6);
    return 0;
}