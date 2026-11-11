#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

    // Defined inside the class
    void addTransaction(double amount)
    {
        if (count < 10)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            for (int i = 0; i < 9; i++)
                transactions[i] = transactions[i + 1];

            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
    }

    // Function declarations
    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement();
};

// Defined outside the class
void SavingsAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        addTransaction(amount);
        cout << "Deposit successful\n";
    }
    else
        cout << "Invalid deposit\n";
}

void SavingsAccount::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        addTransaction(-amount);
        cout << "Withdrawal successful\n";
    }
    else
        cout << "Invalid withdrawal\n";
}

void SavingsAccount::miniStatement()
{
    cout << "\nAccount Number: " << accountNumber << '\n';
    cout << "Current Balance: Rs " << balance << '\n';
    cout << "Last Transactions:\n";

    for (int i = 0; i < count; i++)
        cout << transactions[i] << '\n';
}

int main()
{
    SavingsAccount account(101, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}

*/ALTERNATIVE CONCEPT/*
    #include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<double> transactions;

    transactions.push_back(1000);
    transactions.push_back(-500);
    transactions.push_back(2000);

    while (transactions.size() > 10)
        transactions.pop_front();

    for (int i = 0; i < transactions.size(); i++)
        cout << transactions[i] << '\n';

    return 0;
}
    
