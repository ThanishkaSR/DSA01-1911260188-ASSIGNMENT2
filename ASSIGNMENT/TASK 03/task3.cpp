#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
};

// Weight in grams
double charge(int grams, bool express = false, bool insured = false)
{
    double amount = grams * 0.04;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    cout << "Integer overload selected. ";
    return amount;
}

// Weight in kilograms
double charge(double kg, bool express = false, bool insured = false)
{
    double amount = kg * 40;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    cout << "Double overload selected. ";
    return amount;
}

// Parcel object
double charge(Parcel p, bool express = false, bool insured = false)
{
    double amount = p.weight * 40;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    cout << "Parcel overload selected. ";
    return amount;
}

int main()
{
    Parcel p = {3.0};

    cout << "Charge 1: Rs " << charge(2) << '\n';
    cout << "Charge 2: Rs " << charge(2.0f) << '\n';
    cout << "Charge 3: Rs " << charge(500) << '\n';
    cout << "Charge 4: Rs " << charge(1.5) << '\n';
    cout << "Charge 5: Rs " << charge(2, true) << '\n';
    cout << "Charge 6: Rs " << charge(p) << '\n';

    return 0;
}


