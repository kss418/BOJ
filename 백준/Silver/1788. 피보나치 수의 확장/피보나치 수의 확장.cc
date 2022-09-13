#include <iostream>
using namespace std;
int n;
long long fibo[1000001];
bool si;

int main(){
    cin >> n;
    fibo[0] = 0;

    if (n == 0) {
        cout << 0 << "\n" << 0;
        return 0;
    }

    if (n > 0) {
        fibo[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            fibo[i] = (fibo[i - 1] % 1000000000 + fibo[i - 2] % 1000000000) % 1000000000;
        }
    }
    else {
        fibo[1] = 1;
        n *= -1;
        for (int i = 2; i < n + 1; i++) {
            fibo[i] = (fibo[i - 2] % 1000000000 - fibo[i - 1] % 1000000000) % 1000000000;
        }
    }

    if (fibo[n] > 0) {
        cout << 1;
    }
    else {
        cout << -1;
    }

    cout << "\n" << abs(fibo[n])%1000000000;
    return 0;
}
