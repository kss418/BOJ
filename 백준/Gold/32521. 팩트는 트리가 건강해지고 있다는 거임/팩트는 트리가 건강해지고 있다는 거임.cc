#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
ll a[MAX], dp[MAX], cnt[MAX];
vector <ll> adj[MAX];

ll solve(ll cur, ll pre){
    ll& ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;

    vector <ll> num;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        ret += solve(nxt, cur);
        num.push_back(cnt[nxt]);
    }
    sort(all(num));

    ll sum = a[cur];
    ll c = num.size();
    for(auto &i : num){
        sum += i; c--;
        if(sum > m){
            sum -= i; c++;
        }
    }
    ret += c;
    cnt[cur] = sum;

    return ret;
}

int main() {
    fastio;

    cin >> n >> m; memset(dp, -1, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    cout << solve(1, -1);
    
    
    return 0;
}