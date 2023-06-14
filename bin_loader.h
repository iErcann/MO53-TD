#ifndef BIN_LOADER_H
#define BIN_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>

/**
 * @brief Classe pour charger des données à partir d'un fichier binaire.
 *
 * Cette classe hérite de la classe `loader` et implémente la fonction de chargement
 * spécifique aux fichiers binaires.
 */
class bin_loader : public loader
{
public:
    /**
     * @brief Constructeur par défaut.
     *
     * Initialise le nom du fichier à "loader.bin".
     */
    bin_loader() : loader("loader.bin") {}

    /**
     * @brief Constructeur avec un nom de fichier spécifié.
     *
     * @param s Nom du fichier à charger.
     */
    bin_loader(const string &s) : loader(s){};

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~bin_loader() {}

    /**
     * @brief Fonction de chargement.
     *
     * Charge les données à partir d'un fichier binaire et les stocke dans l'objet
     * de type `storage_type` passé en paramètre.
     *
     * @param storage Objet de type `storage_type` dans lequel stocker les données chargées.
     * @return Une référence vers l'objet `storage_type` après le chargement.
     */
    storage_type &load(storage_type &storage);
};

#endif // BIN_LOADER_H
