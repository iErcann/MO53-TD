/**
 * @file list_storage.h
 * @brief Definition of the list_storage class.
 */

#ifndef LIST_STORAGE_H
#define LIST_STORAGE_H

#include <memory>
#include <stdexcept>
#include <iostream>

/**
 * @class list_element
 * @brief Represents an element in the list.
 */
class list_element
{
public:
    /**
     * @brief Constructor for the list_element class.
     * @param v The value of the element.
     */
    list_element(double v) : _value(v), _next(nullptr), _prev(nullptr) {}

    /**
     * @brief Get the value of the element.
     * @return The value of the element.
     */
    double get_value() const { return _value; }

    /**
     * @brief Get the next element.
     * @return A shared pointer to the next element.
     */
    std::shared_ptr<list_element> get_next() const { return _next; }

    /**
     * @brief Set the next element.
     * @param next A shared pointer to the next element.
     */
    void set_next(std::shared_ptr<list_element> next) { _next = next; }

    /**
     * @brief Get the previous element.
     * @return A shared pointer to the previous element.
     */
    std::shared_ptr<list_element> get_prev() const { return _prev; }

    /**
     * @brief Set the previous element.
     * @param prev A shared pointer to the previous element.
     */
    void set_prev(std::shared_ptr<list_element> prev) { _prev = prev; }

private:
    double _value; /**< The value of the element. */
    std::shared_ptr<list_element> _next; /**< A pointer to the next element. */
    std::shared_ptr<list_element> _prev; /**< A pointer to the previous element. */
};

/**
 * @class list_storage
 * @brief Represents a list storage.
 */
class list_storage
{
public:
    /**
     * @brief Constructor for the list_storage class.
     */
    list_storage() : _head(nullptr), _tail(nullptr) {}

    /**
     * @brief Copy constructor for the list_storage class.
     * @param other The list_storage object to copy from.
     */
    list_storage(const list_storage &other);

    /**
     * @brief Assignment operator for the list_storage class.
     * @param other The list_storage object to assign from.
     * @return A reference to the assigned list_storage object.
     */
    list_storage &operator=(const list_storage &other);

    /**
     * @brief Clear the list storage.
     */
    void clear();

    /**
     * @brief Push a value to the back of the list storage.
     * @param v The value to push.
     */
    void push_back(double v);

    /**
     * @brief Pop the first element from the list storage.
     * @return The value of the popped element.
     * @throw std::out_of_range if the list storage is empty.
     */
    double pop_element();

    /**
     * @brief Get the size of the list storage.
     * @return The size of the list storage.
     */
    int size() const;

    /**
     * @brief Get the value of an element at the specified position.
     * @param position The position of the element.
     * @return The value of the element.
     * @throw std::out_of_range if the list is empty or the position is out of range.
     */
    double get_element(int position) const;

    /**
     * @brief Sort the list storage.
     * @param ascending True to sort in ascending order, false to sort in descending order.
     */
    void sort_storage(bool ascending);

private:
    std::shared_ptr<list_element> _head; /**< A pointer to the head of the list. */
    std::shared_ptr<list_element> _tail; /**< A pointer to the tail of the list. */
};

list_storage::list_storage(const list_storage &other)
{
    std::shared_ptr<list_element> ptr(other._head);
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

list_storage &list_storage::operator=(const list_storage &other)
{
    if (this == &other)
        return *this;

    clear();

    std::shared_ptr<list_element> ptr = other._head;
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }

    return *this;
}

void list_storage::clear()
{
    _head = nullptr;
    _tail = nullptr;
}

void list_storage::push_back(double v)
{
    if (!_head)
    {
        std::cout << "head" << std::endl;
        _head = std::make_shared<list_element>(v);
        _tail = _head;
    }
    else
    {
        std::shared_ptr<list_element> new_element = std::make_shared<list_element>(v);
        new_element->set_prev(_tail);
        _tail->set_next(new_element);
        _tail = new_element;
    }
}

double list_storage::pop_element()
{
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
    int count = 0;
    std::shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        count++;
        ptr = ptr->get_next();
    }
    return count;
}

double list_storage::get_element(int position) const
{
    if (!_head)
    {
        throw std::out_of_range("List is empty");
    }

    if (position < 0 || position >= size())
    {
        throw std::out_of_range("Position is out of range");
    }

    int count = 0;
    std::shared_ptr<list_element> ptr = _head;
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
    std::shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        std::shared_ptr<list_element> min_element = ptr;
        std::shared_ptr<list_element> cursor = ptr->get_next();
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

#endif // LIST_STORAGE_H
