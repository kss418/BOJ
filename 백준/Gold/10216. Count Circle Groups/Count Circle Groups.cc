#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
vector <tll> arr;

class _uf { 
public:
    ll n; vector <ll> p, size;
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); size.resize(n + 1);
        fill(p.begin(), p.end(), -1);
        fill(size.begin(), size.end(), 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        p[b] = a, size[a] += size[b];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};

ll dist(ll x1, ll x2, ll y1, ll y2){
    ll dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> n; arr.clear(); _uf uf(n);
        for(int i = 1;i <= n;i++){
            ll x, y, d; cin >> x >> y >> d;
            arr.push_back({x, y, d});
        }

        for(int i = 0;i < n;i++){
            auto[x1, y1, d1] = arr[i];
            for(int j = i + 1;j < n;j++){
                auto[x2, y2, d2] = arr[j];
                if(dist(x1,x2,y1,y2) <= (d1 + d2) * (d1 + d2)) uf.merge(i, j);
            }
        }

        ll result = 0;
        for(int i = 0;i < n;i++){
            if(uf.find(i) == i) result++;
        }

        cout << result << "\n";
    }
    

    return 0;
}