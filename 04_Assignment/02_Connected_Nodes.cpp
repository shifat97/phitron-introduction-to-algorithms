#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> arr[n];
    while (e--)  {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        priority_queue<int> pq;
        for (int child : arr[x]) {
            pq.push(child);
        }
        if (pq.empty()) {
            cout << -1 << " ";
        } else {
            while (!pq.empty())
            {
                cout << pq.top() << " ";
                pq.pop();
            }
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}