#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;

    m[0] = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == 'P') {
            sum = sum + 1;
        } else {
            sum = sum - 1;
        }

        if (m.find(sum) != m.end()) {
            int len = i - m[sum];
            if (len > ans) {
                ans = len;
            }
        } else {
            m[sum] = i;
        }
    }

    cout << ans;
    return 0;
}
