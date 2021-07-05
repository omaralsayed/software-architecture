// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UPDATER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UPDATER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UPDATER_EXPORTS
#define UPDATER_API __declspec(dllexport)
#else
#define UPDATER_API __declspec(dllimport)
#endif
#include <string>

// This class is exported from the dll
class UPDATER_API Updater {
private:
	int updatePackage;
	int RetrieveData(std::string);
public:
	Updater(void);
	bool CheckForUpdate();
	void DownloadUpdate();

	// TODO: add your methods here.
};
