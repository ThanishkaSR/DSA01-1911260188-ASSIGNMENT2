#include <iostream>
using namespace std;

// Returns a reference to the highest mark
int& highestMark(int marks[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    }

    return marks[maxIndex];
}

// Returns a reference to a local variable (unsafe)
int& wrongFunction()
{
    int x = 50;
    return x;
}

int main()
{
    int marks[5] = {75, 82, 90, 68, 85};

    cout << "Highest mark: " << highestMark(marks, 5) << '\n';

    highestMark(marks, 5) += 2;

    cout << "After moderation: " << highestMark(marks, 5) << '\n';

    cout << "\nUpdated marks: ";
    for (int i = 0; i < 5; i++)
        cout << marks[i] << " ";

    cout << '\n';

    return 0;
}


