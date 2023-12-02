#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // ����� �� ���� ��������� �����
    string filePath1 = "file1.txt";
    string filePath2 = "file2.txt";

    // ³������� ����� ��� �������
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    // ��������, �� ����� ������� �������
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "One or both files could not be opened." << endl;
        return 1;
    }

    // ������� ����� �� ������ � ���������
    string line1, line2;
    int lineNumber = 1;  // ˳������� �����

    while (getline(file1, line1) && getline(file2, line2)) {
        // ��������� �����
        if (line1 != line2) {
            cout << "Line " << lineNumber << " dont save:" << endl;
            cout << "From file 1: " << line1 << endl;
            cout << "From file 2: " << line2 << endl;
        }

        lineNumber++;
    }

    // �������� �����
    file1.close();
    file2.close();

    return 0;
}
