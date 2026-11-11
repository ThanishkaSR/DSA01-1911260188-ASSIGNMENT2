*/Completed TODO 1 and TODO 2/*

#include <iostream>
using namespace std;

class Time
{
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);

    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b)
{
    // TODO 1
    int time1 = a.h * 60 + a.m;
    int time2 = b.h * 60 + b.m;

    int difference = time1 - time2;

    if (difference < 0)
        difference = -difference;

    return difference;
}

bool earlier(const Time& a, const Time& b)
{
    // TODO 2
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int main()
{
    Time departure(9, 45), arrival(13, 10);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    return 0;
}

#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int addNormal(int a, int b)
{
    return a + b;
}

inline int addInline(int a, int b)
{
    return a + b;
}

*/Growth Investigation – Measuring 10,000,000 Calls/*
int main()
{
    const int n = 10000000;
    volatile int result = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        result = addNormal(i, 2);

    auto end = high_resolution_clock::now();

    cout << "Normal function time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        result = addInline(i, 2);

    end = high_resolution_clock::now();

    cout << "Inline function time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    cout << "Result: " << result << '\n';

    return 0;
}
*/Alternative Concept – Member Functions and Getters/*

#include <iostream>
using namespace std;

class Time
{
private:
    int h, m;

public:
    Time(int hh, int mm)
    {
        h = hh;
        m = mm;
    }

    int minutesTo(const Time& b)
    {
        int t1 = h * 60 + m;
        int t2 = b.h * 60 + b.m;

        int diff = t1 - t2;

        if (diff < 0)
            diff = -diff;

        return diff;
    }

    bool isEarlier(const Time& b)
    {
        if (h < b.h)
            return true;

        if (h == b.h && m < b.m)
            return true;

        return false;
    }
};

int main()
{
    Time departure(9, 45), arrival(13, 10);

    cout << departure.minutesTo(arrival) << ' '
         << boolalpha << departure.isEarlier(arrival);

    return 0;
}
