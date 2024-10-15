#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

set<int> primeNumbers;  //가능한 소수를 저장하는 set (중복 제거)

//소수 판별 함수
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

//가능한 숫자 조합 생성
void backtrack(string& numbers, vector<bool>& used, string current) {
    if (!current.empty()) {
        int num = stoi(current);
        if (isPrime(num)) {
            primeNumbers.insert(num);  //소수이면 set에 저장
        }
    }

    //가능한 숫자를 재귀적으로 선택
    for (int i = 0; i < numbers.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            backtrack(numbers, used, current + numbers[i]);
            used[i] = false;  //백트래킹을 위해 상태 복구
        }
    }
}

//소수 개수 계산 함수
int findPrimeCount(string numbers) {
    vector<bool> used(numbers.size(), false);
    primeNumbers.clear();  //소수 저장 set 초기화

    //백트래킹을 시작
    backtrack(numbers, used, "");

    return primeNumbers.size();  //소수의 개수를 반환
}

int main() {
    string numbers;
    cin >> numbers;

    int result = findPrimeCount(numbers);
    cout << result << '\n';

    return 0;
}
