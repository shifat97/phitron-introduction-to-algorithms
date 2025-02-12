#include <bits/stdc++.h>
using namespace std;

int m, n;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] == '#')
        return false;
    return true;
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int count = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;
        count++;

        for (int i = 0; i < 4; i++)
        {
            int ci, cj;
            ci = pi + mv[i].first;
            cj = pj + mv[i].second;
            if (valid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
    return count;
}

int main()
{
    cin >> n >> m;
    vector<int> rooms;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int s = bfs(i, j);
                rooms.push_back(s);
            }
        }
    }

    if (rooms.empty()) {
        cout << 0 << endl;
    } else {
        sort(rooms.begin(), rooms.end());
        for (int room : rooms)
            cout << room << " ";
    }

    return 0;
}
