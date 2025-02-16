#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + mv[i].first;
        cj = sj + mv[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    dfs(si, sj);
    if (vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    solve();
    return 0;
}