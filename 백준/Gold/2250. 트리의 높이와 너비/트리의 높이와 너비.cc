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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
ll l[MAX], r[MAX];
ll mn[MAX], mx[MAX], seq;
bool root[MAX];

void dfs(ll cur, ll dep){
    if(l[cur] != -1) dfs(l[cur], dep + 1);
    ++seq;
    mn[dep] = min(mn[dep], seq);
    mx[dep] = max(mx[dep], seq);
    if(r[cur] != -1) dfs(r[cur], dep + 1);
}


int main() {
    fastio;

    cin >> n;
    memset(root, 1, sizeof(root));
    memset(mn, 0x3f, sizeof(mn));

    for(int i = 1;i <= n;i++){
        ll idx; cin >> idx;
        cin >> l[idx] >> r[idx];

        if(l[idx] != -1) root[l[idx]] = 0;
        if(r[idx] != -1) root[r[idx]] = 0;
    }

    ll st = 0;
    for(int i = 1;i <= n;i++) if(root[i]) st = i;
    dfs(st, 1);

    ll result = 0, idx = 0;
    for(int i = 1;i <= n;i++){
        if(mn[i] == INF) break;
        if(result >= mx[i] - mn[i] + 1) continue;
        result = mx[i] - mn[i] + 1; idx = i;
    }

    cout << idx << " " << result;


    return 0;
}

