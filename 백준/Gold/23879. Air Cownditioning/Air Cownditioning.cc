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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
constexpr ll MID = 100100;
ll a[MAX], b[MAX], result, cnt[2];
vector <ll> idx[2 * MAX];
ll mx[2] = {MINF, INF};

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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        cin >> b[i], a[i] -= b[i];
        idx[a[i] + MID].push_back(i);
        if(a[i] > 0) mx[0] = max(mx[0], a[i]);
        if(a[i] < 0) mx[1] = min(mx[1], a[i]);
    }

    _uf uf(n);
    for(int i = mx[0];i >= 1;i--){
        for(auto& j : idx[i + MID]){
            cnt[0]++;
            if(j != 1 && a[j - 1] >= a[j]){
                if(!uf.same(j, j - 1)) uf.merge(j, j - 1), cnt[0]--;
            }
            
            if(j != n && a[j + 1] >= a[j]){
                if(!uf.same(j, j + 1)) uf.merge(j, j + 1), cnt[0]--;
            }
        }
        
        result += cnt[0];
    }

    for(int i = mx[1];i <= -1;i++){
        for(auto& j : idx[i + MID]){
            cnt[1]++;
            if(j != 1 && a[j - 1] <= a[j]){
                if(!uf.same(j, j - 1)) uf.merge(j, j - 1), cnt[1]--;
            }
            
            if(j != n && a[j + 1] <= a[j]){
                if(!uf.same(j, j + 1)) uf.merge(j, j + 1), cnt[1]--;
            }
        }
        
        result += cnt[1];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}