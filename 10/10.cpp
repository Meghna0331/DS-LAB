#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct Folder
{
    string name;
    vector<Folder*> children;
    Folder* parent;

    Folder(string n)
    {
        name = n;
        parent = NULL;
    }
};

struct File
{
    string name;
    File* left;
    File* right;

    File(string n)
    {
        name = n;
        left = right = NULL;
    }
};

Folder* root = new Folder("root");
File* fileRoot = NULL;

Folder* searchFolder(Folder* f, string name)
{
    if (f == NULL)
        return NULL;

    if (f->name == name)
        return f;

    for (Folder* child : f->children)
    {
        Folder* result = searchFolder(child, name);

        if (result != NULL)
            return result;
    }

    return NULL;
}

void createFolder()
{
    string parentName, folderName;

    cout << "Enter Parent Folder: ";
    cin >> parentName;

    Folder* parent = searchFolder(root, parentName);

    if (parent == NULL)
    {
        cout << "Parent folder not found!\n";
        return;
    }

    cout << "Enter New Folder Name: ";
    cin >> folderName;

    Folder* newFolder = new Folder(folderName);
    newFolder->parent = parent;

    parent->children.push_back(newFolder);

    cout << "Folder created successfully!\n";
}

bool deleteFolder(Folder* parent, string name)
{
    for (int i = 0; i < parent->children.size(); i++)
    {
        if (parent->children[i]->name == name)
        {
            delete parent->children[i];
            parent->children.erase(parent->children.begin() + i);

            cout << "Folder deleted successfully!\n";
            return true;
        }

        if (deleteFolder(parent->children[i], name))
            return true;
    }

    return false;
}

File* insertFile(File* root, string name)
{
    if (root == NULL)
        return new File(name);

    if (name < root->name)
        root->left = insertFile(root->left, name);

    else if (name > root->name)
        root->right = insertFile(root->right, name);

    return root;
}

void addFile()
{
    string folderName, fileName;

    cout << "Enter Folder Name: ";
    cin >> folderName;

    Folder* folder = searchFolder(root, folderName);

    if (folder == NULL)
    {
        cout << "Folder not found!\n";
        return;
    }

    cout << "Enter File Name: ";
    cin >> fileName;

    folder->children.size(); // Folder lookup completed

    fileRoot = insertFile(fileRoot, fileName);

    cout << "File added successfully!\n";
}

bool searchFile(File* root, string name)
{
    if (root == NULL)
        return false;

    if (root->name == name)
        return true;

    if (name < root->name)
        return searchFile(root->left, name);

    return searchFile(root->right, name);
}

void displayFiles(File* root)
{
    if (root == NULL)
        return;

    displayFiles(root->left);

    cout << root->name << " ";

    displayFiles(root->right);
}

void preorder(Folder* root)
{
    if (root == NULL)
        return;

    cout << root->name << " ";

    for (Folder* child : root->children)
        preorder(child);
}

void inorder(Folder* root)
{
    if (root == NULL)
        return;

    if (!root->children.empty())
        inorder(root->children[0]);

    cout << root->name << " ";

    for (int i = 1; i < root->children.size(); i++)
        inorder(root->children[i]);
}

void postorder(Folder* root)
{
    if (root == NULL)
        return;

    for (Folder* child : root->children)
        postorder(child);

    cout << root->name << " ";
}

void levelOrder()
{
    queue<Folder*> q;

    q.push(root);

    while (!q.empty())
    {
        Folder* temp = q.front();
        q.pop();

        cout << temp->name << " ";

        for (Folder* child : temp->children)
            q.push(child);
    }
}

priority_queue<pair<int, string>> taskHeap;

void addTask()
{
    string task;
    int priority;

    cout << "Enter Task Name: ";
    cin >> task;

    cout << "Enter Priority: ";
    cin >> priority;

    taskHeap.push({priority, task});

    cout << "Task added successfully!\n";
}

void processTask()
{
    if (taskHeap.empty())
    {
        cout << "No tasks available!\n";
        return;
    }

    cout << "Processing Task: "
         << taskHeap.top().second << endl;

    taskHeap.pop();
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- FILE AND FOLDER MANAGEMENT ---\n";
        cout << "1. Create Folder\n";
        cout << "2. Delete Folder\n";
        cout << "3. Add File\n";
        cout << "4. Search File\n";
        cout << "5. Display Files\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Inorder Traversal\n";
        cout << "8. Postorder Traversal\n";
        cout << "9. Level Order Traversal\n";
        cout << "10. Add Task\n";
        cout << "11. Process Task\n";
        cout << "0. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        string name;

        switch (choice)
        {
            case 1:
                createFolder();
                break;

            case 2:
                cout << "Enter Folder Name: ";
                cin >> name;

                if (name == "root")
                    cout << "Root folder cannot be deleted!\n";
                else if (!deleteFolder(root, name))
                    cout << "Folder not found!\n";
                break;

            case 3:
                addFile();
                break;

            case 4:
                cout << "Enter File Name: ";
                cin >> name;

                if (searchFile(fileRoot, name))
                    cout << "File Found!\n";
                else
                    cout << "File Not Found!\n";
                break;

            case 5:
                cout << "Files: ";
                displayFiles(fileRoot);
                cout << endl;
                break;

            case 6:
                preorder(root);
                cout << endl;
                break;

            case 7:
                inorder(root);
                cout << endl;
                break;

            case 8:
                postorder(root);
                cout << endl;
                break;

            case 9:
                levelOrder();
                cout << endl;
                break;

            case 10:
                addTask();
                break;

            case 11:
                processTask();
                break;

            case 0:
                cout << "Exiting System!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}
