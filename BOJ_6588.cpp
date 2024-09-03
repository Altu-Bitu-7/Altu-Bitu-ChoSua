#include <iostream>
using namespace std;

const int MAX = 1000001;  //최대 범위 설정 (0부터 시작하므로 실제로는 1000000까지)
int arr[MAX];  //소수 여부를 저장할 배열

//에라토스테네스의 체 알고리즘으로 소수를 구하는 함수
void primeNumberSieve() {
    //배열을 초기화: 2부터 MAX-1까지의 숫자를 초기화
    for(int i = 2; i < MAX; i++) {
        arr[i] = i;  //처음엔 모두 자기 자신을 가리키게 함
    }

    //소수를 찾고 그 배수들을 배열에서 제거
    for(int i = 2; i * i < MAX; i++) {  //i*i가 MAX보다 작을 때까지 반복
        if(arr[i] == 0) {  //i가 이미 0으로 설정된 경우 (소수가 아니어서 이미 지워진 경우)
            continue;  // 다음 숫자로 건너뜀
        }
        for(int j = i * i; j < MAX; j += i) {  //지워진 수가 아니라면, i의 배수들을 모두 0으로 설정
            arr[j] = 0;  //j는 소수가 아님을 표시
        }
    }
}

//골드바흐의 추측을 확인하는 함수
void conjectureOfGoldbach(int n) {
    //에라토스테네스의 체를 통해 소수를 미리 계산
    primeNumberSieve();  //소수 판정을 위한 배열을 초기화

    //무한 루프를 통해 사용자의 입력을 반복적으로 처리
    while (true) {
        cin >> n;  //사용자로부터 정수를 입력받음
        if(n == 0) {  //입력된 값이 0이면 루프 종료
            break;  //프로그램 종료 조건
        }

        bool check = false;  //두 소수의 합으로 n을 나타낼 수 있는지 여부 확인

        //3부터 n/2까지 반복하며 n = i + (n - i) 형태로 두 소수를 찾음
        for(int i = 3; i <= n / 2; i++) {
            if(arr[i] != 0 && arr[n - i] != 0) {  //i와 n-i가 모두 소수인 경우
                cout << n << " = " << i << " + " << n - i << '\n';
                check = true;  //두 소수를 찾았음을 표시
                break;  //첫 번째 결과를 찾으면 루프를 종료
            }
        }

        if (!check) {  //두 소수의 합으로 n을 나타낼 수 없는 경우
            cout << "Goldbach's conjecture is wrong." << '\n';  //오류 메시지 출력
        }
    }
}

int main() {
    //시간복잡도 대비!
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    conjectureOfGoldbach(0);  //골드바흐의 추측 함수 호출
    return 0;
}
