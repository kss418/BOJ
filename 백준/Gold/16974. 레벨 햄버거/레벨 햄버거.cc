#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51;
constexpr ll MOD = 998244353;
ll a[MAX], si[MAX];
map <ll, ll> dp[MAX];

ll dnc(ll cur, ll cnt){
    if(cnt <= 0 || cur <= 0) return 0;
    if(dp[cur].count(cnt)) return dp[cur][cnt];
    ll& ret = dp[cur][cnt]; ret = 0;
    if(cnt == si[cur]) cnt--;

    if(cnt <= si[cur - 1] + 1) ret += dnc(cur - 1, cnt - 1);
    else ret += dnc(cur - 1, cnt - si[cur - 1] - 2) + dnc(cur, si[cur - 1]) + 1;

    return ret;
}


int main() {
    fastio;

    cin >> n >> m; si[0] = 1;
    for(int i = 1;i <= n;i++) si[i] = 2 * si[i - 1] + 3;
    dp[1][1] = 0; dp[1][5] = 3;
    for(int i = 2;i <= 4;i++) dp[1][i] = i - 1;

    cout << dnc(n, m);


    return 0;
}

