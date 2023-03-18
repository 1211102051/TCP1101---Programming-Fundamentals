#include <iostream>
#include <cstdlib> // for abs(), if you need it
using namespace std;

int main()
{
    int n, h;
    cout << "N -> ";
    cin >> n;
    cout << "H -> ";
    cin >> h;
    cout << endl;

    // Write your code here
    for (int i = 0; i < n; ++i) {
        for(int j = 1; j <= h; j++) {
            for(int k = 0; k < j; k++) {
                cout << j;
            }
            cout << endl;
        }
        for(int j = n - 1; j<=h; j++) {
            for (int k = 0; k < j; k++) {
                cout << j;
            }
            cout << endl;
        }
    }
}