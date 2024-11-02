#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
vector <ll> a;
ll dp[MAX][5][5];

ll solve(ll cur, ll l, ll r){
    ll&ret = dp[cur][l][r];
    if(ret != -1) return ret;
    if(l == r && l) return ret = INF;
    if(cur == n) return ret = 0;
    ret = INF;

    ll nxt = a[cur];
    if(!l) ret = min(ret, solve(cur + 1, nxt, r) + 2);
    else if(l == nxt) ret = min(ret, solve(cur + 1, nxt, r) + 1);
    else if(abs(nxt - l) != 2) ret = min(ret, solve(cur + 1, nxt, r) + 3);
    else ret = min(ret, solve(cur + 1, nxt, r) + 4);

    if(!r) ret = min(ret, solve(cur + 1, l, nxt) + 2);
    else if(r == nxt) ret = min(ret, solve(cur + 1, l, nxt) + 1);
    else if(abs(nxt - r) != 2) ret = min(ret, solve(cur + 1, l, nxt) + 3);
    else ret = min(ret, solve(cur + 1, l, nxt) + 4);

    return ret;
}

int main() {
    fastio;

    while(1){
        cin >> n; if(!n) break;
        a.push_back(n);
    }
    n = a.size();
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0, 0);


    return 0;
}

