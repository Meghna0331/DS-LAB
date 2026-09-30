#include <iostream>
using namespace std;

int main()
{
    int tokens[5];
    int top = -1;

    cout << "Enter 5 completed customer tokens:\n";

    for (int i = 0; i < 5; i++)
    {
        top++;
        cin >> tokens[top];
    }

    cout << "\n===== COMPLETED SERVICE =====\n";

    while (top >= 0)
    {
        cout << "Completed Token: " << tokens[top] << endl;
        top--;
    }

    cout << "Service history displayed.";

    return 0;
}
