#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;
class clsUtil
{
public:
    enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

	static void Srand()
	{
		// Seed the random number generator with the current time.
		srand((unsigned)time(NULL));
	}
    static int RandomNumber(int From, int To)
    {
        // Generate a random number between 0 and (To - From), then add From to shift the range.
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    // Function: GetRandomCharacter
    // Purpose: Returns a random character based on the specified character type.
    // Parameters:
    //   - CharType: An enCharType value indicating which type of character to generate.
    // Returns: A random character from the given category.
    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
            return char(RandomNumber(97, 122));
            break; // break is not necessary after return.
        }
        case enCharType::CapitalLetter:
        {
            // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            // Generate a random special character (ASCII: 33 '!' to 47 '/').
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            // Generate a random digit (ASCII: 48 '0' to 57 '9').
            return char(RandomNumber(48, 57));
            break;
        }
        }
        // If no valid type is provided, return a null character.
        return '\0';
    }

   

    // Function: GenerateWord
    // Purpose: Generates a random word of a specified length using characters from a given type.
    // Parameters:
    //   - CharType: The type of character to use (e.g., CapitalLetter).
    //   - Length: The number of characters in the word.
    // Returns: A string containing the generated word.
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;  // Initialize an empty string to build the word.

        // Loop for the number of characters specified by Length.
        for (int i = 1; i <= Length; i++)
        {
            // Append a random character of the specified type to the word.
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    // Function: GenerateKey
    // Purpose: Generates a key string composed of four groups of 4 uppercase letters separated by hyphens.
    // Returns: A string representing the generated key.
    static string GenerateKey()
    {
        string Key = "";  // Initialize an empty key string.

        // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;
    }

    // Function: GenerateKeys
    // Purpose: Generates and prints a specified number of keys.
    // Parameters:
    //   - NumberOfKeys: The total number of keys to generate.
    static void GenerateKeys(short NumberOfKeys)
    {
        // Loop from 1 to NumberOfKeys.
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            // Print the current key number and the generated key.
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }

   


    static void FillArrayWithRandomNumbers(int arr[100], int arrLength , int From, int To)
    {

        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }
    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int Length)
    {
      
        // Fill the array with random words.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Length);
    
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
       
        // Fill the array with random words.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    
    }

    static void Swap(int& A, int& B)
    {
        int Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }

    static void Swap(string& A, string& B)
    {
        string Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }

    static void Swap(double& A, double& B)
    {
        double Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }

    static void Swap(clsDate& A, clsDate& B)
    {
       clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }
     static void FillArrayWithRandomKeys(string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey();
    }

    static string EncryptText(string Text, short EncryptionKey)
    {
        // Loop through each character of the text.
        // Note: Using "<= Text.length()" iterates one extra time (accessing the null terminator), 
        // which may be unintended. Ideally, use "< Text.length()".
        for (int i = 0; i <= Text.length(); i++)
        {
            // Convert the current character to its integer ASCII value,
            // add the encryption key, cast it back to char, and assign it back.
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text; // Return the encrypted text.
    }

    static string DecryptText(string Text, short EncryptionKey)
    {
        // Loop through each character of the text.
        // Note: Using "<= Text.length()" will process one extra character (the null terminator).
        for (int i = 0; i <= Text.length(); i++)
        {
            // Convert the current character to its ASCII integer value,
            // subtract the encryption key, cast back to char, and assign it back.
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text; // Return the decrypted text.
    }

    static string Tabs(int NumOfTabs) {
        string Tabs = "";
        for (int i = 0; i < NumOfTabs; i++)
            Tabs += "\t";
        return Tabs;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

    
};

