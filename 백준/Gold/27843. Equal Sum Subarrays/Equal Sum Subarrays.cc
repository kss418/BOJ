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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX];

class node{
public: 
    ll s, e, sum;
    bool operator < (const node& ot) const{
        return sum < ot.sum;
    }

    bool chk(ll idx){
        return s <= idx && e >= idx;
    }
}; vector <node> arr;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++) arr.push_back({i, j, sum[j] - sum[i - 1]});
    }
    sort(all(arr));

    for(int i = 1;i <= n;i++){
        ll result = INF;
        for(int j = 1;j < arr.size();j++){
            node l = arr[j - 1], r = arr[j];
            if(l.chk(i) ^ r.chk(i)) result = min(result, r.sum - l.sum);
        }

        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}