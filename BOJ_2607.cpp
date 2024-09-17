#include <iostream>
using namespace std;

//알파벳 구성 배열을 초기화하는 함수
void initializeAlpha(const string &str, int alpha[26]) {
    //문자열 str에 등장하는 알파벳 개수를 세어 alpha 배열에 저장
    for (char c : str) {
        alpha[c - 'A']++;
    }
}

//두 문자열이 주어졌을 때, 규칙에 맞게 같은 구성인지 판단하는 함수
bool isSimilar(const string &targetStr, const string &testStr, const int alpha[26]) {
    int targetLen = targetStr.size();
    int testLen = testStr.size();

    //alpha 배열 복사 (기준 문자열의 알파벳 구성)
    int tempAlpha[26];
    copy(alpha, alpha + 26, tempAlpha);

    //testStr에 같은 알파벳이 얼마나 있는지 확인
    int same = 0;
    for (char c : testStr) {
        if (tempAlpha[c - 'A'] > 0) {
            tempAlpha[c - 'A']--;
            same++;
        }
    }

    //두 문자열의 길이가 같은 경우
    if (targetLen == testLen) {
        //알파벳이 모두 같거나 한 글자만 다른 경우
        return (same == targetLen || same == targetLen - 1);
    }
    //targetStr가 testStr보다 한 글자 더 긴 경우 (testStr가 한 글자 추가된 경우)
    else if (targetLen - 1 == testLen && same == targetLen - 1) {
        return true;
    }
    //targetStr가 testStr보다 한 글자 더 짧은 경우 (testStr에서 한 글자가 삭제된 경우)
    else if (targetLen + 1 == testLen && same == targetLen) {
        return true;
    }

    return false;
}

//여러 개의 문자열을 비교하여 규칙을 만족하는 문자열의 개수를 세는 함수
int countSimilarStrings(int n, const string &targetStr) {
    //기준 문자열의 알파벳 구성 배열
    int alpha[26] = {0};
    initializeAlpha(targetStr, alpha);

    //규칙을 만족하는 문자열 개수
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        string testStr;
        cin >> testStr;

        //기준 문자열과 비교하여 규칙을 만족하는 경우 카운트 증가
        if (isSimilar(targetStr, testStr, alpha)) {
            count++;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);  //시간초과 대비
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n;
    cin >> n;
    string targetStr;
    cin >> targetStr;

    //함수 호출 후 결과 계산
    int result = countSimilarStrings(n, targetStr);

    //출력
    cout << result << '\n';
}
