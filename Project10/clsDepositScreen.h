#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsDepositScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

	public:

		static void ShowDepositScreen() {
            _DrawScreenHeader("\t\tDeposit Screen");
            vector <clsBankClient> vClients = clsBankClient::GetClientsList();
            string AccountNumber = "";
            AccountNumber = _ReadAccountNumber();

            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
                AccountNumber = _ReadAccountNumber();
            }

            clsBankClient Client1 = clsBankClient::Find(AccountNumber);
            _PrintClient(Client1);

            double Amount = 0;
            cout << "\nPlease enter deposit amount? ";
            Amount = clsInputValidate::ReadDblNumber();

            char Answer = 'n';
            cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y')
            {
                Client1.Deposit(Amount);
                cout << "\n\nDone Successfully. New balance is: " << Client1.AccountBalance;
            }
            else {
				cout << "\nOperation canceled, no changes were made.\n";
            }

        }

};