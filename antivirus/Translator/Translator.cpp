// Translator.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Translator.h"



// This is the constructor of a class that has been exported.
std::string Translator::translate(std::string context, std::string text) {
    //std::string language = "de_DE.UTF - 8";
    std::string language = "";
    std::string resourcePath = "..\\Translator\\";
    std::string domain = "translation";

    boost::locale::generator gen;
    gen.add_messages_path(resourcePath);
    gen.add_messages_domain(domain);

    std::locale::global(gen(language));
    std::cout.imbue(std::locale());

    return boost::locale::translate(context, text);
}
