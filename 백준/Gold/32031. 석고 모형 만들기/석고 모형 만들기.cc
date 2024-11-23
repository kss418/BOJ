#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];

ll num(ll x, ll y, ll nx, ll ny, ll nz){
    ll ret = 1600 * x + 8 * y + 4 * nx + 2 * ny + nz;
    return ret;
}

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
}; _uf uf(330000);


void m1(ll cx, ll cy){
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 1;j++){
            uf.merge(num(cx, cy, i, j, 0), num(cx, cy, i, j, 1));
        }
    }
}

void m2(ll cx, ll cy){
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 1;j++){
            uf.merge(num(cx, cy, i, 0, j), num(cx, cy, i, 1, j));
        }
    }
}

void m3(ll cx, ll cy){
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 1;j++){
            uf.merge(num(cx, cy, 0, i, j), num(cx, cy, 1, i, j));
        }
    }
}

void m4(ll cx, ll cy){
    if(cy){
        for(int i = 0;i <= 1;i++){
            for(int j = 0;j <= 1;j++){
                uf.merge(num(cx, cy, 0, i, j), num(cx, cy - 1, 1, i, j));
            }
        }
    }

    if(cx){
        for(int i = 0;i <= 1;i++){
            for(int j = 0;j <= 1;j++){
                uf.merge(num(cx, cy, i, 1, j), num(cx - 1, cy, i, 0, j));
            }
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == 'O') m1(i, j);
            else if(st[i][j] == 'I') m2(i, j);
            else m3(i, j);
            m4(i, j);
        }
    }

    ll result = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int x = 0;x <= 1;x++){
                for(int y = 0;y <= 1;y++){
                    for(int z = 0;z <= 1;z++){
                        result += (uf.find(num(i, j, x, y, z)) == num(i, j, x, y, z));
                    }
                }
            }
        }
    }

    cout << result;


    return 0;
}

