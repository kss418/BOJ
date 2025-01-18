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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt[MAX][MAX];
pll a[MAX];

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        for(int j = a[i].x;j < a[i].x + 10;j++){
            for(int k = a[i].y;k < a[i].y + 10;k++) cnt[j][k] = 1;
        }
    }

    ll result = 0;
    for(int i = 1;i <= 100;i++){
        for(int j = 1;j <= 100;j++) result += cnt[i][j];
    }
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

