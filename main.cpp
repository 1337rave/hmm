#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Шляхи до двох текстових файлів
    string filePath1 = "file1.txt";
    string filePath2 = "file2.txt";

    // Відкриття файлів для читання
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    // Перевірка, чи файли вдалося відкрити
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "One or both files could not be opened." << endl;
        return 1;
    }

    // Читання рядка за рядком і порівняння
    string line1, line2;
    int lineNumber = 1;  // Лічильник рядків

    while (getline(file1, line1) && getline(file2, line2)) {
        // Порівняння рядків
        if (line1 != line2) {
            cout << "Line " << lineNumber << " dont save:" << endl;
            cout << "From file 1: " << line1 << endl;
            cout << "From file 2: " << line2 << endl;
        }

        lineNumber++;
    }

    // Закриття файлів
    file1.close();
    file2.close();

    return 0;
}
