#include <iostream>
#include <unordered_set>  //해시셋 사용을 위한 헤더파일
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;  //n m 을 입력 받는다

    unordered_set<string> s;  //문자열을 저장할 해시셋
    int count = 0;  //첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 센다

    for(int i = 0; i < n; i++) {  //n번동안 반복
        string temp;
        cin >> temp;  //입력 받은 문자열은 임시로 저장 후
        s.insert(temp);  //셋에 추가한다
    }

    for(int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if(s.find(temp) != s.end()) {  //만약 입력 받은 문자열이 s 셋에 존재하면
            count++;  //count를 증가한다.
        }
    }

    cout << count << endl;
    return 0;
}
