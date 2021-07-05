// UI.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "UI.h"
#include "..\Translator\Translator.h"



UI::UI() {
	quickScanOptionText = Translator::translate("command", "quick");
	fullScanOptionText = Translator::translate("command", "full");
	checkUpdateOptionText = Translator::translate("command", "check");
	downloadUpdateOptionText = Translator::translate("command", "download");
	uninstallOptionText = Translator::translate("command", "uninstall");
	printHelpOption = Translator::translate("command", "help");
	quitOptionText = Translator::translate("command", "quit");
	std::cout << Translator::translate("ui_msg", "        UI started") << "\n";
}

void UI::SuggestHelp() {
	std::cout << Translator::translate("ui_msg", "    Unknown command") << "\n";
	std::cout << printHelpOption << ":\n\t" << Translator::translate("ui_msg", "Use this command to show help") << "\n";
}

void UI::PrintUIInstruction() {
	std::cout << Translator::translate("ui_msg", "Use those following command for this software") << "\n";
	std::cout << quickScanOptionText << ":\n\t" << Translator::translate("ui_msg", " Start a quick scan of your computer") << "\n";
	std::cout << fullScanOptionText << ":\n\t" << Translator::translate("ui_msg", " Start a full scan of your computer") << "\n";
	std::cout << checkUpdateOptionText << ":\n\t" << Translator::translate("ui_msg", "Check for the update of your software") << "\n";
	std::cout << downloadUpdateOptionText << ":\n\t" << Translator::translate("ui_msg", "Download update") << "\n";
	std::cout << uninstallOptionText << ":\n\t" << Translator::translate("ui_msg", "Uninstall this software") << "\n";
	std::cout << printHelpOption << ":\n\t" << Translator::translate("ui_msg", "Make this instruction appear again") << "\n";
	std::cout << quitOptionText << ":\n\t" << Translator::translate("ui_msg", " Quit our anti-virus program") << "\n";
}

int UI::ParsingCommand(std::string command) {
	if (command == quickScanOptionText) {
		return QUICK_SCAN;
	}
	else if (command == fullScanOptionText) {
		return FULL_SCAN;
	}
	else if (command == checkUpdateOptionText) {
		return CHECK_UPDATE;
	}
	else if (command == downloadUpdateOptionText) {
		return DOWNLOAD_UPDATE;
	}
	else if (command == uninstallOptionText) {
		return UNINSTALL;
	}
	else if (command == quitOptionText) {
		return QUIT;
	}
	else if (command == printHelpOption) {
		return PRINT_HELP;
	}
	return UNKNOWN;
}