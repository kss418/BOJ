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
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], dp[MAX];

class _cht { 
public:
    class line{
        public:
        ll a, b;
        // max line() : line(0, MINF){}
        line() : line(0, INF){}
        line(ll a, ll b) : a(a), b(b){}
        ll f(ll x){ return a * x + b; }
    };

    _cht(){}
    vector <line> v; ll idx = 0;

    bool chk(const line& a, const line& b, const line& c) const{
        return (__int128_t)(a.b - b.b) * (c.a - b.a) >= (__int128_t)(b.b - c.b) * (b.a - a.a);
    }
    bool chk(const line& a, const line& b, ll c) const{
        return (__int128_t)c * (b.a - a.a) <= a.b - b.b;
        // max return (__int128_t)c * (b.a - a.a) >= a.b - b.b;
    }

    void add(ll a, ll b){
        line cur = {a, b};
        if(idx < v.size() && v.back().a == cur.a){
            if(cur.b < v.back().b) cur = v.back();
            v.pop_back();
        }

        while(v.size() >= idx + 2 && chk(v[v.size() - 2], v.back(), cur)) v.pop_back();
        v.push_back(cur); 
    }

    ll query(ll x){
        while(idx + 1 < v.size() && chk(v[idx], v[idx + 1], x)) idx++;
        return v[idx].f(x);
    }
};


void run(){
    cin >> n; _cht cht;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];

    dp[1] = 0; cht.add(b[1], dp[1]);
    for(int i = 2;i <= n;i++){
        dp[i] = cht.query(a[i]);
        cht.add(b[i], dp[i]);
    }

    cout << dp[n];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

