#include <iostream>
#include<vector>
#include<unordered_set>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> connectedCell(vector<unordered_set<int>> &matrix)
{
    unordered_set<int> visited;
    vector<int> count_array;
    //cout<<"here"<<endl;

    for(int i=1;i<matrix.size();i++)
    { 
        if(visited.find(i)!=visited.end())
            continue;

        int curr=i;
        stack<int> dfs;
        dfs.push(curr);

        int ct=0;
        while(dfs.size())
        {
            int c=dfs.top();
            dfs.pop();
            if(visited.find(c)!=visited.end())
                continue;

            //cout<<"visiting "<<c<<endl;
            ct++;

            visited.insert(c);
            for(int x:matrix[c])
            {
                if(visited.find(x)==visited.end())
                {
                    //cout<<"pushed "<<i<<endl;
                    dfs.push(x);
                }
            }
        }

        
        count_array.push_back(ct);
    }

    return count_array;
}


int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n,m;
        cin >> n;
        cin >> m;
        n++;
        vector<unordered_set<int>> matrix(n);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i!=j)
                {
                    matrix[i].insert(j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int u,v;
            cin>>u>>v;
            matrix[u].erase(v);
            matrix[v].erase(u);
        }

        auto result = connectedCell(matrix);
        sort(result.begin(),result.end());

        cout << result.size() << "\n";
        if (result.size() != 0)
        {
            for(int i:result)
                cout<<i<<" ";
            cout<<"\n";
        }   
    }
    return 0;
}