// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UI_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UI_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UI_EXPORTS
#define UI_API __declspec(dllexport)
#else
#define UI_API __declspec(dllimport)
#endif
#include <string>
// This class is exported from the dll
class UI_API UI {
private:
	std::string quickScanOptionText;
	std::string fullScanOptionText;
	std::string printHelpOption;
	std::string checkUpdateOptionText;
	std::string downloadUpdateOptionText;
	std::string uninstallOptionText;
	std::string quitOptionText;

public:
	enum Command { UNKNOWN, QUICK_SCAN, FULL_SCAN, CHECK_UPDATE, DOWNLOAD_UPDATE, UNINSTALL, PRINT_HELP, QUIT };

	UI();
	void SuggestHelp();
	void PrintUIInstruction();
	int ParsingCommand(std::string);
};
