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
constexpr ll MAX = 3010;
constexpr ll MOD = 998244353;
ll dp[MAX];
bool pal[MAX][MAX];
string st;

void init(){
    for(int d = 0;d < st.size();d++){
        for(int s = 0;s < st.size();s++){
            ll e = s + d;
            if(e >= st.size()) break;
            if(st[s] != st[e]) continue;

            if(s == e || s + 1 == e || pal[s + 1][e - 1]) pal[s][e] = 1; 
        }
    }
}

ll solve(ll cur){
    ll&ret = dp[cur];
    if(ret != -1) return ret;
    if(pal[0][cur]) return ret = 1;
    ret = INF;

    for(ll mid = 1;mid <= cur;mid++){
        if(!pal[mid][cur]) continue;
        ret = min(ret, solve(mid - 1) + 1);
    }

    return ret;
}

int main() {
    fastio;

    cin >> st; memset(dp, -1, sizeof(dp)); init();
    cout << solve(st.size() - 1);


    return 0;
}

