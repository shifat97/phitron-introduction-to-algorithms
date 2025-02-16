#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
vector<pair<int, int>> mv = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {2, 1}, {2, -1}, {1, 2}, {1, -2}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int ki, int kj, int qi, int qj)
{
    queue<pair<int, int>> q;
    queue<int> steps;
    q.push({ki, kj});
    steps.push(0);
    vis[ki][kj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int si = p.first;
        int sj = p.second;
        int count = steps.front();
        q.pop();
        steps.pop();

        if (si == qi && sj == qj)
            return count;

        for (int i = 0; i < 8; i++)
        {
            int ci = si + mv[i].first, cj = sj + mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                steps.push(count + 1);
            }
        }
    }
    return -1;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;
        memset(vis, false, sizeof(vis));

        cout << bfs(ki, kj, qi, qj) << endl;
    }
}

int main()
{
    solve();
    return 0;
}
