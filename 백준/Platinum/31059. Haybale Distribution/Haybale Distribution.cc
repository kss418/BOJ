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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], pre[1010101][2], suf[1010101][2];

class _ts { // 0-based index
public:
    ll l, r, s, e;
    _ts(ll l, ll r, ll s, ll e) {
        this->l = l; this->r = r;
        this->s = s; this->e = e;
    }

    ll f(ll cur) {
       ll ret = pre[cur][0] * s + suf[cur][0] * e;
       return ret;
    }

    ll ret() {
        while (r - l > 3) {
            ll st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }

        ll result = INF;
        for(ll cur = l; cur <= r;cur++) result = min(result, f(cur));

        return result;
    }
};

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pre[a[i]][1]++;
        suf[a[i]][1]++;
    }

    for(int i = 1;i < 1010101;i++){
        pre[i][1] += pre[i - 1][1];
        pre[i][0] = pre[i - 1][0] + pre[i - 1][1];
    }

    for(int i = 1010099;i >= 0;i--){
        suf[i][1] += suf[i + 1][1];
        suf[i][0] = suf[i + 1][0] + suf[i + 1][1];
    }

    cin >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        _ts ts(0, 1000000, s, e);
        cout << ts.ret() << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}