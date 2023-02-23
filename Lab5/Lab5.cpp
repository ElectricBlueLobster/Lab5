// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::string text;
std::vector<int> cypherVector({ 'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E' });

void Encode() {
    cout << "Input text to cypher: ";
    getline(cin, text);
    int length = text.size();

    for (int x = 0; x < length; x++) {
        if (int(text[char(x)]) >= 65 && int(text[char(x)]) <= 90 && isupper(text[char(x)])) {
            int temp = text[char(x)];

            text[char(x)] = char(cypherVector.at(temp - 65));
        }
        else if (int(text[char(x)]) >= 97 && int(text[char(x)]) <= 122 && islower(text[char(x)])) {
            int temp = text[char(x)];
            text[char(x)] = char(temp - 32);

            temp = text[char(x)];
            text[char(x)] = char(cypherVector.at(temp - 65));

            temp = text[char(x)];
            text[char(x)] = char(temp + 32);
        }
        else {
            text[char(x)] = text[char(x)];
        }
    }
    std::cout << "Encoded Message: " << '"' << text << '"';
}

int main() {
    Encode();
}