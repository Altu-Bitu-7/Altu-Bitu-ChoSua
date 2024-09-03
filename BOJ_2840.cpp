#include <iostream>
#include <vector>
using namespace std;

string findWord(int n, int k) {
    vector<char> w(n, '?');  //글자를 저장할 벡터를 일단 모두 '?'으로 채움
    int pointer = 0;  //초기 포인터 위치

    for(int i = 0; i < k; i++) {
        int s;  //글자가 몇번 바뀌었는지 나타냄
        char word;   //회전을 멈추었을때 가리키고 있는 글자
        cin >> s >> word;

        //회전 후 포인터 위치 업데이트
        pointer = (pointer + s) % n;

        //현재 위치에 이미 다른 글자가 있을 경우 !
        if(w[pointer] != '?' && w[pointer] != word) {
            return "!";
        }

        //현재 포인터 위치에 단어 삽입
        w[pointer] = word;
    }

    //에러 이유: 중복 글자 확인시 알파벳을 벡터로 다루지 않고 그냥 같은지 안 같은지의 여부만 체크함
    //알파벳을, 인덱스 0부터 25까지 각각 'A'부터 'Z'에 해당하는 벡터로 다룬다.
    vector<bool> alphabetCheck(26, false);  //알파벳 사용 여부를 체크하는 벡터, 초기값은 모두 false
    for(int i = 0; i < n; i++) {  //바퀴의 각 칸을 순회하며 중복된 문자가 있는지 확인하는 반복문
        if(w[i] != '?') {  //현재 칸이 빈칸 (?)이 아니라면, 즉 이미 문자가 있다면
            if(alphabetCheck[w[i] - 'A']) {
                //w[i] - 'A'는 현재 칸에 있는 문자가 알파벳 벡터의 몇 번째 위치에 해당하는지를 계산한다.
                //true라면, 이미 해당 문자가 사용된 적임을 의미함, 중복된 문자이다.
                return "!";   //중복된 문자가 발견되면 "!"를 반환하고 함수 종료
            }
            alphabetCheck[w[i] - 'A'] = true;  //해당 문자가 처음 사용된 경우, 사용 여부를 true로 설정
        }
    }

    // 결과 문자열 구성
    string result = "";
    for(int j = 0; j < n; j++) {
        result += w[((pointer - j) + n) % n];
    }

    return result;
}

int main() {
    int n;  // 바퀴의 칸 수
    int k;  // 바퀴를 돌리는 횟수
    cin >> n >> k;

    cout << findWord(n, k) << '\n';

    return 0;
}
