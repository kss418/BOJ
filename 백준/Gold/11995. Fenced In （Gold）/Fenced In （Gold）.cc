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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll ay[MAX], ax[MAX], x, y;

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

ll num(ll cy, ll cx){
    return cy * (n + 1) + cx;
}

void run(){
    cin >> x >> y >> n >> m; _uf uf((n + 1) * (m + 1));
    for(int i = 1;i <= n;i++) cin >> ax[i];
    for(int i = 1;i <= m;i++) cin >> ay[i];
    ax[n + 1] = x; ay[m + 1] = y;
    sort(ax, ax + n + 1); sort(ay, ay + m + 1);

    for(int i = 0;i <= n;i++) ax[i] = ax[i + 1] - ax[i];
    for(int i = 0;i <= m;i++) ay[i] = ay[i + 1] - ay[i];
    sort(ax, ax + n + 1); sort(ay, ay + m + 1);

    ll cy = 0, cx = 0, result = 0;
    while(cx <= n || cy <= m){
        if(cy <= m && ay[cy] < ax[cx]){
            for(int i = 0;i < n;i++){
                if(uf.same(num(cy, i), num(cy, i + 1))) continue;
                uf.merge(num(cy, i), num(cy, i + 1));
                result += ay[cy];
            }
            cy++;
        }
        else{
            for(int i = 0;i < m;i++){
                if(uf.same(num(i, cx), num(i + 1, cx))) continue;
                uf.merge(num(i, cx), num(i + 1, cx));
                result += ax[cx];
            }
            cx++;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

