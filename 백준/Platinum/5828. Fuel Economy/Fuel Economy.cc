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
constexpr ll MAX = 50101;
constexpr ll MOD = 998244353;
pll a[MAX];
ll nxt[MAX];
multiset <pll> num;
deque <ll> q;

int main() {
    fastio;

    ll mx, f; cin >> n >> mx >> f >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1); a[0].y = INF;
    a[n + 1] = { m, INF };

    for(int i = n;i >= 0;i--){
        while(!q.empty() && a[q.back()].y >= a[i].y) {
            q.pop_back();
        }

        if(q.empty()) nxt[i] = n + 1;
        else nxt[i] = q.back();
        q.push_back(i);
    }

    ll result = 0, flag = 1;
    for(int i = 1;i <= n;i++){
        f -= a[i].x - a[i - 1].x;
        if(f < 0) flag = 0;

        ll diff = a[nxt[i]].x - a[i].x;
        if(diff > mx){
            result += (mx - f) * a[i].y; f = mx;
        }
        else{
            result += max(diff - f, 0ll) * a[i].y;
            f = max(diff, f);
        }
    }
    if(a[n + 1].x - a[n].x > mx) flag = 0;
    
    if(!flag) cout << -1;
    else cout << result;

    
    return 0;

}