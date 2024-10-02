#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 5010;
constexpr ll MOD = 998244353;
pll arr[MAX];
vector <vector<long double>> dp;

long double d(ll a, ll b){
    ld dx = arr[a].x - arr[b].x;
    ld dy = arr[a].y - arr[b].y;

    return sqrt(dx * dx + dy * dy);
}

long double solve(ll a, ll b){
    if(a > b) swap(a, b);
    if(a == n && b == n) return 0;
    if(b == n) return d(a, n);
    long double& ret = dp[a][b];
    if(ret > -0.5) return ret;

    ret = solve(b, b + 1) + d(a, b + 1);
    ret = min(ret, solve(a, b + 1) + d(b, b + 1));
    return ret;
}

int main() {
    fastio;

    cin >> t;

    while(t--){
        cin >> n;
        dp.assign(n + 1, vector<long double>(n, -1));
        for(int i = 1;i <= n;i++) cin >> arr[i].x >> arr[i].y;

        cout << solve(1, 1) << "\n";
    }


    return 0;
}