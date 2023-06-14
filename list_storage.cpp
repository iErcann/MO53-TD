/**
 * @file list_storage.h
 * @brief Implementation of the list_storage class.
 */

#include "list_storage.h"
#include <stdexcept>
#include <iostream>

list_storage::list_storage(const list_storage &other)
{
    /**
     * @brief Copy constructor for list_storage.
     * @param other The list_storage object to be copied.
     */

    shared_ptr<list_element> ptr(other._head);
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

list_storage &list_storage::operator=(const list_storage &other)
{
    /**
     * @brief Assignment operator for list_storage.
     * @param other The list_storage object to be assigned.
     * @return A reference to the assigned list_storage object.
     */

    if (this == &other)
        return *this;

    clear();

    shared_ptr<list_element> ptr = other._head;
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }

    return *this;
}

void list_storage::clear()
{
    /**
     * @brief Clears the list_storage object.
     */

    _head = nullptr;
    _tail = nullptr;
}

void list_storage::push_back(double v)
{
    /**
     * @brief Adds an element to the end of the list_storage.
     * @param v The value of the element to be added.
     */

    if (!_head)
    {
        std::cout << "head" << std::endl;
        _head = make_shared<list_element>(v);
        _tail = _head;
    }
    else
    {
        shared_ptr<list_element> new_element = make_shared<list_element>(v);
        new_element->set_prev(_tail);
        _tail->set_next(new_element);
        _tail = new_element;
    }
}

double list_storage::pop_element()
{
    /**
     * @brief Removes and returns the first element from the list_storage.
     * @return The value of the removed element.
     * @throw std::out_of_range if the list_storage is empty.
     */

    if (!_head)
    {
        throw std::out_of_range("storage empty");
    }

    double return_value = _head->get_value();
    _head = _head->get_next();
    if (_head)
    {
        _head->set_prev(nullptr);
    }
    else
    {
        _tail = nullptr;
    }

    return return_value;
}

int list_storage::size() const
{
    /**
     * @brief Gets the number of elements in the list_storage.
     * @return The number of elements in the list_storage.
     */

    int count = 0;
    shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        count++;
        ptr = ptr->get_next();
    }
    return count;
}

double list_storage::get_element(int position) const
{
    /**
     * @brief Gets the value of the element at the specified position.
     * @param position The position of the element.
     * @return The value of the element.
     * @throw std::out_of_range if the position is out of range.
     */

    if (!_head)
    {
        throw std::out_of_range("List is empty");
    }

    if (position < 0 || position >= size())
    {
        throw std::out_of_range("Position is out of range");
    }

    int count = 0;
    shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        if (count == position)
        {
            return ptr->get_value();
        }
        ptr = ptr->get_next();
        count++;
    }

    throw std::out_of_range("Out of range");
}

void list_storage::sort_storage(bool ascending)
{
    /**
     * @brief Sorts the list_storage in ascending or descending order.
     * @param ascending Flag indicating whether to sort in ascending order or not.
     */

    shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        shared_ptr<list_element> min_element = ptr;
        shared_ptr<list_element> cursor = ptr->get_next();
        while (cursor)
        {
            if (ascending)
            {
                if (cursor->get_value() < min_element->get_value())
                {
                    min_element = cursor;
                }
            }
            else
            {
                if (cursor->get_value() > min_element->get_value())
                {
                    min_element = cursor;
                }
            }
            cursor = cursor->get_next();
        }

        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);

        ptr = ptr->get_next();
    }
}
