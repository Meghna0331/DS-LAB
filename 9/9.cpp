#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Course
{
    string courseName;
    Course* next;
};

struct Student
{
    int roll;
    string name;
    int age;
    Course* courses;
    Student* next;
};

Student* hashTable[SIZE];

int hashFunction(int roll)
{
    return roll % SIZE;
}

void registerStudent()
{
    Student* newStudent = new Student;

    cout << "Enter Roll Number: ";
    cin >> newStudent->roll;

    int index = hashFunction(newStudent->roll);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->roll == newStudent->roll)
        {
            cout << "Roll Number already exists!\n";
            delete newStudent;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Student Name: ";
    cin >> newStudent->name;

    cout << "Enter Age: ";
    cin >> newStudent->age;

    newStudent->courses = NULL;
    newStudent->next = hashTable[index];

    hashTable[index] = newStudent;

    cout << "Student registered successfully!\n";
}

void searchStudent()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = hashFunction(roll);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->roll << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;

            cout << "Enrolled Courses:\n";

            Course* c = temp->courses;

            if (c == NULL)
                cout << "No courses enrolled!\n";

            while (c != NULL)
            {
                cout << c->courseName << endl;
                c = c->next;
            }

            return;
        }

        temp = temp->next;
    }

    cout << "Student not found!\n";
}

void updateStudent()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = hashFunction(roll);

    Student* temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            cout << "Enter New Name: ";
            cin >> temp->name;

            cout << "Enter New Age: ";
            cin >> temp->age;

            cout << "Student information updated!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Student not found!\n";
}

void enrollCourse()
{
    int roll;
    string courseName;

    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = hashFunction(roll);

    Student* temp = hashTable[index];

    while (temp != NULL && temp->roll != roll)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter Course Name: ";
    cin >> courseName;

    Course* c = temp->courses;

    while (c != NULL)
    {
        if (c->courseName == courseName)
        {
            cout << "Already enrolled in this course!\n";
            return;
        }

        c = c->next;
    }

    Course* newCourse = new Course;

    newCourse->courseName = courseName;
    newCourse->next = temp->courses;
    temp->courses = newCourse;

    cout << "Course enrolled successfully!\n";
}

void withdrawCourse()
{
    int roll;
    string courseName;

    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = hashFunction(roll);

    Student* temp = hashTable[index];

    while (temp != NULL && temp->roll != roll)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter Course Name to Withdraw: ";
    cin >> courseName;

    Course* c = temp->courses;
    Course* prev = NULL;

    while (c != NULL && c->courseName != courseName)
    {
        prev = c;
        c = c->next;
    }

    if (c == NULL)
    {
        cout << "Course not found!\n";
        return;
    }

    if (prev == NULL)
        temp->courses = c->next;
    else
        prev->next = c->next;

    delete c;

    cout << "Course withdrawn successfully!\n";
}

void removeStudent()
{
    int roll;

    cout << "Enter Roll Number: ";
    cin >> roll;

    int index = hashFunction(roll);

    Student* temp = hashTable[index];
    Student* prev = NULL;

    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    Course* c = temp->courses;

    while (c != NULL)
    {
        Course* del = c;
        c = c->next;
        delete del;
    }

    delete temp;

    cout << "Student record removed successfully!\n";
}

void displayStudents()
{
    bool found = false;

    for (int i = 0; i < SIZE; i++)
    {
        Student* temp = hashTable[i];

        while (temp != NULL)
        {
            found = true;

            cout << "\nRoll Number: " << temp->roll;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;

            cout << "\nCourses: ";

            Course* c = temp->courses;

            if (c == NULL)
                cout << "None";

            while (c != NULL)
            {
                cout << c->courseName << " ";
                c = c->next;
            }

            cout << endl;

            temp = temp->next;
        }
    }

    if (!found)
        cout << "No student records available!\n";
}

int main()
{
    int choice;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    do
    {
        cout << "\n--- UNIVERSITY STUDENT MANAGEMENT ---\n";
        cout << "1. Register Student\n";
        cout << "2. Search Student\n";
        cout << "3. Update Student\n";
        cout << "4. Enroll in Course\n";
        cout << "5. Withdraw from Course\n";
        cout << "6. Remove Student\n";
        cout << "7. Display All Students\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: registerStudent(); break;
            case 2: searchStudent(); break;
            case 3: updateStudent(); break;
            case 4: enrollCourse(); break;
            case 5: withdrawCourse(); break;
            case 6: removeStudent(); break;
            case 7: displayStudents(); break;
            case 0: cout << "Exiting System!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
