#include <bits/stdc++.h>
using namespace std;
vector<int> arr[1005];
bool vis[1005];
vector<pair<int, int>> pr;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    pr.push_back({0, src});
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
                pr.push_back({pr[p].first + 1, child});
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
    bfs(0);
    int l;
    cin >> l;
    stack<int> st;
    for (int i = 0; i < pr.size(); i++)
    {
        if (pr[i].first == l)
            st.push(pr[i].second);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}