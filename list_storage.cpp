#include "list_storage.h"
#include <stdexcept>
#include <iostream>

list_storage::list_storage(const list_storage &other)
{
    shared_ptr<list_element> ptr(other._head);
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
    _head = nullptr;
    _tail = nullptr;
}

void list_storage::push_back(double v)
{
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
    if (!_head)
    {
        throw out_of_range("storage empty");
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
    if (!_head)
    {
        throw out_of_range("List is empty");
    }

    if (position < 0 || position >= size())
    {
        throw out_of_range("Position is out of range");
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

    throw out_of_range("Out of range");
}

void list_storage::sort_storage(bool ascending)
{
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
