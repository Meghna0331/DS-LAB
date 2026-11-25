#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<string> normalOrders;
priority_queue<string> vipOrders;
stack<string> cancelledOrders;

// Add order
void addOrder()
{
    string order;
    int type;

    cout << "Enter order name: ";
    cin >> order;

    cout << "1. Normal Order\n2. VIP Order\n";
    cin >> type;

    if (type == 1)
        normalOrders.push(order);
    else if (type == 2)
        vipOrders.push(order);

    cout << "Order added successfully!\n";
}

// Process order
void processOrder()
{
    if (!vipOrders.empty())
    {
        cout << "Processing VIP Order: "
             << vipOrders.top() << endl;
        vipOrders.pop();
    }
    else if (!normalOrders.empty())
    {
        cout << "Processing Normal Order: "
             << normalOrders.front() << endl;
        normalOrders.pop();
    }
    else
    {
        cout << "No orders available!\n";
    }
}

// Cancel order
void cancelOrder()
{
    string order;

    cout << "Enter cancelled order name: ";
    cin >> order;

    cancelledOrders.push(order);

    cout << "Order cancelled successfully!\n";
}

// Show recently cancelled order
void showCancelled()
{
    if (!cancelledOrders.empty())
        cout << "Recently Cancelled: "
             << cancelledOrders.top() << endl;
    else
        cout << "No cancelled orders!\n";
}

// Recursive menu navigation
void menuNavigation(int choice)
{
    if (choice == 0)
    {
        cout << "Exiting menu navigation.\n";
        return;
    }

    cout << "\n1. Starters\n";
    cout << "2. Main Course\n";
    cout << "3. Desserts\n";
    cout << "0. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
        cout << "You selected Starters\n";
    else if (choice == 2)
        cout << "You selected Main Course\n";
    else if (choice == 3)
        cout << "You selected Desserts\n";

    menuNavigation(choice);
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- SMART RESTAURANT SYSTEM ---\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Cancel Order\n";
        cout << "4. Show Cancelled Order\n";
        cout << "5. Menu Navigation\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addOrder(); break;
            case 2: processOrder(); break;
            case 3: cancelOrder(); break;
            case 4: showCancelled(); break;
            case 5: menuNavigation(-1); break;
            case 0: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
