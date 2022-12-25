#include <stdio.h>
#include <Windows.h>

int main()
{
    DWORD st = 100;
    DWORD size = sizeof(st);
    HKEY hMyKey;
    if (RegCreateKeyW(HKEY_CURRENT_USER, L"NewMyKey", &hMyKey) == ERROR_SUCCESS)
    {
        if (RegSetValueEx(hMyKey, L"nameparamdword", 0, REG_DWORD, (const BYTE*)&st, sizeof(st)) == ERROR_SUCCESS)
        {
            if (RegGetValueW(hMyKey, NULL, L"nameparamdword", RRF_RT_DWORD, NULL, (LPBYTE)&st, &size) == ERROR_SUCCESS)
            {
                WCHAR buf[256];
                swprintf_s(buf, 256, L"%d", st);

                MessageBox(NULL, buf, L"Оповещение", MB_OK);
            }
        }
    }
    return 0;
}
