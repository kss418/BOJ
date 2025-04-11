#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll MOD = 10007;
ll n, dp[MAX];

ll solve(ll cur){
    if(cur < 0) return 0;
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    ret += solve(cur - 1) + solve(cur - 2);

    return ret %= MOD; 
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 0;i < MAX;i++) dp[i] = -1;
    dp[0] = 1;

    cout << solve(n);

    return 0;
}

