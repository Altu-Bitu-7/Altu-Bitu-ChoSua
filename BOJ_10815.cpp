#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return 1;
        else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    cin >> m;
    vector<int> targets(m);
    for (int& x : targets) cin >> x;

    for (int target : targets) {
        cout << binarySearch(arr, target) << " ";
    }
}
