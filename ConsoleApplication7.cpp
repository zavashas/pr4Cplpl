#include <iostream>
#include <string>
#include <algorithm> 
#include <Windows.h>

using namespace std;

wstring reverse(const wstring input) {
    wstring reversed = input;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

wstring removeVowels(const wstring input) {
    wstring result;
    for (wchar_t ch : input) {
        if (!wcschr(L"аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouyAEIOUY", ch)) {
            result.push_back(ch);
        }
    }
    return result;
}

wstring removeConsonants(const wstring input) {
    wstring result;
    for (wchar_t ch : input) {
        if (!wcschr(L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩbcdfghjklmnpqrstvwxzBCDFGHJKLMNOPQRSTVWXZ", ch)) {
            result.push_back(ch);
        }
    }
    return result;
}

wstring shuffle(const wstring input) {
    wstring shuffle = input;
    random_shuffle(shuffle.begin(), shuffle.end());
    return shuffle;
}

int main() {

    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    wcout << L"Введите слово: ";
    wstring word;
    getline(wcin, word);

    do
    {
        cout << "Выберите действие:\n";
        cout << "1. Слово задом наперед.\n";
        cout << "2. Вывести слово без гласных.\n";
        cout << "3. Вывести слово без согласных.\n";
        cout << "4. Рандомно раскидывать буквы заданного слова.\n";

        int choice;
        wcin >> choice;

        switch (choice) {
        case 1:
            wcout << L"Результат: " << reverse(word) << endl;
            break;
        case 2:
            wcout << L"Результат: " << removeVowels(word) << endl;
            break;
        case 3:
            wcout << L"Результат: " << removeConsonants(word) << endl;
            break;
        case 4:
            srand(time(nullptr));
            wcout << L"Результат: " << shuffle(word) << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
            break;
        }
    } while (true);
    return 0;
}
