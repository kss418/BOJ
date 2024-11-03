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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
string st1, st2;
ll dp[MAX][3], l, r;

ll solve(ll cur, ll idx, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret;
    ret = 0;

    if(cur == n){
        if(cnt == 2) return ret = 1;
        return ret = 0;
    }

    if(!cnt && st2[cur] == st1[l]){
        ret = max(ret, solve(cur + 1, idx, 1));
    }
    else if(cnt == 1 && st2[cur] == st1[r]){
        ret = max(ret, solve(cur + 1, idx, 2));
    }

    if(st2[cur] == s[idx]){
        if(idx < n - 2) ret = max(ret, solve(cur + 1, idx + 1, cnt));
    }

    return ret;
}

int main() {
    fastio;

    cin >> n >> st1 >> st2;
    cin >> l >> r;
    for(int i = 0;i < n;i++){
        if(i == l || i == r) continue;
        s += st1[i];
    }
    memset(dp, -1, sizeof(dp));

    if(solve(0, 0, 0)) cout << "YES\n";
    else cout << "NO\n";
    
    
    return 0;
}