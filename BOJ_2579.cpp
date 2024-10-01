#include<iostream>
#define MAX 301
using namespace std;

int numSteps;              //계단의 수
int stepScores[MAX];       //각 계단의 점수
int maxScores[MAX];        //각 계단까지의 최대 점수를 저장하는 배열

int getMax(int a, int b) {  //두 수 중 더 큰 값을 반환하는 함수
    return (a > b) ? a : b;
}


//최대 점수를 계산하는 함수
void calculateMaxScore() {
    maxScores[1] = stepScores[1];  //첫 번째 계단의 최대 점수
    maxScores[2] = stepScores[1] + stepScores[2];  //첫 두 계단의 최대 점수
    maxScores[3] = getMax(stepScores[1] + stepScores[3], stepScores[2] + stepScores[3]);  //세 번째 계단의 최대 점수

    for (int i = 4; i <= numSteps; i++) {
        maxScores[i] = getMax(maxScores[i - 2] + stepScores[i], maxScores[i - 3] + stepScores[i - 1] + stepScores[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numSteps;
    for (int i = 1; i <= numSteps; i++) {
        cin >> stepScores[i];
    }

    calculateMaxScore();    //점수 계산

    cout << maxScores[numSteps] << '\n';

    return 0;
}
