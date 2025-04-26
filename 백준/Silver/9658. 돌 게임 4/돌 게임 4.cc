#include <bits/stdc++.h>
#define fastio 	cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
typedef unsigned long long ull;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 2010;


int main() {
	fastio;
    
    cin >> n;
    
    if(n % 7 == 1 || n % 7 == 3) cout << "CY";
    else cout << "SK";
    
    
	return 0;
}

