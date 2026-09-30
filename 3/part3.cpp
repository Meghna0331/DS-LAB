#include <iostream>
using namespace std;

void restaurantMenu()
{
    int option;

    cout << "\n\n===== FOOD MENU =====";
    cout << "\n1. Pizza";
    cout << "\n2. Burger";
    cout << "\n3. Pasta";
    cout << "\n4. Exit";
    cout << "\nChoose an option: ";
    cin >> option;

    if (option == 1)
    {
        cout << "Pizza added to your order.";
        restaurantMenu();
    }
    else if (option == 2)
    {
        cout << "Burger added to your order.";
        restaurantMenu();
    }
    else if (option == 3)
    {
        cout << "Pasta added to your order.";
        restaurantMenu();
    }
    else if (option == 4)
    {
        cout << "\nThank you for visiting!";
    }
    else
    {
        cout << "\nPlease enter a valid option.";
        restaurantMenu();
    }
}

int main()
{
    restaurantMenu();
    return 0;
}
