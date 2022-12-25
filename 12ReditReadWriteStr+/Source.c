#include <Stdio.h>
#include <Windows.h>


int main() {
    HKEY hMyKey;
    if (RegCreateKeyW(HKEY_CURRENT_USER, L"NewMyKey", &hMyKey) == ERROR_SUCCESS)
    {
        if (RegSetValueEx(hMyKey, L"nameparam", 0, REG_SZ, L"Message", 8 * sizeof(WCHAR)) == ERROR_SUCCESS)
        {
            WCHAR text[256];
            DWORD size = sizeof(WCHAR) * 256;
            if (RegGetValueW(hMyKey, NULL, L"nameparam", RRF_RT_REG_SZ, NULL, text, &size) == ERROR_SUCCESS)
            {
            MessageBoxW(NULL, text, L"YES", MB_OK);
            }
        }
    }
}
