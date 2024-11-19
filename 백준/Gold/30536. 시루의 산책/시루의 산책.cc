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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll p[MAX], r[MAX];
bool dis[MAX], v[MAX];
deque <ll> q;

ll dist(pll a, pll b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 1;i <= m;i++) cin >> p[i];
    for(int i = 0;i <= m;i++) cin >> r[i];

    for(int i = 1;i <= m;i++){
        dis[p[i]] = 1;
        for(int j = 1;j <= n;j++){
            if(p[i] == j) continue;
            ll d = dist(a[p[i]], a[j]);
            if(d <= r[i] * r[i]) dis[j] = 1;
        }   
    }
    
    for(int i = 1;i <= n;i++){
        if(dis[i]) continue;
        q.push_back(i);
    }

    ll result = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        if(v[cur]) continue; v[cur] = 1; result++;

        for(int i = 1;i <= n;i++){
            if(v[i]) continue;
            if(dist(a[cur], a[i]) <= r[0] * r[0]) q.push_back(i);
        }
    }
    
    cout << result;


    return 0;
}

