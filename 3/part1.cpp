#include <iostream>
using namespace std;

int main()
{
    int orders[5];
    int front = 0, rear = 0;

    cout << "Enter 5 customer order IDs:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> orders[rear];
        rear++;
    }

    cout << "\n--- Customer Order Processing ---\n";

    while (front != rear)
    {
        cout << "Order ID " << orders[front] << " is being processed." << endl;
        front++;
    }

    cout << "All orders have been processed successfully.";

    return 0;
}
