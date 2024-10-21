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
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll MID = 250;
ll lx, ly, cx, cy;
ll arr[501][501];
ll dp[201][501][501];

ll solve(ll cur, ll curx, ll cury){
    if(cur < 0) return 0;
    ll& ret = dp[cur][curx][cury]; 
    if(ret != -1) return ret; 
    if(curx == MID + lx - cx && cury == MID + ly - cy) return ret = 1;
    if(arr[curx][cury]) return ret = 0;
    ret = 0;

    ret += solve(cur - 1, curx - 1, cury) % MOD; ret %= MOD;
    ret += solve(cur - 1, curx, cury - 1) % MOD; ret %= MOD;
    ret += solve(cur - 1, curx + 1, cury) % MOD; ret %= MOD;
    ret += solve(cur - 1, curx, cury + 1) % MOD; ret %= MOD;

    return ret %= MOD;
}

int main() {
    fastio;

    cin >> cx >> cy;
    memset(dp, -1, sizeof(dp));
    cin >> n >> lx >> ly;

    if(abs(cx - lx) + abs(cy - ly) > 210){
        cout << 0; return 0;
    }

    cin >> m;
    while(m--){
        ll x, y; cin >> x >> y;
        if(abs(x - cx) > 210 || abs(y - cy) > 210) continue;
        arr[MID + x - cx][MID + y - cy] = 1;
    }

    cout << solve(n, MID, MID);


    return 0;
}