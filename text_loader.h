/**

@file text_loader.h
@brief This file contains the definition of the text_loader class.
*/
#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>

/**

@class text_loader

@brief A class that represents a text loader.

This class inherits from the loader base class and is responsible for loading text data

into a storage_type object.
/
class text_loader : public loader
{
public:
/*

@brief Default constructor.
Initializes the text_loader with the default filename "texte.txt".
*/
text_loader() : loader("texte.txt"){}
/**

@brief Constructor with filename parameter.
Initializes the text_loader with the specified filename.
@param s The filename to load.
*/
text_loader(const string &s) : loader(s){};
/**

@brief Destructor.
*/
virtual ~text_loader() {}
/**

@brief Loads text data into a storage_type object.
@param storage The storage_type object to load the data into.
@return A reference to the loaded storage_type object.
*/
storage_type &load(storage_type &storage);
};
#endif // TEXT_LOADER_H