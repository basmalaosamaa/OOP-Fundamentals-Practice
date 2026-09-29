#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
using namespace std;

int main()
{
    clsDate Date1;
    Date1.Print();

    clsDate Date2("35/1/2022");
    Date2.Print();

    clsDate Date3(20,12, 2022);
    Date3.Print();
    clsDate Date4(250, 2022);
    Date4.Print();

    
    //cout<< Date2.IsValidDate();
    return 0;
}

