#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sy, sx;
pll a[MAX];
bool u, d, l, r;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    cin >> sy >> sx;

    for(int i = 1;i <= n;i++){
        ll cy = a[i].x, cx = a[i].y;
        ll dy = sy - cy, dx = sx - cx;

        if(abs(dy) >= abs(dx)){
            if(dy >= 0) u = 1;
            if(dy <= 0) d = 1;
        }

        if(abs(dx) >= abs(dy)){
            if(dx >= 0) l = 1;
            if(dx <= 0) r = 1;
        }
    }

    cout << (u & d & l & r ? "NO" : "YES");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}