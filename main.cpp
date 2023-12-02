#include <iostream>
#include <cctype>

using namespace std;

int main() {
    cout << "Enter text (Ctrl+Z to finish typing in the console):\n";

    // Отримання статистики
    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char ch;
    while (cin.get(ch)) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }
        else if (isalpha(ch)) {
            char lowercaseCh = tolower(ch);
            if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (isdigit(ch)) {
            digitCount++;
        }
    }

    // Виведення статистики в консоль
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    cout << "Number of vowels: " << vowelCount << endl;
    cout << "Number of consonant letters: " << consonantCount << endl;
    cout << "Number of digits : " << digitCount << endl;

    return 0;
}
