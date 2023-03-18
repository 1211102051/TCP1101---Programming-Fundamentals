#include <iostream>
#include <vector>
using namespace std;

class Jug
{
    float capacity_; // the maximum amount that this jug can contain.
    float amount_;   // the amount this jug currently contains. 

public:
    Jug(int capacity, int amount);
    int getCapacity() const;
    int getAmount() const;
    void setAmount(int amount);
    void pourTo(Jug& jug);
    void show() const;
};

Jug::Jug(int capacity, int amount)
{
    capacity_ = capacity;
    amount_ = amount;
}

int Jug::getCapacity() const
{
    return capacity_;
}

int Jug::getAmount() const
{
    return amount_;
}

void Jug::setAmount(int amount)
{
    amount_ = amount;
}

void Jug::pourTo(Jug& jug)
{
    // --- Write your code here ---
}

void Jug::show() const
{
    cout << "Capacity = " << capacity_ << ", "
         << "Amount = "   << amount_ << endl;
}

void DisplayAllJugs(const vector<Jug>& jugs)
{
    for (int i = 0; i < jugs.size(); ++i)
    {
        cout << "- Jug[" << i << "] : ";
        jugs[i].show();
    }
}

int main()
{
    cout << "Enter number of jugs -> ";
    int m; cin >> m;

    vector<Jug> jugs;
    for (int i = 0; i < m; ++i)
    {
        cout << "Enter capacity and amount for Jug #" << i << " -> ";
        float capacity, amount;
        cin >> capacity >> amount;
        Jug jug(capacity, amount);
        jugs.push_back(jug);
    }

    cout << endl;
    cout << "Enter number of pouring -> ";
    int k; cin >> k;
    int from, to;
    for (int i = 0; i < k; ++i)
    {
        cout << "\nPouring #" << i << ":" << endl;
        // This loop is written for fun.
        // The test cases will not input similar values for 'from' and 'to'.
        do {
            cout << "From jug -> ";
            cin >> from;
            cout << "To   jug -> ";
            cin >> to;
        } while (from == to);

        cout << "Before pouring: " << endl;
        DisplayAllJugs(jugs);

        // pouring
        jugs[from].pourTo(jugs[to]);

        cout << "After pouring: " << endl;
        DisplayAllJugs(jugs);
    }
}