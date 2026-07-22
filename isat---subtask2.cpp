x#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    string binary = "";
    if (decimal == 0) return "0";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";
    while (decimal > 0) {
        hex = hexDigits[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int power = 0;
    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = toupper(hex[i]);
        int value;
        if (c >= '0' && c <= '9') value = c - '0';
        else if (c >= 'A' && c <= 'F') value = 10 + (c - 'A');
        else {
            cout << "Invalid hexadecimal digit: " << c << endl;
            return -1;
        }
        decimal += value * pow(16, power);
        power++;
    }
    return decimal;
}

int main() {
    int choice;
    cout << "Select Conversion Type" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Binary to Decimal" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Binary equivalent: " << decimalToBinary(decimal) << endl;
    }
    else if (choice == 2) {
        string binary;
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Decimal equivalent: " << binaryToDecimal(binary) << endl;
    }
    else if (choice == 3) {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Hexadecimal equivalent: " << decimalToHexadecimal(decimal) << endl;
    }
    else if (choice == 4) {
        string hex;
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        cout << "Decimal equivalent: " << hexadecimalToDecimal(hex) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
