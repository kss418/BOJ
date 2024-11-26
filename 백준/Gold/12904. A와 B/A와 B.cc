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

bool chk(string& a, string& b){
    if(a == b) return 1;

    bool dir = 0;
    deque <char> q;
    for(auto& i : b) q.push_back(i);

    while(1){
        if(q.empty()) return 0;
        bool flag = 0;

        if(!dir){
            if(q.back() == 'B') dir ^= 1;
            else if(q.back() != 'A') return 0;
            q.pop_back();
        }
        else{
            if(q.front() == 'B') dir ^= 1;
            else if(q.front() != 'A') return 0;
            q.pop_front();
        }

        string now;
        for(auto& i : q) now.push_back(i);
        if(dir) reverse(all(now));
        if(now == a) return 1;
    }

    return 0;
}

int main() {
    fastio;

    string a, b; cin >> a >> b;
    cout << chk(a, b);

     
    return 0;
}