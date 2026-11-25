#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Customer
{
    int token;
    string name;
    string type;
};

queue<Customer> normalQueue;
queue<Customer> priorityQueue;
stack<Customer> servedHistory;

int tokenNumber = 1;

void issueToken()
{
    Customer c;

    c.token = tokenNumber++;

    cout << "Enter Customer Name: ";
    cin >> c.name;

    cout << "Enter Customer Type:\n";
    cout << "1. Normal\n";
    cout << "2. Senior Citizen\n";
    cout << "3. Differently-Abled\n";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c.type = "Normal";
        normalQueue.push(c);
    }
    else if (choice == 2)
    {
        c.type = "Senior Citizen";
        priorityQueue.push(c);
    }
    else if (choice == 3)
    {
        c.type = "Differently-Abled";
        priorityQueue.push(c);
    }
    else
    {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Token Issued Successfully!\n";
    cout << "Token Number: " << c.token << endl;
}

void serveCustomer()
{
    Customer c;

    if (!priorityQueue.empty())
    {
        c = priorityQueue.front();
        priorityQueue.pop();
    }
    else if (!normalQueue.empty())
    {
        c = normalQueue.front();
        normalQueue.pop();
    }
    else
    {
        cout << "No customers waiting!\n";
        return;
    }

    servedHistory.push(c);

    cout << "\nCustomer Served Successfully!\n";
    cout << "Token Number: " << c.token << endl;
    cout << "Name: " << c.name << endl;
    cout << "Type: " << c.type << endl;
}

void showHistory()
{
    if (servedHistory.empty())
    {
        cout << "No service history available!\n";
        return;
    }

    stack<Customer> temp = servedHistory;

    cout << "\nRecently Served Customers:\n";

    while (!temp.empty())
    {
        Customer c = temp.top();

        cout << "Token: " << c.token;
        cout << " Name: " << c.name << endl;

        temp.pop();
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- BANK TOKEN MANAGEMENT SYSTEM ---\n";
        cout << "1. Issue Token\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Service History\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: issueToken(); break;
            case 2: serveCustomer(); break;
            case 3: showHistory(); break;
            case 0: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
