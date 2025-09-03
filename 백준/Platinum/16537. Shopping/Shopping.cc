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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result[MAX], pre[MAX], num = 1;
vector <vector <ll>> tr;
vector <ll> tmp;

class _gcd {
public:
    _gcd() {}

    tll init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

void run(){
    cin >> n; _gcd gcd; 
    tr.clear(); tmp.clear(); num = 1;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m;

    ll g = a[1];
    for(int i = 2;i <= n;i++) g = gcd.ret(g, a[i]);

    if(m % g){ cout << "No solutions" << "\n"; return; }
    ll div = m / g;

    for(int i = 1;i <= n;i++) pre[i] = 1, result[i] = 0;
    g = a[1]; result[1] = 1;

    for(int i = 2;i <= n;i++){
        ll tmp = g;
        auto [nxt, x, y] = gcd.init(g, a[i]);
        g = nxt;
        if(tmp == g) continue;

        pre[i - 1] = x;
        result[i] = y;
    }

    bool f = 0;
    for(int i = n;i >= 1;i--){
        ll nxt = num * abs(pre[i]);
        if(pre[i] < 0) f ^= 1;
        if(nxt > 1000000000){
            tmp.push_back(num);
            num = abs(pre[i]);
        }
        else num = nxt;

        vector <ll> now;
        bool flag = result[i] < 0;
        now.push_back(abs(result[i]) * (f ^ flag ? -1 : 1));
        if(result[i]){
            for(auto& j : tmp) now.push_back(j);
            if(num != 1) now.push_back(num);
        }

        tr.push_back(now);
    }

    reverse(all(tr));
    for(auto& i : tr){
        cout << div * (i[0] < 0 ? -1 : 1) << "*";
        cout << abs(i[0]);
        for(int j = 1;j < i.size();j++){
            cout << "*" << i[j];
        }
        cout << " ";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}