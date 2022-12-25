#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

HHOOK hHook = NULL;
int count;
WPARAM ButtonCode;
LPWSTR str[256];

LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        switch (wParam)
        {
        case WM_LBUTTONDOWN:
            if (ButtonCode != wParam)
                count = 0;
            ButtonCode = wParam;
            count++;
            swprintf_s(str, 256, L"Левая клавиша мыши нажата %d раз", count);
            MessageBox(NULL, str,  L"Оповещение", MB_OK);//Дальше по аналогии
            break;
        }
    }

    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main()
{
    hHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hHook);

    return 0;
}
