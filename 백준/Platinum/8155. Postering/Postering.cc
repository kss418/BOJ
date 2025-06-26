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
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll result, v[MAX], cnt, pre = -1;
vector <ll> use;
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
vector <pll> arr;

void init(){
    while(!use.empty()){
        v[use.back()] = 0;
        use.pop_back();
    }

    result += cnt; cnt = 0;
}

int main() {
    fastio;

    cin >> n; _uf uf(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        arr.push_back({a[i].y, i});
    }
    sort(all(arr)); reverse(all(arr));

    for(auto& i : arr){
        auto[num, idx] = i;
        if(pre > num) init(); cnt++;
        if(v[uf.find(idx + 1)]) cnt--;
        if(v[uf.find(idx - 1)]) cnt--;

        if(a[idx - 1].y >= a[idx].y) uf.merge(idx - 1, idx);
        if(a[idx + 1].y >= a[idx].y) uf.merge(idx + 1, idx);
        v[uf.find(idx)] = 1; use.push_back(uf.find(idx));

        pre = num; 
    }
    init();

    cout << result;
    
     
    return 0;
}