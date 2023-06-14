#include "list_storage.h"
#include <iostream>

#include "text_loader.h"
#include "bin_loader.h"
#include "list_storage.h"
#include <iostream>

/**
 * \brief Fonction principale du programme.
 * \return 0 si le programme s'exécute correctement.
 */
int main()
{
    try
    {
        // Test the text_loader
        text_loader textLoader("texte.txt");  ///< Crée un objet text_loader pour charger un fichier texte.
        list_storage textStorage;  ///< Crée un objet list_storage pour stocker les données chargées.
        textLoader.load(textStorage);  ///< Charge les données du fichier texte dans textStorage.

        std::cout << "Data loaded from text file:\n";

        for (int i = 0; i < textStorage.size(); ++i)
        {
            std::cout << textStorage.get_element(i) << " ";  ///< Affiche chaque élément stocké dans textStorage.
        }
        std::cout << std::endl;

        // Test the bin_loader
        bin_loader binLoader("binary.bin");  ///< Crée un objet bin_loader pour charger un fichier binaire.
        list_storage binStorage;  ///< Crée un objet list_storage pour stocker les données chargées.
        binLoader.load(binStorage);  ///< Charge les données du fichier binaire dans binStorage.

        std::cout << "Data loaded from binary file:\n";
        for (int i = 0; i < binStorage.size(); ++i)
        {
            std::cout << binStorage.get_element(i) << " ";  ///< Affiche chaque élément stocké dans binStorage.
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;  ///< Affiche l'erreur en cas d'exception.
    }

    return 0;
}
