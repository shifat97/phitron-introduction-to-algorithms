#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int m, n;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;
        cout << pi << " " << pj << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci, cj;
            ci = pi + mv[i].first;
            cj = pj + mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, ci});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);
    return 0;
}