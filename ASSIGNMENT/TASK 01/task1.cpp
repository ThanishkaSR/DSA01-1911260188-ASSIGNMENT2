#include <iostream>
using namespace std;

// Call by value
void applyByValue(long long fee, int percent)
{
    fee = fee - fee * percent / 100;
}

// Call by reference
void applyByReference(long long& fee, int percent)
{
    fee = fee - fee * percent / 100;
}

// Call by pointer
void applyByPointer(long long* fee, int percent)
{
    if (fee != nullptr)
        *fee = *fee - (*fee * percent / 100);
}

int main()
{
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    applyByValue(fee1, 10);
    applyByReference(fee2, 15);
    applyByPointer(&fee3, 25);

    cout << "After call by value: " << fee1 << '\n';
    cout << "After call by reference: " << fee2 << '\n';
    cout << "After call by pointer: " << fee3 << '\n';

    return 0;
}

GIVEN PROGRAM
#include <iostream>

void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10)
{
    std::cout << x + y + z << ' ';
}

int main()
{
    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    std::cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    std::cout << '\n';
}

COMPLETED TODO:

#include <iostream>

void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
}

void applyConcession(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

int main()
{
    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);

    std::cout << "after call by value   : "
              << hostelFee << '\n';

    applyConcession(hostelFee, 10);

    std::cout << "after call by reference: "
              << hostelFee << '\n';
}
