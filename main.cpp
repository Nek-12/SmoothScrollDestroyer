#include <cassert>
#include <vector>
#include <cstdio>
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>

std::string GetTime() { return std::to_string(time(nullptr) ); }

int main()
{
    const char key[]{"\\Software\\SmoothScroll"};
    const char value[]{"kSSInstallDate"};
    DWORD dwErrMessageId = 0;
    LPTSTR lpErrCodeStr = nullptr;
    va_list result_state[1] = {ERROR_SUCCESS};
    PHKEY phkResult = nullptr;
    system("pause");
    try
    {
       if (RegOpenKeyExA(HKEY_CURRENT_USER, key, 0, KEY_SET_VALUE, phkResult)  != ERROR_SUCCESS ) throw result_state;

        system("pause");
        std::cout << RegSetKeyValueA(
                *phkResult,
                key,
                value,
                REG_SZ,
                GetTime().c_str(),
                sizeof(value) / sizeof(*value)
                    );
        system("pause");
    }
    catch (...)
    {
        std::cerr << FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
                                    nullptr,
                                    dwErrMessageId,
                                    0,
                                    lpErrCodeStr,
                                    1,
                                    result_state) << std::endl;
        std::cerr << *lpErrCodeStr << std::endl;
        system("pause");
        return(-1);
    }
    std::cout << "Changed the value to " << GetTime() << std::endl;
    system("pause");
    return 0;
}
