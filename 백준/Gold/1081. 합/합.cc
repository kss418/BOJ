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
constexpr ll MAX = 12; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][2], c[MAX][MAX][2];

ll cnt(ll cur, ll num, ll f, ll en){
    ll& ret = c[cur][num][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == en) return ret = 1;

    if(f){
        for(int i = 0;i <= 9;i++) ret += cnt(cur + 1, i, 1, en);
    }
    else{
        for(int i = 0;i < s[cur + 1] - '0';i++) ret += cnt(cur + 1, i, 1, en);
        ret += cnt(cur + 1, s[cur + 1] - '0', 0, en);
    }
    
    return ret;
}

ll solve(ll cur, ll num, ll f, ll en){
    ll& ret = dp[cur][num][f];
    if(ret != -1) return ret; ret = 0;
    if(cur == en) return ret = num;
    
    ll c = 0;
    if(f){
        for(int i = 0;i <= 9;i++){
            ret += solve(cur + 1, i, 1, en);
            c += cnt(cur + 1, i, 1, en);
        }
    }
    else{
        for(int i = 0;i < s[cur + 1] - '0';i++){
            ret += solve(cur + 1, i, 1, en);
            c += cnt(cur + 1, i, 1, en);
        }
        ret += solve(cur + 1, s[cur + 1] - '0', 0, en);
        c += cnt(cur + 1, s[cur + 1] - '0', 0, en);
    }

    ret += c * num;
    return ret;
}

ll cal(ll v){
    if(v <= 0) return 0;
    ll ret = 0; s = to_string(v);
    memset(dp, -1, sizeof(dp)); memset(c, -1, sizeof(c));
    for(int i = 0;i < s[0] - '0';i++) ret += solve(0, i, 1, s.size() - 1);
    ret += solve(0, s[0] - '0', 0, s.size() - 1);
    return ret;
}

void run(){
    cin >> n >> m; 
    cout << cal(m) - cal(n - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}