#include "rolling_average.h"

rolling_average::rolling_average(int size) : window_size(size) {}

double rolling_average::calculate(const storage_type& storage) {
    // Implémentation du calcul de la moyenne mobile
    // Utilise la taille de la fenêtre (window_size) et les données fournies (storage)
    // Retourne le résultat du calcul de la moyenne mobile

    double sum = 0.0;
    for (int i = 0; i < window_size; i++) {
        sum += storage[i];
    }
    double average = sum / window_size;
    return average;
}