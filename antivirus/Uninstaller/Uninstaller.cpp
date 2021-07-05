// Uninstaller.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Uninstaller.h"
#include "..\Translator\Translator.h"




// This is the constructor of a class that has been exported.
Uninstaller::Uninstaller() {
    std::cout << Translator::translate("uninstaller_msg", "Uninstaller loaded") << "\n";
}

void Uninstaller::Run() {
    std::cout << Translator::translate("uninstaller_msg", "Uninstalling the software...") << "\n";
    std::cout << Translator::translate("uninstaller_msg", "Done") << "\n";
}
