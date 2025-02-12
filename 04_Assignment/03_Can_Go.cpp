#include<bits/stdc++.h>
using namespace std;
int m, n;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool found = false;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    if (grid[si][sj] == 'B') {
        found = true;
        return;
    }
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + mv[i].first;
        cj = sj + mv[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'B'))
        {
            dfs(ci, cj);
        }
        if (found) return; 
    }
}

int main()
{
    int si, sj;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                si = i;
                sj = j;
            }
        }
    }
    dfs(si, sj);
    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}