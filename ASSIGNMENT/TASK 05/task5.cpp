#include <iostream>

class Token
{
    static int next;
    int id;

public:
    Token()
    {
        id = ++next;
    }

    int get() const
    {
        return id;
    }

    static int issued()
    {
        return next - 100;
    }
};

int Token::next = 100;

int main()
{
    Token counter[3];

    Token extra;

    std::cout << counter[0].get() << ' '
              << counter[2].get() << ' '
              << extra.get() << ' '
              << Token::issued() << '\n';
}

#include <iostream>
#include <string>

class BusTicket
{
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    std::string name;

public:
    explicit BusTicket(const std::string& n) : seat(0), name(n)
    {
        // TODO 1
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    static int count()
    {
        // TODO 2
        return issued;
    }

    void print() const
    {
        std::cout << name << ": "
                  << (seat ? "Seat " + std::to_string(seat)
                           : std::string("Waiting"))
                  << '\n';
    }
};

int BusTicket::issued = 0;

int main()
{
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& t : trip)
        t.print();

    std::cout << "Issued: " << BusTicket::count() << '\n';
}

*/Creating Tickets Inside a Function Called Twice/*

#include <iostream>
using namespace std;

class BusTicket
{
    static int issued;
    static const int CAPACITY = 3;

    int seat;

public:
    BusTicket()
    {
        seat = 0;

        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    void print()
    {
        if (seat == 0)
            cout << "Waiting\n";
        else
            cout << "Seat " << seat << '\n';
    }

    static int count()
    {
        return issued;
    }
};

int BusTicket::issued = 0;

void createTickets()
{
    BusTicket t[2];

    for (int i = 0; i < 2; i++)
        t[i].print();

    cout << "Issued: " << BusTicket::count() << '\n';
}

int main()
{
    cout << "First call:\n";
    createTickets();

    cout << "Second call:\n";
    createTickets();

    return 0;
}
