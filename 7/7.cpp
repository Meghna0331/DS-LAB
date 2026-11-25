#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

Patient* hashTable[SIZE];

int hashFunction(int id)
{
    return id % SIZE;
}

void registerPatient()
{
    Patient* newPatient = new Patient;

    cout << "Enter Patient ID: ";
    cin >> newPatient->id;

    int index = hashFunction(newPatient->id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == newPatient->id)
        {
            cout << "Patient ID already exists!\n";
            delete newPatient;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Name: ";
    cin >> newPatient->name;

    cout << "Enter Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin >> newPatient->disease;

    newPatient->next = hashTable[index];
    hashTable[index] = newPatient;

    cout << "Patient registered successfully!\n";
}

void searchPatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found!\n";
}

void updatePatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Name: ";
            cin >> temp->name;

            cout << "Enter New Age: ";
            cin >> temp->age;

            cout << "Enter New Disease: ";
            cin >> temp->disease;

            cout << "Patient record updated!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found!\n";
}

void dischargePatient()
{
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];
    Patient* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Patient not found!\n";
        return;
    }

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    delete temp;

    cout << "Patient discharged successfully!\n";
}

void displayPatients()
{
    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        Patient* temp = hashTable[i];

        while (temp != NULL)
        {
            found = true;

            cout << "\nPatient ID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nDisease: " << temp->disease << endl;

            temp = temp->next;
        }
    }

    if (!found)
        cout << "No patient records available!\n";
}

int main()
{
    int choice;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    do
    {
        cout << "\n--- HOSPITAL PATIENT MANAGEMENT ---\n";
        cout << "1. Register Patient\n";
        cout << "2. Search Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Discharge Patient\n";
        cout << "5. Display All Patients\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: registerPatient(); break;
            case 2: searchPatient(); break;
            case 3: updatePatient(); break;
            case 4: dischargePatient(); break;
            case 5: displayPatients(); break;
            case 0: cout << "Exiting system!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
