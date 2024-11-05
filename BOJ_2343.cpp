#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count(const vector<int>& lengths, int maxLen) {
    int disks = 1, sum = 0;
    for (int len : lengths) {
        if (len > maxLen) return lengths.size() + 1;
        if (sum + len > maxLen) { disks++; sum = len; }
        else sum += len;
    }
    return disks;
}

int min(int max, const vector<int>& lengths) {
    int left = *max_element(lengths.begin(), lengths.end()), right = 0;
    for (int len : lengths) right += len;
    int result = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (count(lengths, mid) <= max) {
            result = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> lengths(n);
    for (int& len : lengths) cin >> len;
    cout << min(m, lengths);
}
