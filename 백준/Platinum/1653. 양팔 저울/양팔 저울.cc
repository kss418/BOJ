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
constexpr ll MAX = 10; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> vec, result;
ll a[MAX];

bool cal(){
    ll a = 0, b = 0;
    for(int i = 4;i >= 0;i--) a += vec[i] * (5 - i);
    for(int i = 5;i <= 9;i++) b += vec[i] * (i - 4);

    return a == b;
}

ll num(const vector <ll>& vec){
    ll ret = 0;
    for(auto& i : vec) ret *= 10, ret += i;
    return ret;
}

void init(){
    while(vec.size() != 10) vec.push_back(0);
    sort(all(vec));

    while(1){
        if(cal()) result.push_back(num(vec));
        if(!next_permutation(all(vec))) break;
    }
}

void run(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    cin >> m;
    
    for(int i = 0;i < (1ll << n);i++){
        vec.clear();
        for(int j = 0;j < n;j++){
            if(!(i & (1ll << j))) continue;
            vec.push_back(a[j]);
        }
        init();
    }

    sort(all(result));
    cout << (result.size() > m ? result[m] : result.back());
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

