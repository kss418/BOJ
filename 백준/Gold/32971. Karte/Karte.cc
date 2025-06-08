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
constexpr ll MAX = 33; // SET MAX SIZE
constexpr ll MOD = 998244353;
bitset <22> bs[MAX], tmp[MAX];
string st[MAX];
ll dp[MAX], x, y;

ll solve(ll cur, ll bit){
    ll& ret = dp[cur];
    if(ret != INF) return ret; ret = MINF;

    ret = max(ret, solve(cur - 1, bit) + max<ll>(tmp[cur - 1].count() - x, 0ll));
    return ret;
}

void run(){
    cin >> n >> m >> x >> y;
    for(int i = 0;i < n;i++){
        cin >> st[i];
        reverse(all(st[i]));
        for(int j = 0;j < st[i].size();j++){
            if(st[i][j] == '0') continue;
            bs[i] |= (1ll << j);
        }
    }
    ll result = 0;

    for(int i = 0;i < (1ll << m);i++){
        memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
        ll cnt = 0;
        for(int j = 0;j < m;j++){
            tmp[j] = bs[j];
            tmp[j] &= i;
            if(i & (1ll << j)) cnt++;
        }

        result = max(result, solve(n, i) - y * cnt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

