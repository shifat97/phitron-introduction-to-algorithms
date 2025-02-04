#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1005];
bool vis[1005];
int level[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int child : arr[p])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[p] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int x;
    cin >> x;
    while (x--)
    {
        int s, d;
        cin >> s >> d;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(s);
        cout << level[d] << endl;
    }
    return 0;
}