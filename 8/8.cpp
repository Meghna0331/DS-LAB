#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    int quantity;
    float price;
    Product* next;
};

Product* head = NULL;

const int SIZE = 10;
int hashTable[SIZE];

int hashFunction(int id)
{
    return id % SIZE;
}

void addProduct()
{
    Product* newProduct = new Product;

    cout << "Enter Product ID: ";
    cin >> newProduct->id;

    cout << "Enter Product Name: ";
    cin >> newProduct->name;

    cout << "Enter Quantity: ";
    cin >> newProduct->quantity;

    cout << "Enter Price: ";
    cin >> newProduct->price;

    int index = hashFunction(newProduct->id);

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = newProduct->id;

    newProduct->next = head;
    head = newProduct;

    cout << "Product added successfully!\n";
}

void searchProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == id)
        {
            Product* temp = head;

            while (temp != NULL)
            {
                if (temp->id == id)
                {
                    cout << "Product Found!\n";
                    cout << "ID: " << temp->id << endl;
                    cout << "Name: " << temp->name << endl;
                    cout << "Quantity: " << temp->quantity << endl;
                    cout << "Price: " << temp->price << endl;
                    return;
                }

                temp = temp->next;
            }
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Product not found!\n";
}

void updateProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    Product* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Name: ";
            cin >> temp->name;

            cout << "Enter New Quantity: ";
            cin >> temp->quantity;

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Product updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Product not found!\n";
}

void removeProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    Product* temp = head;
    Product* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Product not found!\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    int index = hashFunction(id);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == id)
        {
            hashTable[index] = -1;
            break;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    delete temp;

    cout << "Product removed successfully!\n";
}

void displayProducts()
{
    Product* temp = head;

    if (temp == NULL)
    {
        cout << "No products available!\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "\nProduct ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nQuantity: " << temp->quantity;
        cout << "\nPrice: " << temp->price << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    do
    {
        cout << "\n--- E-COMMERCE INVENTORY SYSTEM ---\n";
        cout << "1. Add Product\n";
        cout << "2. Search Product\n";
        cout << "3. Update Product\n";
        cout << "4. Remove Product\n";
        cout << "5. Display Products\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: updateProduct(); break;
            case 4: removeProduct(); break;
            case 5: displayProducts(); break;
            case 0: cout << "Exiting system!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
