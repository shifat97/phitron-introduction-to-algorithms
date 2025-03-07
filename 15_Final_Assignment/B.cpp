#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    } else if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    } else if (n == 3) {
        cout << 2 << endl;
        return 0;
    }
    long long arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    }
    cout << arr[n] << endl;
    return 0;
}