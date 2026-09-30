#include <iostream>
using namespace std;

int main()
{
    int cancelled[5];
    int top = -1;

    cout << "Enter 5 cancelled order IDs:\n";

    for (int i = 0; i < 5; i++)
    {
        top++;
        cin >> cancelled[top];
    }

    cout << "\nCancelled Orders (Latest First):\n";

    while (top >= 0)
    {
        cout << "Order ID: " << cancelled[top] << endl;
        top--;
    }

    return 0;
}
