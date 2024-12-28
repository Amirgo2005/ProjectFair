#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string surname;
    string phone;
};

void showContacts(Contact contacts[], int count) {
    cout << "\nContact list:\n";
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". " << contacts[i].name << " " << contacts[i].surname << ": " << contacts[i].phone << "\n";
    }
    if (count == 0) {
        cout << "The list is empty.\n";
    }
}

void addContact(Contact contacts[], int& count, int maxContacts) {
    if (count >= maxContacts) {
        cout << "The phone book is full!\n";
        return;
    }

    cout << "Enter a name: ";
    cin.ignore();
    getline(cin, contacts[count].name);
    cout << "Enter surname: ";
    getline(cin, contacts[count].surname);
    cout << "Enter your phone number: ";
    getline(cin, contacts[count].phone);
    count++;
    cout << "Contact added!\n";
}

void deleteContact(Contact contacts[], int& count) {
    showContacts(contacts, count);
    if (count == 0) return;

    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Incorrect number.\n";
        return;
    }

    for (int i = index - 1; i < count - 1; ++i) {
        contacts[i] = contacts[i + 1];
    }
    count--;
    cout << "The contact has been deleted!\n";
}

int main() {
    const int maxContacts = 100;
    Contact contacts[maxContacts];
    int count = 0;
    int choice;

    while (true) {
        cout << "\nPhone Book:\n";
        cout << "1. Show contacts\n";
        cout << "2. Add a contact\n";
        cout << "3. Delete a contact\n";
        cout << "4. Exit\n";
        cout << "Select an action: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showContacts(contacts, count);
            break;
        case 2:
            addContact(contacts, count, maxContacts);
            break;
        case 3:
            deleteContact(contacts, count);
            break;
        case 4:
            cout << "Exit the program. Goodbye!\n";
            return 0;
        default:
            cout << "Incorrect choice. Try again.\n";
        }
    }
}
