#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>

/**
 * \class text_loader
 * \brief Classe représentant un chargeur de fichiers texte.
 *
 * La classe text_loader hérite de la classe loader et permet de charger
 * des données à partir d'un fichier texte dans un objet de type storage_type.
 */
class text_loader : public loader
{
public:
    /**
     * \brief Constructeur par défaut.
     *
     * Ce constructeur initialise le nom du fichier à "texte.txt".
     */
    text_loader() : loader("texte.txt") {}

    /**
     * \brief Constructeur avec nom de fichier personnalisé.
     *
     * Ce constructeur permet de spécifier le nom du fichier à charger.
     * \param s Le nom du fichier à charger.
     */
    text_loader(const std::string &s) : loader(s) {}

    /**
     * \brief Destructeur virtuel.
     *
     * Destructeur virtuel pour assurer la libération appropriée des ressources.
     */
    virtual ~text_loader() {}

    /**
     * \brief Charge les données du fichier texte dans le stockage spécifié.
     *
     * Cette fonction charge les données du fichier texte dans un objet de type storage_type.
     * \param storage L'objet de type storage_type dans lequel charger les données.
     * \return Une référence vers l'objet de type storage_type après le chargement des données.
     */
    storage_type &load(storage_type &storage);
};

#endif // TEXT_LOADER_H
