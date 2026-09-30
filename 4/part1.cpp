#include <iostream>
using namespace std;

int main()
{
    int tokens[5];
    int front = 0;
    int rear = 0;

    cout << "Enter 5 customer token numbers:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> tokens[rear];
        rear++;
    }

    cout << "\n===== TOKEN SERVICE =====\n";

    while (front != rear)
    {
        cout << "Now Serving Token: " << tokens[front] << endl;
        front++;
    }

    cout << "All customers have been served.";

    return 0;
}
