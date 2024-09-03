#include <iostream>

using namespace std;

//최대공약수를 구하는 함수 (유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m; //첫 번째 분수의 분자(n)와 분모(m)
    int k, j; //두 번째 분수의 분자(k)와 분모(j)
    cin >> n >> m;
    cin >> k >> j;

    //공통 분모 계산
    int denominator = m * j;

    //새로운 분자 계산 (교차 곱셈)
    int numerator = n * j + k * m;

    //기약분수로 만들기 위해 최대공약수 계산
    int g = gcd(numerator, denominator);

    //분자와 분모를 최대공약수로 나누기
    numerator /= g;
    denominator /= g;

    cout << numerator << " " << denominator << endl;

    return 0;
}
