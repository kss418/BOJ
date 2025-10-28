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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

class _crt{
public:
    _crt(){} vector <pll> arr;
    tll gcd(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto[g, x, y] = gcd(b, a % b);
        return { g, y, x - a / b * y };
    }

    void clear(){ arr.clear(); }
    void add(ll a, ll m){ arr.push_back({a, m}); }

    ll mod(ll a, ll m){
        a %= m; if(a >= 0) return a;
        return a + m;
    }

    pll crt(pll a, pll b){
        auto[g, cx, cy] = gcd(a.y, b.y);
        ll lcd = a.y / g * b.y;
        if((b.x - a.x) % g) return {-1, -1};
        ll r = mod((b.x - a.x) / g, b.y); 
        ll l = mod(cx * r, b.y); 
        ll ret = mod(a.x + l * a.y, lcd);

        return { ret, lcd };
    }

    pll ret(){
        pll cur = arr[0];
        for(int i = 1;i < arr.size();i++){
            cur = crt(cur, arr[i]);
            if(cur.x == -1) return {-1, -1};
        }
        return cur;
    }
};

void run(){
    cin >> n; _crt crt;
    for(int i = 0;i < n;i++) cin >> st[i];
    cin >> s;

    for(int i = 0;i < n;i++){
        ll idx = -1;
        for(int j = 0;j < st[i].size();j++){
            if(st[i][j] != s[i]) continue;
            idx = j; break;
        }

        if(idx == -1){
            cout << -1; return;
        }

        crt.add(idx, st[i].size());
    }

    cout << crt.ret().x;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}