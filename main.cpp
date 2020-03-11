#include <cassert>
#include <vector>
#include <windows.h>
#include <string>
#include <ctime>
#include <iostream>

std::string GetTime() {return std::to_string(std::time(nullptr)); }

int main()
{
    const char* key = "SOFTWARE\\SmoothScroll";
    const char* val = "kSSInstallDate";
    //BYTE* bptime = (BYTE*)malloc(strlen(time.c_str()));
    BYTE* bptime = (BYTE*)GetTime().c_str();

    DWORD curReg = 0;
    DWORD curRegSize = sizeof(curReg)*5;
    LONG retCode;

    //std::cout << "Char: " << sizeof(char) << ", My arr: "
     //<< sizeof(BYTE)*strlen((char*)bptime)+1 << std::endl;
     std::cout << "Current time: " << bptime << std::endl;
    system("pause");

    try
    {
        HKEY hkMykey = nullptr;
        retCode = ::RegOpenKeyExA(
                HKEY_CURRENT_USER,
                key,
                0,
                KEY_SET_VALUE,
                &hkMykey
        );
        std::cout << (retCode == 0 ? "Success" : "Failed") << std::endl;
        //<< std::endl <<  "Handle: " << hkMykey << std::endl;
        system("pause");

        retCode = ::RegGetValue(
                HKEY_CURRENT_USER,
                key,
                val,
                RRF_RT_REG_SZ,
                nullptr,
                &curReg,
                &curRegSize
        );
        std::cout << retCode << std::endl
                  << "Key: " << curReg << std::endl
                  << std::endl <<  "Handle: " << hkMykey  << std::endl ;
        system("pause");
        retCode = RegSetValueExA(
                hkMykey,
                val,
                0,
                REG_SZ,
                bptime,
                sizeof(BYTE)*strlen((char*)bptime)+1
        );
        std::cout << retCode << std::endl
                  << "Time: " << std::string((char*)bptime) << std::endl;
        system("pause");


        RegCloseKey(hkMykey);
        return 0;
    }
    catch (...)
    {
        std::cerr << "Unhandled exception" << std::endl;
        system("pause");
        return(-1);
    }

}
