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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], c[2];
vector <ll> num[2];

ll dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    fastio;

    ll cnt = 0;
    while(1){
        cin >> n; if(!n) break; ++cnt;
        for(int i = 0;i < 2;i++) num[i].clear();

        for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
        for(int i = 0;i < 2;i++) cin >> c[i].x >> c[i].y;
        
        for(int i = 0;i < 2;i++){
            for(int j = 1;j <= n;j++) {
                num[i].push_back(dist(c[i], a[j]));
            }
            sort(all(num[i]));
        }

        cin >> m;
        cout << "Case " << cnt << ":\n";
        while(m--){
            ll r1, r2; cin >> r1 >> r2;
            ll lb1 = upper_bound(all(num[0]), r1 * r1) - num[0].begin();
            ll lb2 = upper_bound(all(num[1]), r2 * r2) - num[1].begin();

            cout << max(n - lb1 - lb2, 0ll) << "\n";
        }
    }
    
     
    return 0;
}