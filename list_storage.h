#ifndef LIST_STORAGE_H
#define LIST_STORAGE_H

#include "storage_type.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

/**
 * @brief Classe représentant un élément d'une liste
 */
class list_element
{
    double _value; /**< Valeur de l'élément */
    shared_ptr<list_element> _prev; /**< Pointeur vers l'élément précédent */
    shared_ptr<list_element> _next; /**< Pointeur vers l'élément suivant */

public:
    /**
     * @brief Constructeur de list_element
     * @param v Valeur de l'élément
     * @param p Pointeur vers l'élément précédent
     * @param n Pointeur vers l'élément suivant
     */
    list_element(double v = 0.0, shared_ptr<list_element> p = nullptr, shared_ptr<list_element> n = nullptr) : _value(v), _prev(p), _next(n) {}

    /**
     * @brief Destructeur de list_element
     */
    ~list_element() {}

    /**
     * @brief Obtient le pointeur vers l'élément suivant
     * @return Pointeur vers l'élément suivant
     */
    shared_ptr<list_element> get_next() { return _next; }

    /**
     * @brief Définit le pointeur vers l'élément suivant
     * @param n Pointeur vers l'élément suivant
     */
    void set_next(shared_ptr<list_element> n) { _next = n; }

    /**
     * @brief Obtient le pointeur vers l'élément précédent
     * @return Pointeur vers l'élément précédent
     */
    shared_ptr<list_element> get_prev() { return _prev; }

    /**
     * @brief Définit le pointeur vers l'élément précédent
     * @param n Pointeur vers l'élément précédent
     */
    void set_prev(shared_ptr<list_element> n) { _prev = n; }

    /**
     * @brief Obtient la valeur de l'élément
     * @return Valeur de l'élément
     */
    double get_value() const { return _value; }

    /**
     * @brief Définit la valeur de l'élément
     * @param v Valeur de l'élément
     */
    void set_value(double v) { _value = v; }
};

/**
 * @brief Classe représentant un stockage de données sous forme de liste
 */
class list_storage : public storage_type
{
private:
    shared_ptr<list_element> _head; /**< Pointeur vers la tête de la liste */
    shared_ptr<list_element> _tail; /**< Pointeur vers la queue de la liste */

public:
    /**
     * @brief Constructeur par défaut de list_storage
     */
    list_storage(){};

    /**
     * @brief Constructeur de copie de list_storage
     * @param storage Le list_storage à copier
     */
    list_storage(const list_storage &storage);

    /**
     * @brief Opérateur d'assignation de list_storage
     * @param storage Le list_storage à assigner
     * @return Une référence vers le list_storage assigné
     */
    list_storage &operator=(const list_storage &storage);

    /**
     * @brief Destructeur virtuel de list_storage
     */
    virtual ~list_storage() override{};

    /**
     * @brief Ajoute un élément à la fin de la liste
     * @param d Valeur de l'élément à ajouter
     */
    void push_back(const double d);

    /**
     * @brief Obtient l'élément à la position spécifiée dans la liste
     * @param position Position de l'élément à obtenir
     * @return Valeur de l'élément à la position spécifiée
     */
    double get_element(const int position) const;

    /**
     * @brief Supprime et retourne l'élément en tête de liste
     * @return Valeur de l'élément supprimé
     */
    double pop_element();

    /**
     * @brief Vide la liste
     */
    void clear();

    /**
     * @brief Obtient le nombre d'éléments dans la liste
     * @return Nombre d'éléments dans la liste
     */
    int size() const;

    /**
     * @brief Trie les éléments du stockage
     * @param ascending Booléen indiquant si le tri est croissant ou non
     */
    void sort_storage(const bool ascending);
};

#endif // LIST_STORAGE_H
