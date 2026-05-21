#include <iostream>
#include <string>

using namespace std;

// Function declarations
void showMenu();
void checkBalance(double balance);
void depositMoney(double &balance, string transactions[], int &count);
void withdrawMoney(double &balance, string transactions[], int &count);
void viewTransactions(string transactions[], int count);

int main()
{
    const int correctPin = 1808;
    int enteredPin;
    int attempts = 0;
    bool loggedIn = false;

    double balance = 1000.0;

    string transactions[100];
    int transactionCount = 0;

    // Authentication system
    while (attempts < 3)
    {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == correctPin)
        {
            loggedIn = true;
            break;
        }
        else
        {
            cout << "Incorrect PIN!" << endl;
            attempts++;
        }
    }

    if (!loggedIn)
    {
        cout << "Maximum attempts reached. Access denied." << endl;
        return 0;
    }

    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            checkBalance(balance);
            break;

        case 2:
            depositMoney(balance, transactions, transactionCount);
            break;

        case 3:
            withdrawMoney(balance, transactions, transactionCount);
            break;

        case 4:
            viewTransactions(transactions, transactionCount);
            break;

        case 5:
            cout << "Thank you for using the ATM." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}

// Function to display menu
void showMenu()
{
    cout << "\n===== ATM MENU =====" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. View Transactions" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to check balance
void checkBalance(double balance)
{
    cout << "Current Balance: $" << balance << endl;
}

// Function to deposit money
void depositMoney(double &balance, string transactions[], int &count)
{
    double amount;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    balance += amount;

    transactions[count] = "Deposited: $" + to_string(amount);
    count++;

    cout << "Deposit successful." << endl;
}

// Function to withdraw money
void withdrawMoney(double &balance, string transactions[], int &count)
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= balance)
    {
        balance -= amount;

        transactions[count] = "Withdrawn: $" + to_string(amount);
        count++;

        cout << "Withdrawal successful." << endl;
    }
    else
    {
        cout << "Insufficient balance!" << endl;
    }
}

// Function to view transactions
void viewTransactions(string transactions[], int count)
{
    cout << "\n===== TRANSACTION HISTORY =====" << endl;

    if (count == 0)
    {
        cout << "No transactions available." << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
    }
}