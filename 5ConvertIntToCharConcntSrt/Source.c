#include <Windows.h>
#include <Stdio.h>

    char* int_to_string(int n)
    {
        int nDigits = 1;  // счетчик разрядов
        // Определяем, сколько разрядов имеет число
        int new_n = n;
        while (new_n / 10 != 0)
        {
            nDigits++;
            new_n /= 10;
        }

        char* s = "";
        int i = 0;
        if (n < 0) {
            n = -n;
            nDigits++;
        }
        s = malloc(nDigits);
        for (i; i < nDigits; i++)
        {
            s[i] = n % 10 + '0';
            if (n == 0) {
                s[i] = '-';
            }
            else {
                n /= 10;
            }


        }
        s[nDigits] = '\0';

        int j;
        char c;

        for (i = 0, j = nDigits - 1; i < j; i++, j--) {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        return s;
    }

    char* Concat(char* str1, char* str2) {
        int count = 0;
        while (str1[count] != '\0')
            count++;
        int count2 = 0;
        while (str2[count2] != '\0')
            count2++;
        count += count2;
        char* result = malloc(count + 1);
        result[count] = '\0';
        count2 = 0;
        while (str1[count2] != '\0')
        {
            result[count2] = str1[count2];
            count2++;
        }
        count = 0;
        while (str2[count] != '\0')
        {
            result[count2] = str2[count];
            count++;
            count2++;
        }
        return result;
    }

