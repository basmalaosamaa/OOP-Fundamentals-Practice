#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
    enum enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenu = 4 };

    static void _ShowDepositScreen() {
		cout << "\nDeposit Screen Will be here...\n";
    }
    static void _GoBackToTransactionsMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";
		system("pause>0");
		ShowTransactionsMenu();

    }
    static void _ShowWithdrawScreen() {
		cout << "\nWithdraw Screen Will be here...\n";
    }
	static void _ShowTotalBalancesScreen() {
		cout << "\nTotal Balances Screen Will be here...\n";
	}
    static void _PerfromTransactionsMenuOption(enTransactionsMenuOptions TransactionMenuOption)
    {
        switch (TransactionMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }


        case enTransactionsMenuOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }


        case enTransactionsMenuOptions::eShowMainMenu:
        {



        }

        }

    }

    static short _ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }
public:
    static void ShowTransactionsMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }
};

