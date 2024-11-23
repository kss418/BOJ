#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, [](pll a, pll b){
        return a.y < b.y;
    });

    ll result = INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ll sx = min(a[i].x, a[j].x) - 1;
            ll ex = max(a[i].x, a[j].x) + 1;

            vector <ll> yv;
            for(int k = 1;k <= n;k++){
                if(a[k].x <= sx || a[k].x >= ex) continue;
                yv.push_back(a[k].y);
            }

            ll diff = INF;
            for(int i = 0;i < yv.size();i++){
                if(i + (n >> 1) - 1 >= yv.size()) break;
                ll s = yv[i] - 1, e = yv[i + (n >> 1) - 1] + 1;
                diff = min(diff, e - s);
            }
            
            if(diff == INF) continue;
            result = min(result, (ex - sx) * diff);
        }
    }

    cout << result;


    return 0;
}

