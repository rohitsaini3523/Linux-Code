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
        {
            for (int j = i + 1; j < city; j++)
            {
                cout << "\n Is there a connection between " << i << " and " << j << ":"
                     << "(y or n)"
                     << ":  ";
                cin >> ch;
                if (ch == 'y')
                {
                    cout << "\nEnter the cost of edge " << i << " and " << j << ": ";
                    cin >> cost[i][j];
                    cost[j][i] = cost[i][j];
                }
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
        int st[city][2];
        int i, j, k;
        int r = 0;
        int startv, min, final = 0;
        int nearest[city];

        cout << "\nEnter starting vertex: ";
        cin >> startv;
        nearest[startv] = -1;

        for (i = 0; i < (city); i++)
        {
            if (i != startv)
            {
                nearest[i] = startv;
            }
        }

        for (i = 1; i < city; i++)
        {
            min = 999;
            for (k = 0; k < city; k++)
            {
                if (nearest[k] != -1 && cost[k][nearest[k]] < min)
                {
                    j = k;
                    min = cost[k][nearest[k]];
                }
            }

            st[r][0] = nearest[j];
            st[r][1] = j;
            r = r + 1;
            final = final + cost[j][nearest[j]];
            nearest[j] = -1;

            for (k = 0; k < city; k++)
            {
                if (nearest[k] != -1 && cost[k][nearest[k]] > cost[k][j])
                {
                    nearest[k] = j;
                }
            }
        }

        cout << "\nThe spanning tree is as follows:\n";
        for (i = 0; i < city - 1; i++)
        {
            for (j = 0; j < 2; j++)
            {
                cout << st[i][j];
                cout << "\t";
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
        cout << "\n_____MENU______\n1.Create\n2.Display\n3.Prims\n4.Exit\nChoice: ";
        cin >> ch;
        switch (ch)
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