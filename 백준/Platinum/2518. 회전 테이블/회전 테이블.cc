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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sz[3], arr[MAX][3], dp[MAX][MAX][MAX][3];

ll dist(ll a, ll ai, ll b, ll bi){
    ll ar = arr[ai][a], br = arr[bi][b];
    if(ar > br) swap(ar, br);
    return min(br - ar, ar + n - br);
}

ll solve(ll a, ll b, ll c, ll la){
    ll& ret = dp[a][b][c][la];
    if(ret != -1) return ret; ret = INF;
    if(!a && !b && !c) return ret = 0;

    if(la == 0 && a){
        ret = min(ret, solve(a - 1, b, c, 0) + dist(0, a - 1, 0, a));
        ret = min(ret, solve(a - 1, b, c, 1) + dist(1, b, 0, a));
        ret = min(ret, solve(a - 1, b, c, 2) + dist(2, c, 0, a));
    }
    else if(la == 1 && b){
        ret = min(ret, solve(a, b - 1, c, 0) + dist(0, a, 1, b));
        ret = min(ret, solve(a, b - 1, c, 1) + dist(1, b - 1, 1, b));
        ret = min(ret, solve(a, b - 1, c, 2) + dist(2, c, 1, b));
    }
    else if(la == 2 && c){
        ret = min(ret, solve(a, b, c - 1, 0) + dist(0, a, 2, c));
        ret = min(ret, solve(a, b, c - 1, 1) + dist(1, b, 2, c));
        ret = min(ret, solve(a, b, c - 1, 2) + dist(2, c - 1, 2, c));
    }

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < 3;i++){
        arr[0][i] = 0;
        cin >> sz[i];
        for(int j = 1;j <= sz[i];j++){
            cin >> arr[j][i]; arr[j][i] -= (n / 3) * i;
            arr[j][i] = (arr[j][i] + n - 1) % n;
        }
    }

    ll result = INF;
    for(int i = 0;i < 3;i++){
        result = min(result, solve(sz[0], sz[1], sz[2], i));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}   