#include <iostream>
#include "..\Application\Application.h"
#include "..\UI\UI.h"



int main() {
	Application app_test;
	app_test.StartApp();
	UI ui_test;
	ui_test.PrintUIInstruction();
	std::string command = "";

	while (true) {
		std::cout << ">";
		std::getline(std::cin, command);
		int commandNumber = ui_test.ParsingCommand(command);

		switch (commandNumber) {
		case UI::FULL_SCAN:
			app_test.RunScan(false);
			break;
		case UI::QUICK_SCAN:
			app_test.RunScan(true);
			break;
		case UI::CHECK_UPDATE:
			app_test.CheckForUpdate();
			break;
		case UI::DOWNLOAD_UPDATE:
			app_test.DownloadUpdate();
			break;
		case UI::UNINSTALL:
			app_test.Uninstall();
			break;
		case UI::PRINT_HELP:
			ui_test.PrintUIInstruction();
			break;
		case UI::QUIT:
			app_test.Quit();
			break;
		default:
			ui_test.SuggestHelp();
		}
	}
	
}

