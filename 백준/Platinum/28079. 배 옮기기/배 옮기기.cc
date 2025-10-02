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
constexpr ll MAX = 16; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[1ll << MAX][2];

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(cur == (1ll << n) - 1 && !cnt) return ret = 0;

    if(!cnt){  
        for(int i = 0;i < n;i++){
            ll ni = (1ll << i);
            if(!(cur & ni)) continue;
            
            ll nxt = cur ^ ni ^ ((1ll << n) - 1);
            ret = min(ret, solve(nxt, 1) + a[i]);
        }
    }
    else{
        for(int i = 0;i < n;i++){
            ll ni = (1ll << i);
            if(!(cur & (cur - 1))){
                ll nxt = cur ^ ni ^ ((1ll << n) - 1);
                ret = min(ret, solve(nxt, 0) + a[i]);
                continue;
            }

            if(!(cur & ni)) continue;
            for(int j = i + 1;j < n;j++){
                ll nj = (1ll << j);
                if(!(cur & nj)) continue;
                if(a[i] == a[j]) continue;
                ll mx = max(a[i], a[j]);
                ll nxt = cur ^ ni ^ nj ^ ((1ll << n) - 1);
                ret = min(ret, solve(nxt, 0) + mx);
            }
        }
    }   

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> a[i];

    ll ret = solve((1ll << n) - 1, 1); 
    cout << (ret >= INF ? -1 : ret);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}