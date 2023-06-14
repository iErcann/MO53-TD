/**

@file storage_type.h
@brief Defines the abstract base class for storage types.
The storage_type class provides a common interface for different types of storage.
It defines pure virtual functions for manipulating and accessing elements in the storage.
*/
#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

/**

@class storage_type

@brief Abstract base class for storage types.

The storage_type class defines a common interface for different types of storage.

It provides pure virtual functions for manipulating and accessing elements in the storage.
/
class storage_type
{
public:
/*

@brief Default constructor.
*/
storage_type(){};
/**

@brief Copy constructor.
@param storage The storage object to be copied.
*/
storage_type(const storage_type &storage){};
/**

@brief Assignment operator.
@param storage The storage object to be assigned.
@return Reference to the assigned storage object.
*/
storage_type &operator=(const storage_type &storage) { return *this; };
/**

@brief Virtual destructor.
*/
virtual ~storage_type(){};
/**

@brief Add an element to the end of the storage.
@param d The element to be added.
*/
virtual void push_back(const double d) = 0;
/**

@brief Get the element at the specified position in the storage.
@param position The position of the element to retrieve.
@return The element at the specified position.
*/
virtual double get_element(const int position) const = 0;
/**

@brief Remove and return the last element in the storage.
@return The last element in the storage.
*/
virtual double pop_element() = 0;
/**

@brief Remove all elements from the storage.
*/
virtual void clear() = 0;
/**

@brief Get the number of elements in the storage.
@return The number of elements in the storage.
*/
virtual int size() const = 0;
/**

@brief Sort the elements in the storage.
@param ascending Flag indicating whether to sort in ascending order (true) or descending order (false).
*/
virtual void sort_storage(const bool ascending) = 0;
};
#endif // STORAGE_TYPE_H