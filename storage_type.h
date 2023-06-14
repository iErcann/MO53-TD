#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

/**
 * @class storage_type
 * @brief Classe abstraite représentant un type de stockage générique.
 */
class storage_type
{
public:
    /**
     * @brief Constructeur par défaut.
     */
    storage_type(){};

    /**
     * @brief Constructeur de copie.
     * @param storage L'objet à copier.
     */
    storage_type(const storage_type &storage){};

    /**
     * @brief Opérateur d'affectation.
     * @param storage L'objet à affecter.
     * @return Une référence sur l'objet lui-même.
     */
    storage_type &operator=(const storage_type &storage) { return *this; };

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~storage_type(){};

    /**
     * @brief Ajoute un élément à la fin du stockage.
     * @param d Le double à ajouter.
     */
    virtual void push_back(const double d) = 0;

    /**
     * @brief Récupère l'élément à la position donnée.
     * @param position La position de l'élément.
     * @return La valeur de l'élément.
     */
    virtual double get_element(const int position) const = 0;

    /**
     * @brief Supprime et retourne l'élément en haut du stockage.
     * @return La valeur de l'élément supprimé.
     */
    virtual double pop_element() = 0;

    /**
     * @brief Vide le stockage.
     */
    virtual void clear() = 0;

    /**
     * @brief Retourne la taille du stockage.
     * @return La taille du stockage.
     */
    virtual int size() const = 0;

    /**
     * @brief Trie le stockage.
     * @param ascending Si vrai, trie en ordre croissant ; sinon, trie en ordre décroissant.
     */
    virtual void sort_storage(const bool ascending) = 0;
};

#endif // STORAGE_TYPE_H
