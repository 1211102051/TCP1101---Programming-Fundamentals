#include <iostream>
using namespace std;

void PrintSubstring(char* p1, char* p2)
{
    // --- Write your code here ---
}

int main()
{
    int N;
    cout << "N -> ";
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cout << "\nInput:" << endl;
        char name[20];
        cin >> name;

        int P, Q;
        cin >> P >> Q;

        cout << "Output:" << endl;
        PrintSubstring(name + P, name + Q);
    }
}