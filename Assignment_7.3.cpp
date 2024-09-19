#include <iostream>
using namespace std;


enum EAccountType // Account type enum
{
    SAVING = 1,
    CURRENT,
    DMAT,
    EXIT
};

class InSufficientFundsException // Exception class
{
    int accNo;
    double balance;
    string message;

public:
    InSufficientFundsException() {}

    InSufficientFundsException(int accNo, double balance, string message)
    {
        this->message = message;
        this->accNo = accNo;
        this->balance = balance;
    }

    void display()
    {
        cout << "***************************************" << endl;
        cout << "Exception occured!!! " << endl;
        cout << "Accout No. : " << accNo << endl;
        cout << "Balance : " << balance << endl;
        cout << "Message - " << message << endl;
        cout << "***************************************" << endl;
    }
};

class Account // Account class
{
    int accNo;
    EAccountType type;
    double balance;

public:
    Account() // Default constructor
    {
        this->accNo = 1234;
        this->balance = 00;
    }

    Account(int accNo, EAccountType type, double balance) // Parameterized constructor
    {
        this->accNo = accNo;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        cout << "Enter account number : " << endl;
        cin >> accNo;
        cout << "1. SAVING " << endl;
        cout << "2. CURRENT " << endl;
        cout << "3. DMAT : " << endl;
        cout << "Enter Account Type : " << endl;
        int choice;
        cin >> choice;
        type = EAccountType(choice);
        cout << "Enter balance : " << endl;
        cin >> balance;
    }

    void diaplay()
    {
        cout << "Account No. : " << accNo << endl;
        cout << "Balance : " << balance << endl;
        switch (type)
        {
        case SAVING:
            cout << "Account Type = Saving " << endl;
            break;
        case CURRENT:
            cout << "Account Type = Current " << endl;
            break;
        case DMAT:
            cout << "Account Type = Dmat " << endl;
            break;
        }
    }

    void deposite(int amt) // deposite
    {
        if (amt < 0)
        {
            cout << "expection";
            throw InSufficientFundsException(accNo, balance,"Amount can not be -ve ");
        }
        else
        {
            balance = balance + amt;
            cout << "New Balance : " << balance << endl;
        }
    }

    void withdraw(int amt) // withdraw
    {
        if (amt > balance)
        {
            throw InSufficientFundsException(accNo, balance,"Entered amount is greate than balance.. can't withdraw!!");
        }
        else
            balance = balance - amt;
         cout << "New Balance : " << balance << endl;
    }
};

int getDepostite()
{
    int amt;
    cout << "Enter amount you want to deposite." << endl;
    cin >> amt;
    return amt;
}

int getWithdraw()
{
    int amt;
    cout << "Enter amount you want to withdraw." << endl;
    cin >> amt;
    return amt;
}

int main()
{
    Account *arr[5];
    int index = 0;

    while (index != 5)
    {
        if (index < 5)
        {
            arr[index] = new Account;
            arr[index]->accept();
            arr[index]->diaplay();

            try
            {
                arr[index]->deposite(getDepostite());
            }
            catch (InSufficientFundsException e)
            {
                e.display();
            }

            try
            {
                arr[index]->withdraw(getWithdraw());
            }
            catch (InSufficientFundsException e)
            {
                e.display();
            }
            index++;
        }
        else
        {
            cout << "Account array is full!!!" << endl;
        }
    }
    return 0;
}