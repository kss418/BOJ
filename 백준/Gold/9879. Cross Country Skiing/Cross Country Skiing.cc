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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], b[MAX][MAX], cnt;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 0);
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

class node{
public:
    ll s, e, d;
    bool operator < (const node& ot) const{
        return d < ot.d;
    }
};
vector <node> arr;

bool outrange(ll cy, ll cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

void run(){
    cin >> n >> m; _uf uf(n * m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) cin >> a[i][j];
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> b[i][j];
            uf.si[i * m + j] = b[i][j];
            cnt += b[i][j];
        }
    }

    if(cnt <= 1){ cout << 0; return; }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < 4;k++){
                ll ny = i + dy[k], nx = j + dx[k];
                if(outrange(ny, nx)) continue;
                arr.push_back({i * m + j, ny * m + nx, abs(a[i][j] - a[ny][nx])});
            }
        }
    }

    ll result = 0;
    sort(all(arr));
    for(auto& [s, e, d] : arr){
        result = d;
        uf.merge(s, e);
        if(uf.size(s) == cnt) break;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

