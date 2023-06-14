#include "list_storage.h"
#include <iostream>

#include "text_loader.h"
#include "bin_loader.h"
#include "list_storage.h"
#include <iostream>

int main()
{
    try
    {
        // Test the text_loader
        text_loader textLoader("texte.txt");
        list_storage textStorage;
        textLoader.load(textStorage);

        std::cout << "Data loaded from text file:\n";

        for (int i = 0; i < textStorage.size(); ++i)
        {
            std::cout << textStorage.get_element(i) << " ";
        }
        std::cout << std::endl;

        // Test the bin_loader
        bin_loader binLoader("binary.bin");
        list_storage binStorage;
        binLoader.load(binStorage);

        std::cout << "Data loaded from binary file:\n";
        for (int i = 0; i < binStorage.size(); ++i)
        {
            std::cout << binStorage.get_element(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
