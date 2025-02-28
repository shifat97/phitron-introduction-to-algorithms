#include <iostream>
#include <vector>
using namespace std;

pair<int, int> max_container(const vector<int>& heights) {
    int left = 0, right = heights.size() - 1;
    int maxArea = 0;
    pair<int, int> idx;

    while (left < right) {
        int h = min(heights[left], heights[right]);
        int area = h;
        if (area > maxArea) {
            maxArea = area;
            idx.first = left;
            idx.second = right;
        }
        
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }
    return idx;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        pair<int, int> result = max_container(heights);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}



