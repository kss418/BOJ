#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], c;
map <pll, ll> num;
ll dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};

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

void run(){
    cin >> n; ll x = 0; _uf uf(n);
    a[0] = INF;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] <= a[i - 1]) x++;
        num[{x, a[i]}] = ++c;
    }

    x = 0;
    for(int i = 1;i <= n;i++){
        ll y = a[i];
        if(a[i] <= a[i - 1]) x++;
        ll now = num[{x, y}];

        for(int j = 0;j < 4;j++){
            ll ny = y + dy[j], nx = x + dx[j];
            if(!num.count({nx, ny})) continue;
            uf.merge(now, num[{nx, ny}]);
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        if(uf.find(i) == i) result++;
    }
    
    cout << result << "\n";
    cout << n;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}