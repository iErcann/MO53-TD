#include "data_list.h"
#include "manager.h"

#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

void Manager::createObjects()
{
    // Création des objets nécessaires

    // Création d'une instance de data_list
    _dataList.from_binary("binary.bin");
}

void Manager::runCalculations()
{
    // Effectuer les calculs requis sur les objets

    std::cout << "t:" << std::endl;
    _dataList.print_data();

    // Calcul de la moyenne mobile avec une fenêtre de largeur 2
    data_list t2 = _dataList.moving_average(2);

    std::cout << "t2:" << std::endl;
    t2.print_data();
}

void Manager::saveResults()
{
    // Sauvegarder les résultats dans des fichiers ou d'autres formes de sortie

    // Sauvegarder les données de _dataList dans un fichier texte
    _dataList.to_text("output.txt");
}

Manager::Manager()
{
    // Constructor code
}

data_list &Manager::getDataList()
{
    return _dataList;
}