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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
int a[MAX], c[MAX], v[MAX], dp[MAX][MAX][MAX][2];

bool chk(ll cur, ll nxt){
    return (cur <= n && nxt <= n && (a[nxt] == a[cur] || c[nxt] == c[cur]));
}

int solve(ll fi, ll se, ll th, ll cnt){
    int& ret = dp[fi][se][th][cnt];
    if(ret != -1) return ret; ret = 0;

    if(!cnt){
        if(chk(fi, se)){
            ret = max(ret, solve(se, th, th + 1, 0) + v[se]);
        }

        if(chk(fi, th + 1)){
            ret = max(ret, solve(se, th, th + 1, 1) + v[th + 1]);
        }
    }
    else{
        if(chk(th, fi)){
            ret = max(ret, solve(fi, se, th + 1, 0) + v[fi]);
        }

        if(chk(th, th + 1)){
            ret = max(ret, solve(fi, se, th + 1, 1) + v[th + 1]);
        }
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> c[i] >> a[i] >> v[i];
    cout << max(solve(1, 2, 3, 0) + v[1], solve(1, 2, 3, 1) + v[3]);
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}