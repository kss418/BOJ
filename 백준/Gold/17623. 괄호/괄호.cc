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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string dp[MAX];
char c[6] = {'(', ')', '{', '}', '[', ']'};

string solve(ll cur){
    string& ret = dp[cur];
    if(!ret.empty()) return ret;
    ret.resize(2010, '6');

    for(int i = 1;i < cur;i++){
        ll sz = solve(i).size() + solve(cur - i).size();
        if(sz > ret.size()) continue;
        string now = solve(i) + solve(cur - i);
        if(sz < ret.size() || now < ret) ret = now;
    }

    if(cur % 2 == 0){
        ll sz = solve(cur / 2).size() + 2;
        if(sz <= ret.size()){
            string now = "1" + solve(cur / 2) + "2";
            if(sz < ret.size() || now < ret) ret = now;
        }
    }

    if(cur % 3 == 0){
        ll sz = solve(cur / 3).size() + 2;
        if(sz <= ret.size()){
            string now = "3" + solve(cur / 3) + "4";
            if(sz < ret.size() || now < ret) ret = now;
        }
    }

    if(cur % 5 == 0){
        ll sz = solve(cur / 5).size() + 2;
        if(sz <= ret.size()){
            string now = "5" + solve(cur / 5) + "6";
            if(sz < ret.size() || now < ret) ret = now;
        }
    }
    
    return ret;
}

void tf(string s){
    for(auto& i : s) cout << c[i - '1'];
    cout << "\n";
}

void run(){
    cin >> n;
    tf(solve(n));
}

int main() {
    fastio; cin >> t;
    dp[1] = "12"; dp[2] = "34"; dp[3] = "56";
    while(t--) run(); 

    return 0;
}

