#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int m, n;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};

    bool found = false;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first, pj = p.second;

        if (pi == di && pj == dj)
        {
            found = true;
            break;
        }

        for (auto move : mv)
        {
            int ci = pi + move.first;
            int cj = pj + move.second;

            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {pi, pj};
            }
        }
    }

    return found;
}

int main()
{
    int ri, rj, di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'D')
                di = i, dj = j;
            if (grid[i][j] == 'R')
                ri = i, rj = j;
        }
    }
    memset(vis, false, sizeof(vis));
    if (bfs(ri, rj, di, dj))
    {
        int x = di, y = dj;
        while (parent[x][y].first != -1 && parent[x][y].second != -1)
        {
            if (grid[x][y] != 'D' && grid[x][y] != 'R')
                grid[x][y] = 'X';

            int px = parent[x][y].first;
            int py = parent[x][y].second;
            x = px;
            y = py;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
