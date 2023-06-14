/**
 * @file text_loader.h
 * @brief Définition de la classe text_loader.
 */

#include "text_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief Charge les données à partir d'un fichier texte et les stocke dans le conteneur.
 *
 * Cette classe permet de charger des données numériques à partir d'un fichier texte
 * et de les stocker dans un conteneur fourni en argument.
 */
class text_loader
{
public:
    /**
     * @brief Charge les données à partir d'un fichier texte dans le conteneur fourni.
     *
     * @param storage Le conteneur où stocker les données.
     * @return Une référence vers le conteneur mis à jour avec les données chargées.
     * @throw ios_base::failure si le fichier ne peut pas être ouvert.
     */
    storage_type &load(storage_type &storage);
};

storage_type &text_loader::load(storage_type &storage)
{
    storage_type &returned_storage = storage;
    ifstream file(source);  // Ouverture du fichier

    if (!file.is_open())
    {
        throw ios_base::failure("Can't open the file.");
    }

    string line;
    while (getline(file, line))
    {
        returned_storage.push_back(stold(line));  // Conversion de chaque ligne en nombre et ajout au conteneur
    }

    return returned_storage;
}
