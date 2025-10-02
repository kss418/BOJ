#include <bits/stdc++.h>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
deque <char> a, b, c;
string oa, ob;
vector <pll> result;

void comp(string& os, deque <char>& s){
    deque <char> tmp; char la = -1;
    for(auto& i : os){
        if(la != i) tmp.push_back(i);
        la = i;
    }

    s = tmp;
}

void opa(){
    while(a.size() > 1){
        if(a.back() == b.back()){
            a.pop_back();
            result.push_back({1, 2});
        }
        else{
            if(c.empty()) c.push_back(a.back());
            a.pop_back();
            result.push_back({1, 3});
        }
    }
}

void opb(){
    while(b.size() > 1){
        if(a.back() == b.back()){
            b.pop_back();
            result.push_back({2, 1});
        }
        else{
            if(c.empty()) c.push_back(b.back());
            b.pop_back();
            result.push_back({2, 3});
        }
    }
}

void op(){
    result.clear(); comp(oa, a); comp(ob, b); 
    if(a[0] == b[0]) b.push_front(a[0] ^ 3);

    if(a.back() == b.back()){
        if(a.size() > 1){
            a.pop_back();
            result.push_back({1, 2});
        }
        else if(b.size() > 1){
            b.pop_back();
            result.push_back({2, 1});
        }
    }

    if(a.size() > 1){
        if(c.empty()) c.push_back(a.back());
        a.pop_back();
        result.push_back({1, 3});
    }
    else if(b.size() > 1){
        if(c.empty()) c.push_back(b.back());
        b.pop_back();
        result.push_back({2, 3});
    }

    if(c.empty()) return;
    if(a[0] != c.back()) opa(), opb();
    else opb(), opa();

    if(!c.empty()){
        if(a.back() == c.back()) result.push_back({3, 1});
        else result.push_back({3, 2});
        c.pop_back();
    }
}

void run(){
    cin >> n >> m >> oa >> ob; op(); 

    cout << result.size() << "\n";
    if(m != 1) for(auto& [l, r] : result){
        cout << l << " " << r << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}