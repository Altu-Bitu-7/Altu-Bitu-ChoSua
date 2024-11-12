#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

//문자열에서 각 알파벳 문자의 등장 빈도를 계산하여 반환하는 함수
vector<int> 문자빈도수계산(const string& 문자열) {
    vector<int> 빈도수(26, 0);
    for (char 문자 : 문자열) {
        ++빈도수[문자 - 'a'];
    }
    return 빈도수;
}

//연속적인 부분 문자열 중 특정 문자가 정확히 K번 등장하는 경우의
//가장 짧은 길이와 가장 긴 길이를 계산하는 함수
pair<int, int> 최소최대문자열길이계산(const string& 문자열, int K, const vector<int>& 빈도수) {
    int 최소길이 = INT_MAX;
    int 최대길이 = -1;

    for (int i = 0; i < 문자열.length(); ++i) {
        if (빈도수[문자열[i] - 'a'] < K) //해당 문자의 빈도가 K 미만이면 건너뜀
            continue;

        int 횟수 = 0;
        for (int j = i; j < 문자열.length(); ++j) {
            if (문자열[i] == 문자열[j]) { //연속된 동일 문자 카운트
                ++횟수;
            }
            if (횟수 == K) {  //K번 등장 시 최소 및 최대 길이 갱신
                최소길이 = min(최소길이, j - i + 1);
                최대길이 = max(최대길이, j - i + 1);
                break;
            }
        }
    }

    return {최소길이, 최대길이};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int 테스트케이스수;
    cin >> 테스트케이스수;
    while (테스트케이스수--) {
        string 문자열;
        int K;
        cin >> 문자열 >> K;

        //각 문자의 빈도수 계산
        vector<int> 빈도수 = 문자빈도수계산(문자열);

        //최소, 최대 길이 계산
        auto [최소길이, 최대길이] = 최소최대문자열길이계산(문자열, K, 빈도수);

        //결과 출력
        if (최소길이 == INT_MAX || 최대길이 == -1)
            cout << -1 << "\n";
        else
            cout << 최소길이 << " " << 최대길이 << "\n";
    }

    return 0;
}
