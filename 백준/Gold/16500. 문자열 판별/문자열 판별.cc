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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
map <string, bool> cnt;
ll dp[MAX];

ll solve(ll cur){
    ll&ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = cur;i >= 0;i--){
        string now = s.substr(i, cur - i + 1);
        if(!cnt.count(now)) continue;
        if(i) ret |= solve(i - 1);
        else ret = 1;
    }

    return ret;
}

int main() {
    fastio;

    cin >> s >> n;
    for(int i = 0;i < n;i++) {
        string st; cin >> st;
        cnt[st] = 1;
    }
    
    memset(dp, -1, sizeof(dp)); 
    cout << solve(s.size() - 1);


    return 0;
}