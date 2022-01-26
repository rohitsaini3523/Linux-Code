#include <bits/stdc++.h>
using namespace std;

vector<int> alpha[26];
vector<char> T;

void ans()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    bool check[26][26];
    memset(check, false, sizeof(check));
    bool ok = false;
    for (int i = 1; i < n; i++)
    {
        int len1 = s[i - 1].size();
        int len2 = s[i].size();

        int pos = 0;
        while (s[i - 1][pos] == s[i][pos] && pos < min(len1, len2))
            ++pos;

        if (pos == len2)
        {
            cout << "NO" << endl;
            return;
        }
        else if (pos == len1)
            continue;
        int from = s[i - 1][pos] - 'a';
        int to = s[i][pos] - 'a';

        if (check[to][from] == 1)
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            alpha[from].push_back(to);
            check[from][to] = true;
        }
    }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                if (check[i][k] & check[k][j])
                    check[i][j] = true;

    for (int i = 0; i < 26; i++)
    {
        if (check[i][i] == true)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    }
int main()
{
    int t;
    cin >> t;
    while (t--)
        ans();
    return 0;
}