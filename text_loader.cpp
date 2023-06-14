/**
 * \file text_loader.h
 * \brief Définition de la classe text_loader.
 */

#include "text_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std;

/**
 * \brief Charge les données à partir d'un fichier texte dans une structure de stockage.
 * \param storage La structure de stockage à remplir avec les données du fichier.
 * \return La structure de stockage remplie.
 * \throws ios_base::failure Si le fichier ne peut pas être ouvert.
 */
storage_type &text_loader::load(storage_type &storage)
{
    storage_type &returned_storage = storage;
    ifstream f(source);

    if (!f.is_open())
    {
        throw ios_base::failure("Can't open the file.");
    }

    string line;
    while (getline(f, line))
    {
        returned_storage.push_back(stold(line));
    }

    return returned_storage;
}
