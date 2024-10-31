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
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], idx[MAX];
ll lc[MAX], rc[MAX];


void dnc(ll s, ll e, ll l, ll r, ll pre){
    if(s > e || l > r) return;
    
    ll prv = idx[b[pre]];
    ll cur = idx[b[r]];
    if(prv > cur) lc[b[pre]] = b[r];
    else rc[b[pre]] = b[r];

    ll root = b[r];
    ll mid = idx[root];
    ll left = mid - s;
    
    dnc(s, mid - 1, l, l + left - 1, r); dnc(mid + 1, e, l + left, r - 1, r);
}

void dfs(ll cur){
    cout << cur << " ";
    if(lc[cur]) dfs(lc[cur]);
    if(rc[cur]) dfs(rc[cur]);
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], idx[a[i]] = i;
    for(int i = 1;i <= n;i++) cin >> b[i];

    dnc(1, n, 1, n, 0); dfs(b[n]);


    return 0;
}

