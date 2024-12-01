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
ll a[MAX];

class _mnc { // 0-based index
public:
    vector <ll> dp, v; ll n, sum = 0, m = 0;

    _mnc(){}
    _mnc(string& s) : _mnc(move(tf(s))){};
    _mnc(const vector <ll>& v){ init(v); }
    
    void init(const vector <ll>& arr){
        for(auto& i : arr){
            v.push_back(INF);
            v.push_back(i);
        }
        v.push_back(INF); this->n = v.size();
        dp.resize(n + 1, 0); cal();
    }

    void cal(){
        ll r = -1, c = -1;
        for(int i = 0;i < n;i++){
            if(i <= r) dp[i] = min(r - i, dp[2 * c - i]);
            while(i + dp[i] + 1 < n && i - dp[i] - 1 >= 0){
                if(v[i + dp[i] + 1] == v[i - dp[i] - 1]) dp[i]++;
                else break;
            }
            if(i + dp[i] > r) c = i, r = i + dp[i];
            sum += dp[i] / 2 + 1;
            m = max(m, dp[i]);
        }
    }

    ll cnt(){ return sum; } // 팰린드롬 개수
    ll mx(){ return m; } // 가장 긴 팰린드롬 길이

    vector <ll> tf(string& s){
        vector <ll> ret;
        for(auto& i : s) ret.push_back(i);
        return ret;
    }
};

int main() {
    fastio;

    cin >> n; vector <ll> arr;
    for(int i = 1;i <= n;i++) cin >> m, arr.push_back(m);
    _mnc mnc(arr);

    cin >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        s = 2 * (s - 1) + 1; e = 2 * (e - 1) + 1;
        ll mid = (s + e) / 2, diff = mid - s;
        cout << (mnc.dp[mid] >= diff) << "\n";
    }
  
     
    return 0;
}