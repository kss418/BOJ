#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 303; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX][MAX][MAX][2], st = -1, result;
vector <ll> arr;
bool zero;

ll solve(ll s, ll e, ll c, ll p){
    ll& ret = dp[s][e][c][p];
    if(ret != -1) return ret; ret = INF;  
    if(s == st && e == st) return ret = 0;

    ll cnt = c - ((st - s) + (e - st)) + 1 - zero;
    if(cnt < 0) return ret;

    if(!p && s != st){
        ret = min(ret, solve(s + 1, e, c, 0) + cnt * (arr[s + 1] - arr[s]));
        ret = min(ret, solve(s + 1, e, c, 1) + cnt * (arr[e] - arr[s]));
    }
    else if(p && e != st){
        ret = min(ret, solve(s, e - 1, c, 0) + cnt * (arr[e] - arr[s]));
        ret = min(ret, solve(s, e - 1, c, 1) + cnt * (arr[e] - arr[e - 1]));
    }

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        arr.push_back(a[i]);
        if(!a[i]) zero = 1;
    }

    if(!zero) arr.push_back(0);
    sort(all(arr));

    memset(dp, -1, sizeof(dp));
    for(int i = 0;i < arr.size();i++) if(!arr[i]) st = i;

    for(int i = st;i >= 0;i--){
        for(int j = st;j < arr.size();j++){
            ll cnt = (st - i) + (j - st) + zero;
            ll now = min(solve(i, j, cnt, 0), solve(i, j, cnt, 1));
            result = max(result, cnt * m - now);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}