/**

@file manager.cpp
@brief Implementation file for the Manager class.
*/
#include "data_list.h"
#include "manager.h"

#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

/**

@brief Create the necessary objects.

This function creates an instance of the data_list class and loads data from a binary file.

It uses the from_binary function of the data_list class to read data from the "binary.bin" file.
*/
void Manager::createObjects()
{
// Création des objets nécessaires

// Création d'une instance de data_list
_dataList.from_binary("binary.bin");
}

/**

@brief Perform the required calculations on the objects.

This function performs calculations on the data_list object.

It prints the original data and calculates the moving average with a window width of 2.
*/
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

/**

@brief Save the results to output files or other forms of output.

This function saves the results to a text file.

It uses the to_text function of the data_list class to save the data from _dataList to the "output.txt" file.
*/
void Manager::saveResults()
{
// Sauvegarder les résultats dans des fichiers ou d'autres formes de sortie

// Sauvegarder les données de _dataList dans un fichier texte
_dataList.to_text("output.txt");
}

/**

@brief Manager class constructor.
This is the constructor for the Manager class.
It initializes the Manager object.
*/
Manager::Manager()
{
// Constructor code
}
/**

@brief Get the data_list object.
This function returns a reference to the data_list object.
It allows access to the data_list object from outside the Manager class.
@return Reference to the data_list object.
*/
data_list &Manager::getDataList()
{
return _dataList;
}