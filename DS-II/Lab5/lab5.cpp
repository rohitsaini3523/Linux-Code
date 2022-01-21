#include <iostream>
using namespace std;

class graph
{
    int cost[10][10];
    int city;
    public:
        graph()
        {
            city = 0;
            cout << "Enter Number of Cities: ";
            cin >> city;
            for (int i = 0; i < city; i++)
            for (int j = 0; j < city; j++)
            {
                cost[i][j] = 999;
            }

        }
    void create()
    {
        char ch;
        for (int i = 0; i < city; i++)
            for (int j = 0; j < city; j++)
            {
                cout << "Is city " <<i<<" and "<<j<<" connected (y/n):  " ;
                cin >> ch;
                if(ch=='y'||ch=='Y')
                {
                    cout << "Enter the cost of edge " << i << " " << j << ": ";
                    cin >> cost[i][j];
                }
            }
    }
    void display()
    {
        for (int i = 0; i < city; i++)
        {
            for (int j = 0; j < city; j++)
            {
                cout << cost[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    void prims()
    {
        int s[city][2];
        int i, j, k;
        int r = 0;
        int v, min;
        int final = 0;
        int nearest[city];
        cout << "Enter starting vertex : ";
        cin >> v;
        nearest[v] = -1;
        for (int i = 0; i < city-1; i++)
        {
            if(i != v)
                nearest[i] = v;      
        }
        for (i = 1; i < city; i++)
        {
            min = 999;
            for (k = 0; k < city; k++)
            {
                if((nearest[k] != -1)&& (cost[k][nearest[k]]<min))
                {
                    j = k;
                    min = cost[k][nearest[k]];
                }
            }
            s[r][0] = j;
            s[r][1] = nearest[j];
            r = r + 1;
            final = final + cost[j][nearest[j]];
            nearest[j] = -1;
            for (k = 0; k < city; k++)
            {
                if((nearest[k]!=-1) && (cost[k][nearest[k]]>cost[k][j]))
                {
                    nearest[k] = j;
                }
            }
        }
        cout << "\n The Spanning tree is: \n";
        for (i = 0; i < city-1 ; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << s[i][j]<<"\t";
            }
            cout << endl;
        }
        cout << "\nThe total cost is: " << final << endl;
    }
};
int main() 
{
    int ch;
    graph g;
    do
    {
        cout << "_____MENU______\n1.Create\n2.Display\n3.Prims\n4.Exit\nChoice: ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.prims();
                break;
            case 4:
                break;
        }
    } while (ch != 4);
    return 0;
}