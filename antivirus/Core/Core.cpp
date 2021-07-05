// Core.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Core.h"
#include "..\Translator\Translator.h"

// This is the constructor of a class that has been exported.
Core::Core() {
    std::cout << Translator::translate("core_msg", "Core loaded") << "\n";
}

void Core::ScanVirus(bool quickScan) {
    if (quickScan) {
        std::cout << Translator::translate("core_msg", "Core starts quick scan") << "\n";
    }
    else {
        std::cout << Translator::translate("core_msg", "Core starts full scan") << "\n";
    }
}

void Core::Stop() {
    std::cout << Translator::translate("core_msh", "Core is stopped") << "\n";
}
