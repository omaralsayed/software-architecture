// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the APPLICATION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// APPLICATION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "../Core/Core.h"
#include "../ReportGenerator/ReportGenerator.h"
#include "../Updater/Updater.h"
#include "../Uninstaller/Uninstaller.h"
#ifdef APPLICATION_EXPORTS
#define APPLICATION_API __declspec(dllexport)
#else
#define APPLICATION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class APPLICATION_API Application {
private:
	Core* appCore;
	ReportGenerator* appReporter;
	Updater* appUpdater;
	Uninstaller* appUninstaller;

public:
	void StartApp();
	void RunScan(bool);
	bool CheckForUpdate();
	void DownloadUpdate();
	void Uninstall();
	void Quit();
};


