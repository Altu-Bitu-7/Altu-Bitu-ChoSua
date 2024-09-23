#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

const int MAX = 1001; //최대 톱니바퀴 수 정의
deque<int> dq[MAX];  //각 톱니바퀴의 상태를 저장할 deque 배열

//톱니바퀴 상태를 입력받아 deque에 저장하는 함수
void inputGears(int T, const vector<string>& gearStates) {
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < gearStates[t].length(); i++) {
            dq[t].push_back(gearStates[t][i] - '0');  //문자열을 숫자로 변환해 deque에 저장
        }
    }
}

//특정 톱니바퀴의 회전 방향을 결정하고 옆에 있는 톱니바퀴도 회전시킬지 탐색하는 함수
vector<pair<int, int>> findRotation(int num, int dir, int T) {
    vector<pair<int, int>> rotations;  //회전할 톱니바퀴 번호와 방향을 저장
    queue<pair<int, int>> q;  //BFS 탐색을 위한 큐
    bool visited[MAX] = { false };  //각 톱니바퀴의 방문 여부를 체크할 배열

    //현재 톱니바퀴 번호와 회전 방향을 큐에 추가
    q.push({ num, dir });
    visited[num] = true;
    rotations.push_back({ num, dir });

    //BFS 방식으로 인접한 톱니바퀴를 탐색하며 회전 여부 결정
    while (!q.empty()) {
        int cur = q.front().first;  //현재 톱니바퀴 번호
        int d = q.front().second;   //현재 톱니바퀴의 회전 방향
        q.pop();

        //왼쪽에 있는 톱니바퀴와 비교하여 회전 여부 결정
        if (cur != 0 && !visited[cur - 1] && dq[cur][6] != dq[cur - 1][2]) {
            visited[cur - 1] = true;
            q.push({ cur - 1, d * -1 });  //방향을 반대로 회전 (에러이유)
            rotations.push_back({ cur - 1, d * -1 });
        }

        //오른쪽에 있는 톱니바퀴와 비교하여 회전 여부 결정
        if (cur != T - 1 && !visited[cur + 1] && dq[cur][2] != dq[cur + 1][6]) {
            visited[cur + 1] = true;
            q.push({ cur + 1, d * -1 });  //방향을 반대로 회전
            rotations.push_back({ cur + 1, d * -1 });
        }
    }

    return rotations;  // 회전할 톱니바퀴와 회전 방향 목록을 반환
}

//톱니바퀴를 회전시키는 함수
void rotateGears(const vector<pair<int, int>>& rotations) {
    for (const auto& rotation : rotations) {
        int cur = rotation.first;  //회전할 톱니바퀴 번호
        int d = rotation.second;   //회전 방향

        //시계 방향 회전
        if (d == 1) {
            int temp = dq[cur].back();  //마지막 원소 저장
            dq[cur].pop_back();  //마지막 원소 제거
            dq[cur].push_front(temp);  //첫 번째 위치에 추가
        }
        //반시계 방향 회전
        else {
            int temp = dq[cur].front();  //첫 번째 원소 저장
            dq[cur].pop_front();  //첫 번째 원소 제거
            dq[cur].push_back(temp);  //마지막 위치에 추가
        }
    }
}

//결과 계산 (톱니바퀴의 12시 방향이 1인 톱니바퀴의 수를 세는 함수)
int calculateResult(int T) {
    int result = 0;
    for (int t = 0; t < T; t++) {
        if (dq[t][0] == 1) {  //톱니바퀴의 첫 번째 원소(12시 방향)이 1인지 확인
            result++;
        }
    }
    return result;  //12시 방향이 1인 톱니바퀴의 수 반환
}

int main() {
    ios::sync_with_stdio(false);  //시간 초과 대비
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;  //톱니바퀴 개수

    //톱니바퀴 상태
    vector<string> gearStates(T);
    for (int t = 0; t < T; t++) {
        cin >> gearStates[t];  //각 톱니바퀴 상태(문자열)
    }
    inputGears(T, gearStates);  //입력받은 상태를 토대로 톱니바퀴 초기화

    int K;
    cin >> K;  //회전 명령 개수 입력

    //각 회전 명령에 대해 처리
    for (int k = 0; k < K; k++) {
        int num, dir;
        cin >> num >> dir;  //회전할 톱니바퀴 번호와 방향 입력

        //회전할 톱니바퀴 및 방향 찾기
        vector<pair<int, int>> rotations = findRotation(num - 1, dir, T);

        //톱니바퀴 회전
        rotateGears(rotations);
    }

    //결과 계산 및 출력
    cout << calculateResult(T) << "\n";

    return 0;
}
