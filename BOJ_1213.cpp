//IDE에서 코드를 돌릴때는 어느 경우의 입력을 줘도 밎게 출력이 되는데
//백준에서는 코드가 틀렸다고 합니다..ㅠㅠ (아무리 봐도 뭘 잘못했는지 잘 모르겠습니다ㅠ)
#include <iostream>
#include <algorithm> //algorithm 헤더 파일을 추가하면 컴파일 에러가 안남
using namespace std;

//알파벳 개수를 카운팅하는 함수
void countAlphabets(int alpha[], const string& s) {
    for (char c : s) {
        alpha[c - 'A']++;  //대문자 기준으로 카운트
    }
}

//홀수 개수 문자를 찾고, 회문이 가능한지 여부를 판별하는 함수
bool canFormPalindrome(int alpha[], int& oddNum, int& midNum) {
    oddNum = 0;
    midNum = -1;

    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1) {  //홀수 개수의 문자를 찾음
            oddNum++;
            midNum = i;
            alpha[i]--;  //홀수 개수에서 1개 빼서 짝수로 만듦
        }
    }

    //홀수 개수의 문자가 2개 이상이면 펠린드롬을 만들 수 없음
    return oddNum <= 1;
}

//펠린드롬으로 만드는 함수
string createPalindrome(int alpha[], int midNum) {
    string ans, tmp;

    //짝수 개수의 문자를 절반만 ans에 추가
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 0) {
            ans.append(alpha[i] / 2, 'A' + i);
        }
    }

    //ans의 역순을 tmp에 저장
    tmp = ans;
    reverse(tmp.begin(), tmp.end());

    //홀수 개수의 문자를 중앙에 추가
    if (midNum != -1) {
        ans += 'A' + midNum;
    }

    //회문의 뒷부분에 역순 문자열을 이어 붙임
    ans += tmp;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int alpha[26] = {0};  //알파벳 a~z까지 각 문자의 개수를 저장할 배열
    countAlphabets(alpha, s);  //알파벳 개수 카운트

    int oddNum, midNum;

    //펠린드롬을 만들 수 있는지 확인
    if (!canFormPalindrome(alpha, oddNum, midNum)) {
        cout << "I'm Sorry HanSoo";  // 만들 수 없는 경우
    } else {
        string result = createPalindrome(alpha, midNum);  //펠린드롬 생성
        cout << result << '\n';
    }

    return 0;
}
