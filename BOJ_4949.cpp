#include <iostream>
#include <stack>     // 스택 사용
#include <string>    // 문자열 사용

using namespace std;

// 문자열 s가 괄호 균형을 이루는지 확인하는 함수
bool isBalanced(const string& s) {
    stack<char> stk;  // 괄호를 저장할 스택을 생성한다.


    for (char ch : s) { // 문자열의 각 문자를 순회한다.
        switch (ch) {
            case '(': case '[':  // 열린 (대)괄호일 때는 스택에 추가한다.
                stk.push(ch);
            break;
            case ')':
                // 닫힌 괄호일 때는
                    if (stk.empty() || stk.top() != '(') return false;  // 스택이 비어있거나 올바른 짝이 아닐 경우 false(불균형)을 리턴한다.
            stk.pop();  // 올바른 짝이면 스택에서 제거한다.
            break;
            case ']':
                // 닫힌 대괄호일 때는
                    if (stk.empty() || stk.top() != '[') return false;  // 스택이 비어있거나 올바른 짝이 아닐 경우 false(불균형)을 리턴한다.
            stk.pop();  // 올바른 짝이면 스택에서 제거한다.
            break;
            default:
                // 괄호가 아닌 다른 문자는 무시한다.
                    break;
        }
    }

    // 모든 괄호가 닫히고 스택이 비어있다면 균형 잡힌 것이다.
    return stk.empty();
}

int main() {
    string line;  // 입력 문자열을 저장할 변수

    //getline은 cin >> 처럼 공백이나 개행문자에서 입력을 끊지 않고 개행문자까지 포함한 전체의 줄을 읽기 때문에 훨씬 효율적이다.
    while (getline(cin, line)) {   // 입력을 한 줄씩 읽는다.
       if (line == ".") break;  // 입력이 "."이면 종료한다.

        // 입력 문자열의 괄호 균형을 확인
        if (isBalanced(line)) {
            cout << "yes" << '\n';  // 균형 잡힌 경우 "yes" 출력
        } else {
            cout << "no" << '\n';  // 균형 잡히지 않은 경우 "no" 출력
        }
    }
    return 0;  // 프로그램 종료
}
