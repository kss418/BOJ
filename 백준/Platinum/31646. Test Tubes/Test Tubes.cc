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
string a, b, c, oa, ob;
vector <pll> result;

void comp(string& os, string& s){
    string tmp; char la = -1;
    for(auto& i : os){
        if(la != i) tmp.push_back(i);
        la = i;
    }

    s = tmp;
}

void op(){
    result.clear(); comp(oa, a); comp(ob, b);
    while(a.size() != 1 || b.size() != 1 || !c.empty()){
        if(a.size() == 1 && b.size() == 1){
            if(a.back() == b.back()){
                result.push_back({2, 1});
                result.push_back({3, 2});
                b.pop_back(); b.push_back(c.back());
            }
            else if(a.back() == c.back()) result.push_back({3, 1});
            else result.push_back({3, 2});
            c.pop_back();
        }
        else if(a.size() == 1){
            if(!b.empty() && a.back() == b.back()){
                b.pop_back();
                result.push_back({2, 1});
            }
            else if(!c.empty() && a.back() == c.back()){
                c.pop_back();
                result.push_back({3, 1});
            }
            else{
                if(c.empty()) c.push_back(b.back());
                b.pop_back();
                result.push_back({2, 3});
            }
        }
        else if(b.size() == 1){
            if(!a.empty() && b.back() == a.back()){
                a.pop_back();
                result.push_back({1, 2});
            }
            else if(!c.empty() && b.back() == c.back()){
                c.pop_back();
                result.push_back({3, 2});
            }
            else{
                if(c.empty()) c.push_back(a.back());
                a.pop_back();
                result.push_back({1, 3});
            }
        }
        else{
            if(!a.empty() && !b.empty() && a.back() == b.back()){
                if(a.size() < b.size()){
                    a.pop_back();
                    result.push_back({1, 2});
                }
                else{
                    b.pop_back();
                    result.push_back({2, 1});
                }
            }
            else if(!a.empty() && !b.empty() && a.back() != b.back()){
                if(a.size() < b.size()){
                    result.push_back({1, 3});
                    if(c.empty()) c.push_back(a.back());
                    a.pop_back();
                }
                else{
                    result.push_back({2, 3});
                    if(c.empty()) c.push_back(b.back());
                    b.pop_back();
                }
            }
        }
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