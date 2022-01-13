//========================================
// Name        : LAB4.cpp
// Author      : ROHIT Saini
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 4, Ansi-style
// Erp: 1032200897	======================

#include <iostream>
using namespace std;

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
    void BFS()
    {
        
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
            cout << "Head \"" << i << " " << head[i]->name << "  -> ";
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
    g.create();
    g.Show();
    g.DFS();

    return 0;
}