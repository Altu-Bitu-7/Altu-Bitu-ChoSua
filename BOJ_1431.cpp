#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int compare (string a, string b) {

    if (a.length() != b.length()) {  //문자열 a와 문자열 b의 크기를 비교한다, 만약 같지 않으면
        return a.length() < b.length(); //짧은 것을 앞으로 오게끔 한다.
    }

    int sumA = 0;
    int sumB = 0;

    for(int i = 0; i < a.length(); i++) {
        //문자열 a의 길이만큼 (b와 같으니까 b는 비교할 필요 없음) 반복하며 각 요소의 합을 진행한다
        //에러가 난 이유: 중간중간 숫자가 아닌 문자도 있기 때문에 숫자만을 합하기 위해 문자의 리밋을 0~9까지 걸어줘야 한다!!!
        if(isdigit(a[i])) {  //isdigit() 함수를 사용하면 문자가 0~9까지의 숫자인지 확인하는 함수이다.
            sumA += a[i] - '0'; //에러 이유: 문자를 숫자로 변환하기 위해서는 현재 문자의 아스키코드 - 0의 아스키코드(48)을 해줘야한다.
        }

        if(isdigit(b[i])) {
            sumB += b[i] - '0';
        }
    }

    if(sumA != sumB) {  //만약 합이 다르다면,
            return sumA < sumB;  //합이 낮은 것이 먼저 와야 한다.
    }
    return a < b;  //길이도 같고 합도 같다면 사전순으로 비교한다.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string serialNumber[50];  //50과 같거나 작아야 한다
    cin >> n;  //50과 같거나 작아야 한다

    for(int i = 0; i < n; i++) {  //n번만큼 serialNumber를 입력받는다
        cin >> serialNumber[i];  //i,n번 만큼 입력 받는다
    }

    sort(serialNumber, serialNumber + n, compare);  //정렬할 때는 sort 함수를 사용하면 편하다 (algorithm header)

    for(int i = 0; i < n; i++) {
        cout << serialNumber[i] << endl;
    }

    return 0;
}
