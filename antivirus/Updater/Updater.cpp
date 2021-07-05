// Updater.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Updater.h"
#include "..\Translator\Translator.h"



// This is the constructor of a class that has been exported.
Updater::Updater() {
    updatePackage = 0;
    std::cout << Translator::translate("update_msg", "Updater started") << "\n";
}

int Updater::RetrieveData(std::string link) {
    return 1;
}

bool Updater::CheckForUpdate() {
    std::cout << Translator::translate("update_msg", "Finding updates...") << "\n";
    int package = RetrieveData("https://dummy_update_link.com/update/version") == 1;
    if (package == 1) {
        std::cout <<  Translator::translate("update_msg", "Found new update. Please download the update") << "\n";
    }
    else {
        std::cout << Translator::translate("update_msg", "Your software is the newest one") << "\n";
    }
    return package == 1;
}

void Updater::DownloadUpdate() {
    updatePackage = RetrieveData("https://dummy_update_link.com/update/version");
    std::cout << Translator::translate("update_msg", "Update downloaded") << "\n";
}
