#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
bool vis[1005];

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = true;
	int sum = 0;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		sum += p;
		for(int child : a[p]) {
			if (vis[child] == false) {
				q.push(child);
				vis[child] = true;
			}
		}
	}
	cout << sum << endl;
}

int main() {
	int n, e;
	cin >> n >> e;
	while(e--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(vis, false, sizeof(vis));
	bfs(0);
	return 0;
}

