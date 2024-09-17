#include <iostream>
#include <queue>
using namespace std;

//n*n개의 수 중에서 n번째로 큰 수를 찾는 함수
//입력된 n값에 따라 n*n개의 수 중에서 n번째로 큰 수를 반환한다.
int findNthLargest(int n) {
    //우선순위 큐(priority_queue)는 작은 수가 우선순위를 갖도록 설정 (최소 힙)
    priority_queue<int, vector<int>, greater<int>> pq;
    int num;

    //n*n개의 수를 입력받아 처리
    for (int i = 0; i < n * n; i++) {
        cin >> num;  //새로운 숫자를 입력받음

        //큐의 크기가 n보다 작으면 새로운 숫자를 그대로 추가
        if (pq.size() < n) {
            pq.push(num);
        } else {
            //큐의 크기가 n 이상일 때
            //현재 숫자를 추가한 후 가장 작은 수를 제거
            pq.push(num);
            pq.pop();
        }
    }

    //우선순위 큐의 가장 위에 있는 값이 n번째로 큰 값
    return pq.top();
}

int main() {
    ios::sync_with_stdio(false);  //시간초과 대비
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;  //입력

    //n*n개의 수 중에서 n번째로 큰 수를 찾아서 출력
    cout << findNthLargest(n) << '\n';

    return 0;
}
