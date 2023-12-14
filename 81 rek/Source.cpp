#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>

using namespace std;

int countLetterGroupsRecursive(char* str, int i = 0, int count = 0) {
    if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0') {
        return count;
    }

    if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
        (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c') &&
        (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
        count++;
        return countLetterGroupsRecursive(str, i + 3, count);
    }

    return countLetterGroupsRecursive(str, i + 1, count);
}

char* ChangeRecursive(char* str, int len, int i = 0, char* tmp = nullptr, char* t = nullptr) {
    if (!tmp) {
        tmp = new char[len * 2 + 1];
        t = tmp;
        tmp[0] = '\0';
    }

    if (i >= len) {
        *t = '\0';
        return tmp;
    }

    if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
        (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c' ) &&
        (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
        strcat(t, "**");
        t += 2;
        return ChangeRecursive(str, len, i + 3, tmp, t);
    }
    else {
        *t++ = str[i];
        *t = '\0';  // додаємо завершуючий символ рядка
        return ChangeRecursive(str, len, i + 1, tmp, t);
    }
}


int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "i: " << countLetterGroupsRecursive(str) << endl;
    char* dest = ChangeRecursive(str, strlen(str));

    cout << "Modified string: " << dest << endl;

    delete[] dest;
    return 0;
}