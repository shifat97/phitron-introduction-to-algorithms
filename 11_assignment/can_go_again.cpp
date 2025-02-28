#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;
    Edge(int u, int v, int w) {
        a = u;
        b = v;
        c = w;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;
    vector<long long int> dist(n + 1, LLONG_MAX);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int s;
    cin >> s;

    dist[s] = 0;
    bool cycle = false;

    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;
        for (const auto &ed : edge_list) {
            if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.c < dist[ed.b]) {
                dist[ed.b] = dist[ed.a] + ed.c;
                updated = true;
            }
        }
        if (!updated) break; 
    }

    for (const auto &ed : edge_list) {
        if (dist[ed.a] != LLONG_MAX && dist[ed.a] + ed.c < dist[ed.b]) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (dist[x] == LLONG_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[x] << endl;
        }
    }

    return 0;
}