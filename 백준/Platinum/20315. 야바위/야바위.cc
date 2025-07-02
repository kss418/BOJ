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

ll result[MAX], org[MAX], idx = 1;
set <ll> num[MAX];
class node{
public:
    ll op, a, b;
}; node a[MAX];

class query{
public:
    ll idx, st, num;
    node nd;

    bool operator < (const query& ot) const{
        return num < ot.num;
    }
}; query b[MAX];

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i < m;i++) cin >> a[i].op >> a[i].a >> a[i].b;
    for(int i = 1;i <= k;i++){
        cin >> b[i].st >> b[i].num; b[i].idx = i;
        cin >> b[i].nd.op >> b[i].nd.a >> b[i].nd.b;
        num[b[i].st].insert(i);
    }

    sort(b + 1, b + k + 1);
    for(int i = 1;i <= n;i++) org[i] = i;
    for(int i = 1;i <= m;i++){
        while(idx <= k && b[idx].num == i){
            if(b[idx].nd.op == 1){
                if(num[org[b[idx].nd.a]].count(b[idx].idx)){
                    num[org[b[idx].nd.a]].erase(b[idx].idx);
                    num[org[b[idx].nd.b]].insert(b[idx].idx);
                }
                else if(num[org[b[idx].nd.b]].count(b[idx].idx)){
                    num[org[b[idx].nd.b]].erase(b[idx].idx);
                    num[org[b[idx].nd.a]].insert(b[idx].idx);
                }
            }
            else{
                if(num[org[b[idx].nd.a]].count(b[idx].idx)){
                    num[org[b[idx].nd.a]].erase(b[idx].idx);
                    num[org[b[idx].nd.b]].insert(b[idx].idx);
                }
            }

            idx++;
        }
        
        if(i == m) break;
        if(a[i].op == 1) swap(org[a[i].a], org[a[i].b]);
        else{
            if(num[org[a[i].a]].size() > num[org[a[i].b]].size()) swap(org[a[i].a], org[a[i].b]);
            for(auto& j : num[org[a[i].a]]) num[org[a[i].b]].insert(j);
            num[org[a[i].a]].clear();
        }
    }

    for(int i = 1;i <= n;i++){
        for(auto& j : num[org[i]]) result[j] = i;
    }

    for(int i = 1;i <= k;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

