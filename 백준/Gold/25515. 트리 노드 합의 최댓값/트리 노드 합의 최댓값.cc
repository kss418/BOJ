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
ll a[MAX], dp[MAX];
vector <ll> adj[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret;
    
    ret = a[cur];
    for(auto& nxt: adj[cur]) ret += max(solve(nxt), 0ll);
    
    return ret;
}

int main() {
    fastio;

    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 1; i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    for(int i = 0;i < n;i++) cin >> a[i];

    cout << solve(0);
    

    return 0;
}

