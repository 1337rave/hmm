#include <iostream>
#include <string>
#include <fstream>


using namespace std;

// Function to encrypt text using the Caesar cipher
string encryptCaesar(const string& text, int key) {
    string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            result += static_cast<char>((ch - base + key) % 26 + base);
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    cout << "Enter the path of the input file: ";
    string inputFilePath;
    getline(cin, inputFilePath);

    cout << "Enter the path of the output file: ";
    string outputFilePath;
    getline(cin, outputFilePath);

    // Open input file using standard input stream
    ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    // Read the content of the input file
    string content = "";
    char ch;
    while (inputFile.get(ch)) {
        content += ch;
    }

    // Close the input file
    inputFile.close();

    // Encryption key (shift value)
    int key;
    cout << "Enter the encryption key (an integer): ";
    cin >> key;

    // Encrypt the content
    string encryptedContent = encryptCaesar(content, key);

    // Open output file using standard output stream
    ofstream outputFile(outputFilePath);

    if (!outputFile.is_open()) {
        cerr << "Unable to open the output file." << endl;
        return 1;
    }

    // Write the encrypted content to the output file
    outputFile << encryptedContent;

    // Close the output file
    outputFile.close();

    cout << "Encryption completed. The result is saved in the output file." << endl;

    return 0;
}
