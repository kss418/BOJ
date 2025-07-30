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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 1234567;
ll dp[MAX][MAX][2], c[MAX][MAX][2];

ll num(ll cur, ll cnt, ll f){
    ll& ret = c[cur][cnt][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == 1){
        if(f){
            if(n & (1ll << (cur - 1))) return ret = (cnt <= 1 ? 1 : 0);
            return ret = (cnt ? 0 : 1);
        }
        return ret = (cnt <= 1 ? 1 : 0);
    }

    if(f){
        if(n & (1ll << (cur - 1))){
            if(cnt) ret += num(cur - 1, cnt - 1, 1), ret %= MOD;
            ret += num(cur - 1, cnt, 0); ret %= MOD;
        }
        else ret += num(cur - 1, cnt, 1); ret %= MOD;
    }   
    else{
        if(cnt) ret += num(cur - 1, cnt - 1, 0), ret %= MOD;
        ret += num(cur - 1, cnt, 0); ret %= MOD;
    }

    return ret %= MOD;
}

ll solve(ll cur, ll cnt, ll f){
    ll& ret = dp[cur][cnt][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == 1){
        if(f){
            if(n & (1ll << (cur - 1))) return ret = (cnt == 1 ? 1 : 0);
            return ret = 0;
        }

        return ret = (cnt == 1 ? 1 : 0);
    }

    if(f){
        if(n & (1ll << (cur - 1))){
            if(cnt){
                ll now = ((1ll << (cur - 1)) % MOD * num(cur - 1, cnt - 1, 1)) % MOD;
                ret += (solve(cur - 1, cnt - 1, 1) + now) % MOD; ret %= MOD;
            }
            ret += solve(cur - 1, cnt, 0); ret %= MOD;
        }
        else ret += solve(cur - 1, cnt, 1), ret %= MOD;
    }
    else{
        if(cnt){
            ll now = ((1ll << (cur - 1)) % MOD * num(cur - 1, cnt - 1, 0)) % MOD;
            ret += (solve(cur - 1, cnt - 1, 0) + now) % MOD; ret %= MOD;
        }
        ret += solve(cur - 1, cnt, 0); ret %= MOD;
    }

    return ret %= MOD;
}

void run(){
    cin >> n >> m; n--;
    memset(dp, -1, sizeof(dp));
    memset(c, -1, sizeof(c));

    cout << solve(54, m, 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

