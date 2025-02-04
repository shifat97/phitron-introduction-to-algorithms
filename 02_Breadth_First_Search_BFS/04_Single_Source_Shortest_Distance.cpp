#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
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
		for (int child : a[p])
		{
			if (vis[child] == false)
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
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(vis, false, sizeof(vis));
	memset(level, -1, sizeof(level));
	int src, dst;
	cin >> src >> dst;
	bfs(src);
	cout << level[dst] << endl;
	return 0;
}
