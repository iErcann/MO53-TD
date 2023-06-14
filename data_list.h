#ifndef DATA_LIST_H
#define DATA_LIST_H

#include <vector>
#include <string>

/**
 * @brief Classe représentant un élément de liste.
 */
class list_element
{
    double _value; /**< Valeur de l'élément */
    list_element *_prev; /**< Pointeur vers l'élément précédent */
    list_element *_next; /**< Pointeur vers l'élément suivant */

public:
    /**
     * @brief Constructeur de la classe list_element.
     * @param v Valeur de l'élément
     * @param p Pointeur vers l'élément précédent
     * @param n Pointeur vers l'élément suivant
     */
    list_element(double v = 0.0, list_element *p = nullptr, list_element *n = nullptr) : _value(v), _prev(p), _next(n) {}

    /**
     * @brief Destructeur de la classe list_element.
     */
    ~list_element() {}

    /**
     * @brief Accesseur pour l'élément suivant.
     * @return Pointeur vers l'élément suivant
     */
    list_element *get_next() { return _next; }

    /**
     * @brief Mutateur pour l'élément suivant.
     * @param n Pointeur vers l'élément suivant
     */
    void set_next(list_element *n) { _next = n; }

    /**
     * @brief Accesseur pour l'élément précédent.
     * @return Pointeur vers l'élément précédent
     */
    list_element *get_prev() { return _prev; }

    /**
     * @brief Mutateur pour l'élément précédent.
     * @param n Pointeur vers l'élément précédent
     */
    void set_prev(list_element *n) { _prev = n; }

    /**
     * @brief Accesseur pour la valeur de l'élément.
     * @return Valeur de l'élément
     */
    double get_value() const { return _value; }

    /**
     * @brief Mutateur pour la valeur de l'élément.
     * @param v Nouvelle valeur de l'élément
     */
    void set_value(double v) { _value = v; }
};

/**
 * @brief Classe représentant une liste de valeurs.
 */
class values_list
{
    list_element *_head; /**< Pointeur vers le premier élément de la liste */
    list_element *_tail; /**< Pointeur vers le dernier élément de la liste */

public:
    /**
     * @brief Constructeur par défaut de la classe values_list.
     */
    values_list() : _head(nullptr), _tail(nullptr) {}

    /**
     * @brief Constructeur de copie de la classe values_list.
     * @param other Autre instance de values_list à copier
     */
    values_list(const values_list &other);

    /**
     * @brief Destructeur de la classe values_list.
     */
    ~values_list() { clear(); }

    /**
     * @brief Opérateur d'assignation de la classe values_list.
     * @param other Autre instance de values_list à copier
     * @return Référence à l'instance courante de values_list
     */
    values_list &operator=(const values_list &other);

    /**
     * @brief Vide la liste en supprimant tous les éléments.
     */
    void clear();

    /**
     * @brief Ajoute une valeur à la fin de la liste.
     * @param v Valeur à ajouter
     */
    void push_back(double v);

    /**
     * @brief Supprime le dernier élément de la liste.
     */
    void pop_element(); // Remove last element

    /**
     * @brief Retourne le nombre d'éléments dans la liste.
     * @return Nombre d'éléments dans la liste
     */
    size_t size() const;

    /**
     * @brief Retourne la valeur d'un élément à une position donnée dans la liste.
     * @param position Position de l'élément
     * @return Valeur de l'élément à la position donnée
     */
    double get_value(size_t position) const;

    /**
     * @brief Trie la liste dans l'ordre croissant ou décroissant.
     * @param ascending True pour trier dans l'ordre croissant, false pour trier dans l'ordre décroissant
     */
    void sort_list(bool ascending);

    /**
     * @brief Classe itératrice pour parcourir les éléments de la liste.
     */
    struct iterator_values_list
    {

    private:
        list_element *element; /**< Pointeur vers l'élément courant */

    public:
        /**
         * @brief Constructeur de la classe iterator_values_list.
         * @param element Pointeur vers l'élément courant
         */
        iterator_values_list(list_element *element);

        /**
         * @brief Surcharge de l'opérateur de déréférencement.
         * @return Référence à l'élément courant
         */
        list_element &operator*() const { return *element; };

