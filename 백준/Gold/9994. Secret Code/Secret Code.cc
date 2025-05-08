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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <string, ll> dp;

ll solve(const string& cur){
    if(cur.size() <= 1) return 0;
    if(dp.count(cur)) return dp[cur];
    ll& ret = dp[cur]; ret = 1;
    if(cur.size() % 2 == 0) return ret;
    ll sz = (cur.size() - 1) / 2;
    
    if(cur.substr(0, sz) == cur.substr(cur.size() - sz, sz)){
        ret += solve(cur.substr(0, sz + 1));
        ret += solve(cur.substr(cur.size() - sz - 1, sz + 1));
    }

    if(cur.substr(0, sz) == cur.substr(cur.size() - sz - 1, sz)){
        ret += solve(cur.substr(cur.size() - sz - 1, sz + 1));
    }

    if(cur.substr(1, sz) == cur.substr(cur.size() - sz, sz)){
        ret += solve(cur.substr(0, sz + 1));
    }

    return ret;
}

void run(){
    cin >> s;
    cout << solve(s) - 1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

