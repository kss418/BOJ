#include <bits/stdc++.h>
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
short a[MAX][MAX];
ll result;
class node{
public:
    short a[4], sz;
    bool full;
    void insert(int num){
        if(!num || full) return;
        for(int i = 0;i < sz;i++) if(a[i] == num) return;
        a[sz] = num; sz++;
    
        if(sz != 4) return;
        full = 1; sz = 1; a[0] = -1;
    }
}; node ul[MAX][MAX], ur[MAX][MAX], dl[MAX][MAX], dr[MAX][MAX];

void merge(node& a, node& b){
    if(a.full) return;
    if(b.full){
        a.full = 1; a.sz = 1;
        a.a[0] = -1;
    }

    for(int i = 0;i < b.sz;i++){
        if(a.sz >= 4 || a.full) return;
        a.insert(b.a[i]);
    }
}

bool same(short a, short b){
    if(a == -1 || b == -1) return 0;
    return a == b;
}

bool chk(short cy, short cx){
    node& na = ul[cy - 1][cx - 1], nb = ur[cy - 1][cx + 1];
    node& nc = dl[cy + 1][cx - 1], nd = dr[cy + 1][cx + 1];

    for(int i = 0;i < na.sz;i++){
        for(int j = 0;j < nb.sz;j++){
            if(same(na.a[i], nb.a[j])) continue;
            for(int k = 0;k < nc.sz;k++){
                if(same(na.a[i], nc.a[k])) continue;
                if(same(nb.a[j], nc.a[k])) continue;
                for(int l = 0;l < nd.sz;l++){
                    if(same(na.a[i], nd.a[l])) continue;
                    if(same(nb.a[j], nd.a[l])) continue;
                    if(same(nc.a[k], nd.a[l])) continue;
                    return 1;
                }
            }
        }
    }

    return 0;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            ul[i][j].insert(a[i][j]);
            merge(ul[i][j], ul[i - 1][j]);
            merge(ul[i][j], ul[i][j - 1]);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = n;j >= 1;j--){
            ur[i][j].insert(a[i][j]);
            merge(ur[i][j], ur[i - 1][j]);
            merge(ur[i][j], ur[i][j + 1]);
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= n;j++){
            dl[i][j].insert(a[i][j]);
            merge(dl[i][j], dl[i + 1][j]);
            merge(dl[i][j], dl[i][j - 1]);
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = n;j >= 1;j--){
            dr[i][j].insert(a[i][j]);
            merge(dr[i][j], dr[i + 1][j]);
            merge(dr[i][j], dr[i][j + 1]);
        }
    }

    for(int i = 2;i < n;i++){
        for(int j = 2;j < n;j++){
            if(a[i][j]) continue;
            result += chk(i, j);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}