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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll org[MAX][MAX], a[MAX][MAX];

void init(){
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++) a[i][j] = org[i][j];
    }
}

void flip(ll cy, ll cx){
    a[cy][cx] ^= 1;
    if(cy) a[cy - 1][cx] ^= 1;
    if(cy != 9) a[cy + 1][cx] ^= 1;
    if(cx) a[cy][cx - 1] ^= 1;
    if(cx != 9) a[cy][cx + 1] ^= 1;
}

bool chk(){
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++) if(a[i][j]) return 0;
    }
    return 1;
}

ll solve(ll cur){
    init(); ll ret = 0;
    for(int i = 0;i < 10;i++){
        if(cur & (1ll << i)) flip(i, 0), ret++;
    }

    for(int i = 1;i < 10;i++){
        for(int j = 0;j < 10;j++){
            if(!a[j][i - 1]) continue;
            flip(j, i); ret++;
        }
    }

    return (chk() ? ret : INF); 
}

void run(){
    for(int i = 0;i < 10;i++) {
        cin >> st[i];
        for(int j = 0;j < 10;j++){
            org[i][j] = (st[i][j] == '#' ? 0 : 1);
        }
    }

    ll result = INF;
    for(int i = 0;i < (1ll << 10);i++){
        result = min(result, solve(i));
    }

    cout << (result == INF ? -1 : result);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

