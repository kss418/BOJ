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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], flag = 1;
vector <vector <ll>> result;
vector <ll> un[MAX];

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
    cin >> n; _uf uf(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
            if(!a[i][j]) uf.merge(i, j);
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){;
            if(uf.same(i, j) == a[i][j]) flag = 0;
        }
    }

    for(int i = 0;i < n;i++) un[uf.find(i)].push_back(i);
    for(int i = 0;i < n;i++) {
        if(uf.find(i) != i) continue;
        sort(all(un[i]));
        result.push_back(un[i]);
        if(un[i].size() < 2) flag = 0;
    }

    if(!flag){ cout << 0; return; }
    cout << result.size() << "\n";
    sort(all(result));
    for(auto& i : result){
        sort(all(i));
        for(auto& j : i) cout << j + 1 << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}