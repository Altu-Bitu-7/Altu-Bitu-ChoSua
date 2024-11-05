#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//필요한 시간 계산하는 함수
long long calculateResources(long long time, const vector<long long>& times) {
    long long totalResources = 0;
    for (long long t : times) {
        totalResources += (time / t); //주어진 시간으로 각 자원에서 얻을 수 있는 총 개수
    }
    return totalResources;
}

//최소 시간을 찾는 이진 탐색 함수
long long findMinimumTime(int numResources, long long requiredResources, const vector<long long>& times) {
    long long left = 1;  //최소 시간
    long long right = times[0] * requiredResources; //최대 시간
    long long minTime = 0;

    while (left <= right) {
        long long mid = (left + right) / 2; //중간값

        long long totalResources = calculateResources(mid, times);

        if (totalResources < requiredResources) {
            left = mid + 1; //필요 시간이 부족한 경우 더 큰 시간 탐색
        } else {
            minTime = mid; //필요 시간이 충족되는 경우 최소 시간 갱신
            right = mid - 1; //더 작은 시간 탐색
        }
    }

    return minTime;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<long long> times(n); //각 자원의 시간 저장

    for (int i = 0; i < n; i++) {
        cin >> times[i]; //자원 별로 필요한 시간 입력
    }

    sort(times.begin(), times.end()); //시간 정렬

    //최소 시간 계산 및 출력
    long long result = findMinimumTime(n, m, times);
    cout << result << endl;

    return 0;
}
