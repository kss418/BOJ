#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
mt19937 rd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
pll a[MAX]; ll num;

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
} ccw;

ll cnt(pll l, pll r){
    ll ret = 0;
    for(int i = 1;i <= n;i++){
        ret += (ccw.ret(l, a[i], r) == 0);
    }
    return ret;
}
    
void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    num = (n * m) / 100 + ((n * m) % 100 ? 1 : 0); 

    if(n == 1){ cout << "possible"; return; }
    uniform_int_distribution <int> rnd(1, n);

    for(int i = 1;i <= 150;i++){
        int l = rnd(rd);
        int r = rnd(rd);
        while(l == r) r = rnd(rd);
        if(cnt(a[l], a[r]) >= num){
            cout << "possible"; return;
        }
    }

    cout << "impossible";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

