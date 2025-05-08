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
constexpr ll MOD = 2014;
map <string, ll> dp;

ll solve(const string& cur){
    if(cur.size() <= 1) return 0;
    if(dp.count(cur)) return dp[cur];
    ll& ret = dp[cur]; ret = 1;

    for(int i = 1;i < cur.size();i++){
        string a = cur.substr(0, i);
        string b = cur.substr(i, cur.size() - i);
        if(a.size() == b.size()) continue;
        
        if(a.size() < b.size()) swap(a, b);
        if(a.substr(0, b.size()) == b) ret += solve(a);
        if(a.substr(a.size() - b.size(), b.size()) == b) ret += solve(a);
        ret %= MOD;
    }

    return ret %= MOD;
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