        /**
         * @brief Accesseur pour l'élément courant.
         * @return Pointeur vers l'élément courant
         */
        list_element *getElement() { return this->element; };

        /**
         * @brief Surcharge de l'opérateur d'incrémentation préfixe.
         * @return Référence à l'instance courante de iterator_values_list
         */
        iterator_values_list &operator++();

        /**
         * @brief Surcharge de l'opérateur d'incrémentation postfixe.
         * @return Instance précédente de iterator_values_list
         */
        iterator_values_list &operator++(int);

        /**
         * @brief Surcharge de l'opérateur de différence.
         * @param itr1 Première instance de iterator_values_list à comparer
         * @param itr2 Deuxième instance de iterator_values_list à comparer
         * @return True si les instances sont différentes, false sinon
         */
        friend bool operator!=(const iterator_values_list &itr1, const iterator_values_list &itr2) { return (itr1.element != itr2.element); };
    };

    /**
     * @brief Retourne un itérateur pointant vers le premier élément de la liste.
     * @return Itérateur pointant vers le premier élément de la liste
     */
    iterator_values_list begin();

    /**
     * @brief Retourne un itérateur pointant vers la fin de la liste.
     * @return Itérateur pointant vers la fin de la liste
     */
    iterator_values_list end();

    /**
     * @brief Surcharge de l'opérateur d'indexation.
     * @param i Indice de l'élément à accéder
     * @return Référence à l'élément à l'indice donné
     */
    list_element &operator[](int i)
    {
        iterator_values_list it = begin();
        int count = 0;
        while (count < i && it != end())
        {
            it++;
            count++;
        }
        return *it;
    }
};

/**
 * @brief Classe représentant une liste de données.
 */
class data_list
{
    values_list _values; /**< Liste de valeurs */

public:
    /**
     * @brief Constructeur par défaut de la classe data_list.
     */
    data_list();

    /**
     * @brief Constructeur de copie de la classe data_list.
     * @param other Autre instance de data_list à copier
     */
    data_list(const data_list &other);

    /**
     * @brief Destructeur de la classe data_list.
     */
    ~data_list() { _values.clear(); }

    /**
     * @brief Méthode pour remplir la liste à partir d'une source texte.
     * @param source Chemin vers le fichier source texte
     */
    void from_text(const std::string &source);

    /**
     * @brief Méthode pour remplir la liste à partir d'une source binaire.
     * @param source Chemin vers le fichier source binaire
     */
    void from_binary(const std::string &source);

    /**
     * @brief Méthode pour écrire les données de la liste vers une destination texte.
     * @param destination Chemin vers le fichier destination texte
     */
    void to_text(const std::string &destination);

    /**
     * @brief Méthode pour écrire les données de la liste vers une destination binaire.
     * @param destination Chemin vers le fichier destination binaire
     */
    void to_binary(const std::string &destination);

    /**
     * @brief Affiche les données de la liste.
     */
    void print_data() const;

    /**
     * @brief Calcule et retourne une nouvelle liste avec la moyenne mobile des données.
     * @param window_width Largeur de la fenêtre de la moyenne mobile
     * @return Nouvelle liste avec la moyenne mobile des données
     */
    data_list moving_average(size_t window_width);

    /**
     * @brief Trie la liste dans l'ordre croissant ou décroissant et retourne une nouvelle liste triée.
     * @param ascending True pour trier dans l'ordre croissant, false pour trier dans l'ordre décroissant
     * @return Nouvelle liste triée
     */
    data_list sort_table(bool ascending = true);

    /**
     * @brief Calcule et retourne une nouvelle liste avec la moyenne des données.
     * @return Nouvelle liste avec la moyenne des données (une seule valeur)
     */
    data_list average();

    /**
     * @brief Calcule et retourne une nouvelle liste avec la somme des données.
     * @return Nouvelle liste avec la somme des données (une seule valeur)
     */
    data_list table_sum();

    /**
     * @brief Calcule et retourne une nouvelle liste avec le nombre d'éléments dans la liste.
     * @return Nouvelle liste avec le nombre d'éléments dans la liste (une seule valeur)
     */
    data_list table_count();
};

#endif // DATA_LIST_H
