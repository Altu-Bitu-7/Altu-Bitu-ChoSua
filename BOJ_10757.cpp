#include <iostream>
#include <string>
#include <vector>
using namespace std;

string addNumbers(string a, string b) {
    vector<int> v_a, v_b, sum;
    int carry = 0;

    // 입력받은 a와 b 문자열을 벡터에 정수로 변환하여 저장한다.
    for(int i = 0; i < a.length(); i++) {
        v_a.push_back(a[i] - '0');  // '0'을 빼서 문자형 숫자를 정수형 숫자로 변환한다. (아스키코드 뺄셈)
    }
    for(int i = 0; i < b.length(); i++) {
        v_b.push_back(b[i] - '0');  // '0'을 빼서 문자형 숫자를 정수형 숫자로 변환한다. (아스키코드 뺄셈)
    }

    // 최대 길이를 계산하고, 결과를 저장할 벡터의 크기 할당한다.
    int maxLength = max(v_a.size(), v_b.size());
    sum.resize(maxLength + 1, 0); // 최대 길이 + 1, 마지막 자리 캐리까지 고려!!

    // 에러 난 이유: 뒤에서부터 거꾸로 연산 실행해야 한다!
    int idx_a = v_a.size() - 1;
    int idx_b = v_b.size() - 1;

    //  에러 난 이유: 인덱스 접근 범위와 캐리값 코드 잘못 작성함
    for (int i = maxLength; i >= 0; i--) {
        int digitA = (idx_a >= 0) ? v_a[idx_a--] : 0;
        int digitB = (idx_b >= 0) ? v_b[idx_b--] : 0;

        int tempSum = digitA + digitB + carry;  //tempSum은 i번째 자릿수에 저장되어야 하는 곳이다.
        sum[i] = tempSum % 10;  // 현재 자릿수의 결과,
        carry = tempSum / 10;   // 다음 자릿수로 넘길 캐리! (에러 조심)
    }

    // 벡터에서 앞자리의 0을 제거하고, 나머지 자릿수의 숫자를 문자열로 변환한다.
    // 결과를 저장할 빈 문자열을 초기화한다. (에러 이유)
    string result = "";

    // 앞자리에 있는 0을 처리하기 위한 변수
    bool leadingZero = true;

    // 덧셈 결과 벡터의 각 자릿수를 문자열로 변환하여 결과에 추가한다.
    for (int i = 0; i < sum.size(); i++) {
        // 현재 자릿수의 값이 0이 아닌 경우, leadingZero 플래그를 false로 설정한다.
        // 이는 이제 유효한 숫자가 나왔으므로 앞자리에 0이 더 이상 없음을 의미한다.
        if (sum[i] != 0) {
            leadingZero = false;
        }

        // leadingZero가 false일 때, 즉, 앞자리에 0이 없을 때만 결과 문자열에 현재 자릿수의 값을 추가한다.
        if (!leadingZero) {
            // 현재 자릿수의 값을 문자열로 변환하고, 결과 문자열에 추가한다.
            result += to_string(sum[i]);
        }
    }

    // 만약 결과 문자열이 비어있다면, 즉, 모든 자릿수가 0인 경우 "0"을 반환하고
    // 빈 문자열인 경우는 모든 자릿수가 0일 때 발생할 수 있으므로 이를 처리한다.
    return result.empty() ? "0" : result;

}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addNumbers(a, b) << '\n';
    return 0;
}
