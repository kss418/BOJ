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
constexpr ll MAX = 10101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], p[2];
ll c[2];
using pld = pair <ld, ld>;
pair <pld, pld> pl[2];
ld pi = M_PI;

class _li{
public:
    _li() {}

    ld ccw(pld v1, pld v2, pld v3){
        ld num = (v2.x - v1.x) * (v3.y - v1.y);
        num -= (v3.x - v1.x) * (v2.y - v1.y);

        if(num > 0) return 1; 
        else if(num < 0) return -1; 
        return 0;
    }

    bool ret(pair<pld, pld> a, pair<pld, pld> b) {
        return ret(a.x, a.y, b.x, b.y);
    }
    bool ret(pld av1, pld av2, pld bv1, pld bv2){
        ld ac = ccw(av1, av2, bv1) * ccw(av1, av2, bv2);
        ld bc = ccw(bv1, bv2, av1) * ccw(bv1, bv2, av2);

        if(!ac && !bc){
            if(av1 > av2) swap(av1, av2);
            if(bv1 > bv2) swap(bv1, bv2);
            return bv1 <= av2 && av1 <= bv2;
        }

        return ac <= 0 && bc <= 0;
    }
};

pair <ld, ld> tf(ll dir, ll len = 1000){
    return {len * sinl(2 * pi * (ld)dir / (ld)3600), len * cosl(2 * pi * (ld)dir / (ld)3600)};
}

void run(){
    cin >> n; _li li;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 0;i < 2;i++) cin >> p[i].x >> p[i].y;
    for(int i = 0;i < 2;i++) pl[i] = {{0, 0}, tf(p[i].x, p[i].y)};

    for(int i = 1;i <= n;i++){
        pair <pld, pld> now = {tf(a[i].x), tf(a[i].y)};
        for(int j = 0;j < 2;j++){
            c[j] += li.ret(now, pl[j]);
        }
    }

    cout << (c[0] % 2 == c[1] % 2 ? "YES" : "NO");
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}