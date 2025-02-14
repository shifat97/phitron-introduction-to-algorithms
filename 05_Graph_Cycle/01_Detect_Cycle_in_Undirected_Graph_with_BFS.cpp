#include<bits/stdc++.h>
using namespace std;

bool vis[105], cycle;
vector<int> arr_list[105];
int parent[105];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int child : arr_list[p]) {
            if (vis[child] && parent[p] != child) cycle = true;
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
                parent[child] = p;
            }
        }
    }
}

void solve() {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int a, b;
        cin >> a >> b;
        arr_list[a].push_back(b);
        arr_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for(int i = 0; i < n; i++)
        if (!vis[i]) bfs(i);
    if (cycle) cout << "Cycle" << endl;
    else cout << "NO Cycle" << endl;
}

int main() {
    solve();
    return 0;
}