#include <iostream>
using namespace std;

class SavingsAccount {
private:
    double transactions[10];
    int count;
    int nextIndex;

public:
    SavingsAccount() {
        count = 0;
        nextIndex = 0;
    }

    void addTransaction(double amount) {
        transactions[nextIndex] = amount;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10) {
            count++;
        }
    }

    void miniStatement() {
        cout << "Last Transactions:" << endl;

        int start = (nextIndex - count + 10) % 10;

        for (int i = 0; i < count; i++) {
            cout << transactions[(start + i) % 10] << endl;
        }
    }
};

int main() {
    SavingsAccount account;

    account.addTransaction(100);
    account.addTransaction(-50);
    account.addTransaction(200);
    account.addTransaction(-30);
    account.addTransaction(150);
    account.addTransaction(-40);
    account.addTransaction(300);
    account.addTransaction(-60);
    account.addTransaction(250);
    account.addTransaction(-70);
    account.addTransaction(400);
    account.addTransaction(-80);

    account.miniStatement();

    return 0;
}
