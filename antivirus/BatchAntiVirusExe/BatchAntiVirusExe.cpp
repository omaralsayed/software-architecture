#include <iostream>
#include "..\Application\Application.h"

int main() {
    Application app_test;
    app_test.StartApp();
    if (app_test.CheckForUpdate()) {
        app_test.DownloadUpdate();
    }
    app_test.RunScan(false);
    app_test.Quit();
    
}

