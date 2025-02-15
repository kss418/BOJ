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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result;
vector <pll> a, b;
map <ll, ll> sum;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll idx, v; cin >> idx >> v;
        a.push_back({idx, v});
    }
    
    cin >> m;
    for(int i = 1;i <= m;i++) {
        ll idx, v; cin >> idx >> v;
        b.push_back({idx, v});
    }
    sort(all(a)); sort(all(b));

    ll now = 0;
    sum.insert({MINF, 0});
    for(auto& i : b){
        now += i.y;
        sum.insert({i.x, now});
    }

    ll s, e; cin >> s >> e;
    for(auto& i : a){
        auto l = --sum.upper_bound(i.x + s - 1);
        auto r = --sum.upper_bound(i.x + e);
        result += i.y * (r->y - l->y);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

