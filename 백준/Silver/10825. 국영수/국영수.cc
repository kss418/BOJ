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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    string name;
    ll kr, en, ma;

    bool operator < (const node& ot) const{
        if(kr != ot.kr) return kr > ot.kr;
        else if(en != ot.en) return en < ot.en;
        else if(ma != ot.ma) return ma > ot.ma;
        return name < ot.name;
    }
} a[MAX];

int main() {
    fastio;
    
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].name >> a[i].kr >> a[i].en >> a[i].ma;
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++) cout << a[i].name << "\n";
    
    
    return 0;
}