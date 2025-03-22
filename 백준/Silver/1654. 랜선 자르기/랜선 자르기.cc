#include <iostream>
using namespace std;
int n, m, a[1010101];

bool decision(long long cur){
    long long cnt = 0;
    for(int i = 1;i <= n;i++){
        cnt += a[i] / cur;
    }

    return cnt >= m;
}

int maximazation(){
    long long lo = 1, hi = (1 << 31) - 1;
    while(lo < hi){
        long long mid = (lo + hi + 1) / 2;
        if(decision(mid)) lo = mid;
        else hi = mid - 1;
    }

    return lo;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << maximazation();

    return 0;
}