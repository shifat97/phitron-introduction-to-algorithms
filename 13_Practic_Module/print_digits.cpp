#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 0) return 0;
    int l = n % 10;
    solve(n / 10);
    cout << l << " ";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}