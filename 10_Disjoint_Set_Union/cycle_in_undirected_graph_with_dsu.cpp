#include<bits/stdc++.h>
using namespace std;
int par[1005];
int sz[1005];
int find(int node) {
    if (par[node] == -1) 
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2) {
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (sz[leader1] >= sz[leader2]) {
        par[leader2] = leader1;
        sz[leader1] += sz[leader2];
    } else {
        par[leader1] = leader2;
        sz[leader2] += sz[leader1];
    }
}

int main() {
    memset(par, -1, sizeof(par));
    memset(sz, 1, sizeof(sz));
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--) {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);  
        
        if (leaderA == leaderB) cycle = true;
        else dsu_union(a, b);
    }
    cout <<  endl;
    if (cycle) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    return 0;
}