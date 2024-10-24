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

class _dlog{
public:
    map<ll, ll> num; vector <ll> prime;
    _dlog(){};

    void factor(ll p){ // 소인수분해
        prime.clear();  
        for(ll i = 2;i * i <= p;i++){
            if(p % i) continue;
            prime.push_back(i);
            if(i * i != p) prime.push_back(p / i);
        }
    }

    ll phi(ll p){ 
        factor(p); ll ret = p;
        for(auto& i : prime) ret /= i, ret *= i - 1;
        return ret;
    }

    ll sqrt(ll num){
        ll lo = 0, hi = num;
        while(hi > lo){
            ll mid = (lo + hi + 1) >> 1;
            if(mid * mid < num) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    ll pow(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
    
    ll ret(ll a, ll b, ll p) { // a^x = b (mod p), ret x
        ll mx = sqrt(phi(p)) + 1; num.clear();
        ll inv = pow(a, p - 2, p), cur = b;
        for(int i = 0;i < mx;i++) {
            if(num.find(cur) == num.end()) num[cur] = i;
            cur *= inv; cur %= p;
        }
        cur = 1; for(int i = 0;i < mx;i++){
            if(num.find(cur) != num.end()) return i * mx + num[cur];
            cur *= pow(a, mx, p); cur %= p;
        }
        return -1;
    }
};


int main() {
    fastio; 

    ll p, a, b; _dlog dlog;

    while(cin >> p >> a >> b){
        ll ret = dlog.ret(a, b, p);
        if(ret == -1) cout << "no solution\n";
        else cout << ret << "\n";
    }
    
    
    return 0;
}