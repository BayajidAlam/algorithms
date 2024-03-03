

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }
        int maxHeight = INT_MIN, left = 0, right = n - 1;
        int ai = 0, aj = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            if (h > maxHeight) {
                maxHeight = h;
                ai = left;
                aj = right;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        cout << ai << " " << aj << endl;
    }
    return 0;
}