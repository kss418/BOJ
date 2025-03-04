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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll result = INF;
pair<ll, char> a[MAX];
set <ll> num;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        char c; ll idx; cin >> c >> idx;
        a[i] = {idx, c}; num.insert(idx);
    }
    sort(a + 1, a + n + 1);

    for(auto& cur : num){
        ll cnt = 0;
        for(int i = 1;i <= n;i++){
            if(a[i].x < cur && a[i].y == 'L') cnt++;
            else if(a[i].x > cur && a[i].y == 'G') cnt++;
        }
        result = min(result, cnt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}