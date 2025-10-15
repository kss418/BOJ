#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][10][2][2], result;

ll solve(ll cur, ll num, ll st, ll f){
    if(cur < 0) return 0;
    ll& ret = dp[cur][num][st][f];
    if(ret != -1) return ret; ret = 0;
    if(!cur){
        if(f) return ret = (num > s[cur] - '0' ? 0 : 1);
        return ret = 1;
    }

    if(f){
        for(int i = 0;i < s[cur - 1] - '0';i++){
            if(st && i == num) continue;
            ret += solve(cur - 1, i, (i ? 1 : st), 0);
            ret %= MOD;
        }

        if(st && num != s[cur - 1] - '0') ret += solve(cur - 1, s[cur - 1] - '0', 1, 1);
    }
    else{
        for(int i = 0;i <= 9;i++){
            if(st && i == num) continue;
            ret += solve(cur - 1, i, (i ? 1 : st), 0);
            ret %= MOD;
        }
    }

    return ret %= MOD;
}

void cal(ll mul){
    cin >> s; memset(dp, -1, sizeof(dp));
    if(mul == -1){
        for(int i = s.size() - 1;i >= 0;i--){
            if(s[i] == '0') s[i] = '9';
            else { s[i]--; break; }
        }
    }

    reverse(all(s));
    if(s.back() == '0') s.pop_back();
    if(s.empty()) result--;

    result += mul * solve(s.size() - 1, 0, 0, 0);
    result = (result % MOD + MOD) % MOD;

    for(int i = 1;i < s.back() - '0';i++){
        result += mul * solve(s.size() - 1, i, 1, 0);
        result = (result % MOD + MOD) % MOD;
    }

    result += mul * solve(s.size() - 1, s.back() - '0', 1, 1);
    result = (result % MOD + MOD) % MOD;
}

void run(){
    cal(-1); cal(1);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}