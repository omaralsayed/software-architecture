// Application.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Application.h"
#include "../Translator/Translator.h"




void Application::StartApp () {
	appCore = new Core();
	appReporter = new ReportGenerator();
	appUpdater = new Updater();
	appUninstaller = new Uninstaller();
	std::cout << Translator::translate("app_msg", "    App finished loading...") << "\n";
}

void Application::RunScan(bool quickScan) {
	std::cout << Translator::translate("app_msg", "    App starts scanning...") << "\n";
	appCore->ScanVirus(quickScan);
	appReporter->WriteReport();
	std::cout << Translator::translate("app_msg", "    App finished scanning...") << "\n";
}

bool Application::CheckForUpdate() {
	return appUpdater->CheckForUpdate();
}

void Application::DownloadUpdate() {
	appUpdater->DownloadUpdate();
}

void Application::Quit() {
	std::cout << Translator::translate("app_msg", "    App finished quitting...") << "\n";
	appCore->Stop();
}

void Application::Uninstall() {
	Quit();
	appReporter->WriteReport();
	appUninstaller->Run();
}
