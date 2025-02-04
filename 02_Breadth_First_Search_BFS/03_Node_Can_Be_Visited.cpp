#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
bool vis[1005];

void isNodeVisited(int src)
{
	queue<int> q;
	q.push(src);
	vis[src] = true;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (int child : a[p])
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
	int v, e;
	cin >> v >> e;
	while (e--)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(vis, false, sizeof(vis));
	int src, dst;
	cin >> src >> dst;
	isNodeVisited(src);
	if (vis[dst])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
