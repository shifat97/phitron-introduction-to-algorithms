#include<bits/stdc++.h>

using namespace std;

bool arr[100005];

int solve(int n) {
    arr[1] = true;
    for (int i = 1; i <= n; i++) {
        if (arr[i]) {
            if (i + 3 <= n)
                arr[i + 3] = true;
            if (i * 2 <= n)
                arr[i * 2] = true;
        }
    }
    return arr[n];
}

int main() {
    memset(arr, false, sizeof(arr));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (solve(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}