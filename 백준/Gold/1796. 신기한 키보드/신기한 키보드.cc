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
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 51; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][2], dp[MAX][2], cnt[MAX];
ll num[MAX];

ll solve(ll cur, ll f){
    if(cur == -1) return 0;
    ll& ret = dp[cur][f];
    if(ret != -1) return ret; ret = INF;

    ll diff = a[cur][1] - a[cur][0];
    ll z = solve(cur - 1, 0) + (cur ? abs(a[cur - 1][0] - a[cur][f ^ 1]) : a[cur][f ^ 1]) + diff + cnt[cur];
    ll o = solve(cur - 1, 1) + (cur ? abs(a[cur - 1][1] - a[cur][f ^ 1]) : a[cur][f ^ 1]) + diff + cnt[cur];
    ret = min({ret, z, o});

    return ret;
}

void run(){
    cin >> s; n = s.size(); ll c = 0;
    for(ll i = 0;i < 26;i++) a[i][0] = INF;
    for(ll i = 0;i < n;i++) {
        cnt[s[i] - 'a']++;
        a[s[i] - 'a'][0] = min(a[s[i] - 'a'][0], i);
        a[s[i] - 'a'][1] = max(a[s[i] - 'a'][1], i);
    }

    for(ll i = 0;i < 26;i++){
        if(!cnt[i]) continue;
        a[c][0] = a[i][0]; a[c][1] = a[i][1]; 
        cnt[c] = cnt[i]; c++;
    }

    memset(dp, -1, sizeof(dp));
    cout << min(solve(c - 1, 0), solve(c - 1, 1));
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

