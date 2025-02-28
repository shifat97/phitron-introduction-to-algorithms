#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_mat(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        adj_mat[i][i] = 0;
    }

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]) {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int src, dest;
        cin >> src >> dest;
        if (adj_mat[src][dest] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << adj_mat[src][dest] << endl;
        }
    }

    return 0;
}