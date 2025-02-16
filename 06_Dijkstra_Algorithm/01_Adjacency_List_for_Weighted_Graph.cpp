#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> arr[n];
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (pair<int,int> item : arr[i]) {
            cout << item.first << " " << item.second << ", ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}