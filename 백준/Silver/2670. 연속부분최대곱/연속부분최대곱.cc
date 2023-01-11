#include <iostream> 
#include <algorithm>
#include <vector> 
#include <cstring>
#include <deque> 
#include <set>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 10101;
double arr[MAX];

int main() {
    cin >> n;
    double cur = 1;
    double result = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cur *= arr[i];
        cur = max(cur, arr[i]);
        result = max(result, cur);
    }

    printf("%0.3lf", result);
  

    return 0;
}