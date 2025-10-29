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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], now;

class _ccw{
public:
    _ccw() {}

    ll ret(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
        return ret({x1, y1}, {x2, y2}, {x3, y3});
    }
    ll ret(pll v1, pll v2, pll v3){
        ll num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }
};

void run(){
    cin >> n; _ccw ccw;
    for(int i = 1;i <= n;i++) cin >> a[i].y >> a[i].x;
    cin >> now.y >> now.x;
    
    sort(a + 1, a + n + 1, [&ccw](pll a, pll b){
        a.x -= now.x; a.y -= now.y;
        b.x -= now.x; b.y -= now.y;

        if((pll(a.x, a.y) > pll(0, 0)) ^ (pll(b.x, b.y) > pll(0, 0))){
            return pll(a.x, a.y) > pll(b.x, b.y);
        }

        if(ccw.ret(a, b, pll(0, 0))) return ccw.ret(a, b, pll(0, 0)) > 0;
        
        auto dist = [](pll p){ return p.x * p.x + p.y * p.y; };
        return dist(a) > dist(b);
    });

    reverse(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) cout << a[i].y << " " << a[i].x << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}