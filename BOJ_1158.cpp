#include <iostream>
#include <list>   // 원형 큐를 구현하기 쉬워서 list 함수를 사용
#include <vector> // 벡터는 순서대로 제거된 요소들을 저장하는 데 적합하고 벡터의 인덱스 접근은 O(1) 시간 복잡도로 빠르기 때문에 효율적이다.

using namespace std;

// 여러 개의 값을 반환할 수 있는 데이터 구조를 사용해야 하기 때문에 vector<int>로 선언해야 한다. int 타입으로 선언시, 다수의 값을 반환해야 하는 문제에서는 정보가 손실된다!!!
vector<int> getNumber(int N, int K) {  // 요세푸스 순열을 계산하는 함수 (N = people, K = 제거되는 순서)

    list<int> people;  // 사람들을 저장할 리스트
    vector<int> result;  // 제거된 순서를 저장할 벡터

    for (int i = 1; i <= N; ++i) {   // 1부터 N까지 사람을 리스트에 추가한다.
        people.push_back(i);
    }

    auto it = people.begin();  // 리스트의 시작 위치를 가리키는 이터레이터
    // (auto는 it의 타입을 people.begin()이 반환하는 타입으로 자동으로 설정한다.)

    while (!people.empty()) {   // 모든 사람이 제거될 때까지 반복하는 while문
        for (int i = 0; i < K - 1; ++i) {  // K-1만큼 이터레이터를 이동한다. (K번째 사람을 찾기 위해)
            ++it;  // 다음 사람으로 이동한다.
            if (it == people.end()) it = people.begin();  // 리스트의 끝에 도달하면 다시 처음으로 돌아간다.
        }

        result.push_back(*it);   // 현재 이터레이터가 가리키는 사람을 결과 벡터에 추가한다.

        it = people.erase(it);   // 현재 이터레이터가 가리키는 사람을 people 리스트에서 제거한다.
        if (it == people.end()) it = people.begin();  // 리스트의 끝에 도달하면 처음으로 돌아간다.
    }

    return result;  // 제거된 순서를 저장하고 있는 벡터를 반환한다.
}

int main() {
    int N, K;
    cin >> N >> K;

    // 요세푸스 순열 계산
    vector<int> number = getNumber(N, K);

    // 제거된 순서를 저장하고 있는 벡터의 데이터를 출력한다.
    cout << '<';
    for (size_t i = 0; i < number.size(); ++i) {
        cout << number[i];
        if (i < number.size() - 1) cout << ", ";  // 마지막 항목이 아닐 경우는 쉼표를 추가한다.
    }
    cout << '>' << '\n';  // (출력에 소요되는 시간을 최소화하기 위해 개행문자 '\n' 사용)

    return 0;
}
