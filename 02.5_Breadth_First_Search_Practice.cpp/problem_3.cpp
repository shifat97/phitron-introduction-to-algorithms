#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1005];
bool vis[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
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
    memset(vis, false, sizeof(vis));
    int x, count = 0;
    cin >> x;
    for (int child : arr[x])
    {
        count++;
    }
    cout << count << endl;
    return 0;
}