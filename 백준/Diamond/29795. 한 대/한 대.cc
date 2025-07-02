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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX];

class _cht { 
public:
    class line{
        public:
        ll a, b;
        line() : line(MINF, MINF){}
        line(ll a, ll b) : a(a), b(b){}
        ll f(ll x){ return a * x + b; }
    };

    _cht(){}
    vector <line> v; ll idx = 0;

    f128 cross(line& a, line& b){
        return (b.b - a.b) / (a.a - b.a);
    }

    bool chk(const line& a, const line& b, const line& c) const{
        return (i128)(a.b - b.b) * (c.a - b.a) >= (i128)(b.b - c.b) * (b.a - a.a);
    }
    bool chk(const line& a, const line& b, ll c) const{
        return (i128)c * (b.a - a.a) >= a.b - b.b;
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

    ll ls(ll x){ // linear search
        while(idx + 1 < v.size() && chk(v[idx], v[idx + 1], x)) idx++;
        return v[idx].f(x);
    }

    ll bs(ll x){ // binary search
        ll lo = 0, hi = v.size() - 1;
        while(lo < hi){
            ll mid = (lo + hi) >> 1ll;
            if(chk(v[mid], v[mid + 1], x)) lo = mid + 1;
            else hi = mid;
        }

        return v[lo].f(x);
    }
};

void run(){
    cin >> n >> m; _cht cht; 
    ll mx1 = MINF, mx2 = MINF;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        if(a[i].x == 1) mx1 = max(mx1, a[i].y);
        else mx2 = max(mx2, a[i].y);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) cht.add(a[i].x, a[i].y);
    
    while(m--){
        ll s, e; cin >> s >> e;
        ll result = 0;

        while(s < e){
            if(cht.v[0].a == 1 && (cht.v.size() == 1 || s < cht.cross(cht.v[0], cht.v[1]))){
                if(cht.v[0].b <= 0){
                    result = -1; break;
                }

                ll nxt = cht.v.size() != 1 ? floor((ld)cht.cross(cht.v[0], cht.v[1])) : e;
                ll cnt = (nxt - s) / cht.v[0].b + ((nxt - s) % cht.v[0].b ? 1 : 0);
                s += cnt * cht.v[0].b;
                result += cnt;
            }
            else{
                ll nxt = cht.bs(s);
                if(nxt <= s){
                    result = -1; break;
                }

                s = nxt; result++;
            }
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

