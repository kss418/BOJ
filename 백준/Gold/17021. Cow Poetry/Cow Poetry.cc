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
constexpr ll MOD = 1e9 + 7;
ll cnt[26], result = 1, dp[MAX];
vector <ll> num[MAX], all;

ll solve(ll cur){
    ll& ret = dp[cur];
    if(!cur) return ret = 1;
    if(ret != -1) return ret; ret = 0;

    for(auto& i : all){
        if(cur - i < 0) continue;
        ret += solve(cur - i);
        ret %= MOD;
    }

    return ret %= MOD;
}

class _pow {
public:
    _pow() {}

    ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

    ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

void run(){
    cin >> n >> m >> k; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++){
        ll v, c; cin >> v >> c;
        num[c].push_back(v);
        all.push_back(v);
    }

    while(m--){
        char c; cin >> c;
        cnt[c - 'A']++;
    }
    
    _pow pow;
    for(int i = 0;i < 26;i++){
        if(!cnt[i]) continue;
        ll sum = 0;
        for(int j = 1;j <= n;j++){
            ll now = 0;
            for(auto& v : num[j]){
                now += solve(k - v);
                now %= MOD;
            }

            sum += pow.ret(now, cnt[i], MOD); sum %= MOD;
        }

        result *= sum; result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

