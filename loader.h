#ifndef LOADER_H
#define LOADER_H

#include "storage_type.h"
#include <string>

/**
 * @brief Classe abstraite représentant un chargeur de données.
 *
 * Cette classe abstraite définit l'interface commune pour tous les chargeurs de données.
 * Un chargeur est responsable de charger des données à partir d'une source spécifiée
 * dans un objet de type `storage_type`.
 */
class loader
{
protected:
    string source; /**< Le chemin d'accès à la source de données. */

public:
    /**
     * @brief Constructeur par défaut.
     *
     * Initialise la source de données avec la valeur par défaut "texte.txt".
     */
    loader() : source("texte.txt") {};

    /**
     * @brief Constructeur prenant en paramètre la source de données.
     *
     * @param s Le chemin d'accès à la source de données.
     */
    loader(const string &s) : source(s) {};

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~loader() {};

    /**
     * @brief Méthode abstraite pour charger les données dans un objet de type `storage_type`.
     *
     * @param storage L'objet `storage_type` dans lequel charger les données.
     * @return Une référence vers l'objet `storage_type` contenant les données chargées.
     */
    virtual storage_type &load(storage_type &storage) = 0;
};

#endif // LOADER_H
