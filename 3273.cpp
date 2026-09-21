#include <bits/stdc++.h>
using namespace std;

//단순 이중 for문을 쓰면 N이 최대 십만이니 O(N^2)하면 1초 내에 절대 통과 X
//정렬 시키고나서 x를 넘어가면 바로 탈락시키는 기법을 적용시키면 줄어들 순 있으나, 최악의 경우 똑같이 O(N^2)임.
//양 끝 투 포인터를 사용해야함. 정렬 시키는데 O(NlogN)이 걸리고 양끝에서 순회하는데 O(N)이 필요함.

int arr[100005]; //이 문제는 벡터보단 배열 선택.
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int X;
    cin >> X;

    sort(arr, arr+N); //O(NlogN) 소모.

    //투 포인터: st와 en이 arr를 둘이서 양분하므로 O(N)이 소모.
    int st = 0;
    int en = N-1;
    while(st < en) { //st가 en을 역전하면 종료조건. 문제 조건에서 i < j이므로 st와 en이 같아도 안됨.
        if(arr[st] + arr[en] < X) st++; //X보다 작으면 st를 오른쪽으로 이동

        else if(arr[st] + arr[en] > X) en--; //X보다 크면 en을 왼쪽으로 이동

        else { //arr[st] + arr[en] == X
            ans++; //정답 발견

            st++;
            en--;
        }    
    }

    cout << ans;
}