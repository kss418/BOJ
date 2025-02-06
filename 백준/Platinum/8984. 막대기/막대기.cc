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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX]; ll dp[MAX][2], result;
vector <ll> xv, yv;
map <ll, ll> xm, ym;

void comp(vector <ll>& v, map <ll, ll>& mp){
    sort(all(v)); ll cnt = 0;
    for(auto& i : v){
        if(!mp.count(i)) mp[i] = ++cnt;
    }
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        xv.push_back(a[i].x);
        yv.push_back(a[i].y);
    }
    comp(xv, xm); comp(yv, ym);
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        ll x = xm[a[i].x], y = ym[a[i].y];
        ll d = abs(a[i].x - a[i].y) + m;
        ll a = dp[x][0], b = dp[y][1];
        dp[x][0] = max(dp[x][0], b + d);
        dp[y][1] = max(dp[y][1], a + d);
        result = max({result, dp[x][0], dp[y][1]});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}