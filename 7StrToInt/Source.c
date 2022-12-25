#include <Windows.h>
#include <Stdio.h>

int GetLevels(int a, int n) {
    for (size_t i = 1; i < n; i++)
    {
        a *= 10;
    }
    return a;
}

int string_to_int(LPWSTR str) {
    int result = 0;
    int is_negative = 0;
    int i = 0;
    int count = 0;

    if (str[i] == L'-') {
        is_negative = 1;
        i++;
    }
    int index = i;
    while (str[index] != '\0')
    {
        count++;
        index++;
    }

    while (str[i] != L'\0') {
        if (str[i] >= L'0' || str[i] <= L'9') {
            result += (int)(str[i] - '0') * (GetLevels(10, count) / 10);
            count--;
        }
        i++;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}
