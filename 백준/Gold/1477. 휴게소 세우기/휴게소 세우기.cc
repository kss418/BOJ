#include <iostream>
#include <algorithm>
using namespace std;

int a[1010], n, m, l;

bool decision(int cur){
    int cnt = 0;
    for(int i = 1;i <= n + 1;i++){
        int diff = a[i] - a[i - 1];
        cnt += diff / cur;
        if(diff % cur == 0) cnt--;
    }

    return cnt <= m;
}

int minimazation(){
    // 정답의 범위는 1 ~ l
    int lo = 1, hi = l;
    while(lo < hi){
        int mid = (lo + hi) / 2; // 중간값
        // 결정 문제의 답이 1 이면 
        // 정답은 [lo, mid]에 존재
        if(decision(mid)) hi = mid;
        
        // 결정 문제의 답이 0 이면
        // 정답은 [mid + 1, hi]에 존재
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    cin >> n >> m >> l;
    for(int i = 1;i <= n;i++) cin >> a[i];
    a[0] = 0; a[n + 1] = l;
    sort(a, a + n + 2);

    cout << minimazation();

    return 0;
}

