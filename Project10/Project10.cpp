#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"














void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FirstName + " " + Client.LastName;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}
void ShowTotalBalances()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n________________________________________________";
    cout << "____________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n________________________________________________";
    cout << "____________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);

            cout << endl;
        }

    cout << "\n________________________________________________";
    cout << "____________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
    cout << "\t\t\t\t\t ( " << clsUtil::NumberToText(TotalBalances)<<" )";

}

int main()

{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
    return 0;
}