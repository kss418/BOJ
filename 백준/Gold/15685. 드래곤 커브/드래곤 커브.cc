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
ll dx[4] = { 1, 0, -1, 0 };
ll dy[4] = { 0, -1, 0, 1 }; 
map <pll, bool> arr;
map <pll, bool> cur, tmp;

pll rot(pll a, pll org){
    ll rx = org.x + a.y - org.y, ry = org.y - a.x + org.x;
    return {rx, ry};
}

void rotate(pll end){
    for(auto & i : cur){
        tmp[i.x] = 1; tmp[rot(i.x, end)] = 1;
    }
    cur = tmp; tmp.clear();
}

void curve(ll cx, ll cy, ll dir, ll gen){
    cur.clear(); tmp.clear();
    cur[{cy, cx}] = 1; cur[{cy + dy[dir], cx + dx[dir]}] = 1;
    pll st = {cy, cx};
    pll end = {cy + dy[dir], cx + dx[dir]};

    while(gen--){ 
        rotate(end);
        end = rot(st, end); 
    }
    
    for(auto& i : cur) arr[i.x] = 1;
}
 
bool sq(ll cy, ll cx){
    if(!arr.count({cy, cx}) || !arr.count({cy + 1, cx})) return 0;
    if(!arr.count({cy, cx + 1}) || !arr.count({cy + 1, cx + 1})) return 0;
    return 1;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll cx, cy, d, g; cin >> cx >> cy >> d >> g;
        curve(cx, cy, d, g);
    }
    
    ll result = 0;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(sq(i, j)) result++;
        }
    }

    cout << result;

     
    return 0;
}