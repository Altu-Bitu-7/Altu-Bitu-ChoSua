#include <iostream>
using namespace std;

pair<int, int> lengths[12];

int calculateMelonFieldArea(int k) {
    int d, l, big_area = 0, small_area = 0;

    //방향과 길이 입력을 받고 배열에 저장 (순환 구조)
    for (int i = 0; i < 6; i++) {
        cin >> d >> l;
        lengths[i] = lengths[i + 6] = { d, l };
    }

    //큰 직사각형과 작은 직사각형의 면적을 계산
    for (int i = 3; i < 12; i++) {
        if (lengths[i].first == lengths[i - 2].first
            && lengths[i - 1].first == lengths[i - 3].first) {

            //큰 직사각형 면적
            big_area = lengths[i + 1].second * lengths[i + 2].second;
            //작은 직사각형 면적
            small_area = lengths[i - 1].second * lengths[i - 2].second;

            break;
            }
    }

    //결과 계산 후 반환
    return k * (big_area - small_area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    cout << calculateMelonFieldArea(k) << endl;

    return 0;
}
