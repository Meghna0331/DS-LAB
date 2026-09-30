#include <iostream>
using namespace std;

int main()
{
    int tokens[10];
    int front = 0, rear = 0;
    int option;

    do
    {
        cout << "\n\n===== BANK TOKEN COUNTER =====";
        cout << "\n1. Generate Token";
        cout << "\n2. Show Waiting Tokens";
        cout << "\n3. Call Customer";
        cout << "\n4. Exit";
        cout << "\nSelect an option: ";
        cin >> option;

        if (option == 1)
        {
            cout << "\nEnter Token Number: ";
            cin >> tokens[rear];
            rear++;
            cout << "Token generated successfully!";
        }
        else if (option == 2)
        {
            cout << "\n===== CUSTOMERS IN QUEUE =====\n";

            if (front < rear)
            {
                for (int i = front; i < rear; i++)
                {
                    cout << "Waiting Token: " << tokens[i] << endl;
                }
            }
            else
            {
                cout << "No customers waiting!";
            }
        }
        else if (option == 3)
        {
            if (front < rear)
            {
                cout << "\nCalling Token: " << tokens[front];
                front++;
            }
            else
            {
                cout << "\nQueue is empty!";
            }
        }
        else if (option == 4)
        {
            cout << "\nThank you for using the bank system!";
        }
        else
        {
            cout << "\nInvalid option!";
        }

    } while (option != 4);

    return 0;
}
