#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n, m, a[MAX], num[MAX];

bool decision(ll cur){
    ll last = 0;
    for(int i = 1;i <= n;i++){
        if(i <= cur) last = max(a[i] - m + 1, 1ll);
        else last = max({a[i] - m + 1, num[i - cur] + m, 1ll});
        num[i] = last;

        ll diff = a[i] - num[i];
        if(diff < 0) return 0;
    }
    
    return 1;
}

ll minimization(){
    ll lo = 1, hi = 201010;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(decision(mid)) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    
    cout << minimization();

    return 0;
}





