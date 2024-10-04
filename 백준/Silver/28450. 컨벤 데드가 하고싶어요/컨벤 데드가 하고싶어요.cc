#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
constexpr ll MOD = 998244353;
ll dp[MAX][MAX], arr[MAX][MAX];

ll solve(ll y, ll x){
    if(y <= 0 || x <= 0) return INF;
    ll& ret = dp[y][x];
    if(ret != -1) return ret;

    ret = min(solve(y - 1, x), solve(y, x - 1)) + arr[y][x];
    return ret;
}

int main() {
    fastio;

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> arr[i][j];
    }
    dp[1][1] = arr[1][1];

    ll ret = solve(n, m);
    cin >> k;
    if(ret > k) cout << "NO";
    else {
        cout << "YES\n" << ret;
    }


    return 0;
}