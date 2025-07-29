#include <bits/stdc++.h>
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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <pll> arr[MAX];
ll dp[1ll << MAX];

ll solve(ll v){
    ll& ret = dp[v];
    if(ret != -1) return ret; ret = INF;

    for(ll cur = 0;cur < n;cur++){
        if(!(v & (1ll << cur))) continue;
        ll nv = v ^ (1ll << cur);
        for(auto& [bit, co] : arr[cur]){
            if(!nv && !bit){ ret = min(ret, co); continue; }
            if((nv & bit) != bit) continue;
        
            ret = min(ret, solve(nv) + co);
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++){
        ll sz; cin >> sz;
        for(int j = 0;j < sz;j++){
            ll c, csz, bit = 0; cin >> c >> csz;

            for(int k = 0;k < csz;k++){
                ll v; cin >> v;
                bit |= (1ll << v);
            }

            arr[i].push_back({bit, c});
        }
    }

    memset(dp, -1, sizeof(dp)); ll ret = INF;
    for(int i = 1;i < (1ll << n);i+=2){
        ret = min(ret, solve(i));
    }

    cout << ret << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}