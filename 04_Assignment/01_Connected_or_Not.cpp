#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int found = -1;
        if (x == y)
        {
            found = 0;
        }
        else
        {
            for (int child : arr[x])
            {
                if (child == y)
                    found = 0;
            }
        }
        if (found == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}