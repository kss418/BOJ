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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], cy = 1, cx = 1;
vector <ll> xv[MAX], yv[MAX];
vector <ll> sx[MAX], sy[MAX];
map <pll, ll> c;
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pll cal(ll dir, ll v, ll cy, ll cx){   
    cy += dy[dir] * v; cx += dx[dir] * v;
    return {cy, cx};    
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        ll cx, cy, v; cin >> cx >> cy >> v;
        yv[cy].push_back(cx);
        xv[cx].push_back(cy);
        c[{cy, cx}] = v;
    }

    for(int i = 1;i < MAX;i++){
        sort(all(xv[i])); sort(all(yv[i]));
        for(int j = 0;j < xv[i].size();j++){
            ll now = c[{xv[i][j], i}];
            ll cur = (j ? sx[i][j - 1] + now : now);
            sx[i].push_back(cur);
        }

        for(int j = 0;j < yv[i].size();j++){
            ll now = c[{i, yv[i][j]}];
            ll cur = (j ? sy[i][j - 1] + now : now);
            sy[i].push_back(cur);
        }
    }

    ll result = 0;
    while(m--){
        ll dir, v; cin >> dir >> v;
        auto[ny, nx] = cal(dir, v, cy, cx);
      
        if(cx != nx){
            ll mx = max(cx, nx), mn = min(cx, nx);
            if(cx > nx) mx--, mn--;
            ll s = upper_bound(all(yv[cy]), mn) - yv[cy].begin();
            ll e = upper_bound(all(yv[cy]), mx) - yv[cy].begin() - 1;
            if(e >= s) result += sy[cy][e] - (s ? sy[cy][s - 1] : 0);
        }
        else{
            ll mx = max(cy, ny), mn = min(cy, ny);
            if(cy > ny) mx--, mn--;
            ll s = upper_bound(all(xv[cx]), mn) - xv[cx].begin();
            ll e = upper_bound(all(xv[cx]), mx) - xv[cx].begin() - 1;
            if(e >= s) result += sx[cx][e] - (s ? sx[cx][s - 1] : 0);
        }

        cy = ny; cx = nx;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}