#include <Windows.h>
#include <Stdio.h>

HHOOK hHook;
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    // ���� ������� - ������� �������
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        // �������� �������� ������� �������
        TCHAR szKeyName[256];
        DWORD iKey = MapVirtualKey(p->vkCode, NULL) << 16;
        if (!((p->vkCode <= 32))) {
            iKey |= 0x1 << 24;
        }

        GetKeyNameText(iKey, szKeyName, 256);
        // ������� �������� ������� � MessageBox
        MessageBox(NULL, szKeyName, "Key Pressed", MB_OK);
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main()
{
    // ������������� ��� �� ��������� ������� ����������
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    // ������������ ��������� ����
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // ������� ���
    UnhookWindowsHookEx(hHook);
    return 0;
}
