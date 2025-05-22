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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll dp[MAX][11];
vector <ll> result;

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = cnt ? 0 : 1;

    ret += solve(cur - 1, cnt);
    if(cnt) ret += solve(cur - 1, cnt - 1);
    ret = min<ll>(ret, 1e8);

    return ret;
}

void run(){
    cin >> n >> m; memset(dp, -1, sizeof(dp));

    if(m == 1){
        cout << 1;
        for(int i = 1;i < n;i++) cout << 0;
        return;
    }

    ll cur = 5000;
    while(--cur){
        if(n > solve(cur - 1, m) && m){
            result.push_back(1);
            n -= solve(cur - 1, m);
            m--;
        }
        else result.push_back(0);
    }

    bool flag = 0;
    for(auto& i : result){
        if(!i && !flag) continue;
        flag = 1;
        cout << i;
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

