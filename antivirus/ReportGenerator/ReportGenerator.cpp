// ReportGenerator.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ReportGenerator.h"
#include "../Translator/Translator.h"

void ReportGenerator::WriteReport() {
	std::cout << Translator::translate("reporter_msg", "Our reporter is writing report about your computer") << "\n";
}