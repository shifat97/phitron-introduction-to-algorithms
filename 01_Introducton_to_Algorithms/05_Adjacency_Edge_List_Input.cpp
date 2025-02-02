#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iterator>
#include <numeric>
#include <tuple>
#include <functional>
#include <limits>
#include <type_traits>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edge_list;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    for (pair<int, int> p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
