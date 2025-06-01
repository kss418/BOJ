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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
map <ll, ll> pos;
multiset <ll> num;
ll all, result = INF;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, [](pll a, pll b){
        return a.y < b.y;
    });

    for(int i = 1;i <= n;i++){
        if(a[i].y != a[i - 1].y) all++;
    }
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        if(pos.count(a[i].y)){
            num.erase(num.find(pos[a[i].y]));
        }

        pos[a[i].y] = a[i].x;
        num.insert(a[i].x);

        if(num.size() == all){
            result = min(result, *--num.end() - *num.begin());
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

