#include <bits/stdc++.h>
using namespace std;

bool vis[105], cycle;
vector<int> arr_list[105];
int pathvis[105];

void dfs(int src) {
    vis[src] = true;
    pathvis[src] = true;
    for (int child : arr_list[src]) {
        if (vis[child] && pathvis[child])
            cycle = true;
        if (!vis[child]) {
            dfs(child);
        }
    }
    pathvis[src] = false;    
}

void solve()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr_list[a].push_back(b);
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, -1, sizeof(pathvis));
    cycle = false;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    if (cycle)
        cout << "Cycle" << endl;
    else
        cout << "NO Cycle" << endl;
}

int main()
{
    solve();
    return 0;
}