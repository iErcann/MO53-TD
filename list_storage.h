#ifndef LIST_STORAGE_H
#define LIST_STORAGE_H

#include "storage_type.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

class list_element
{
    double _value;
    shared_ptr<list_element> _prev;
    shared_ptr<list_element> _next;

public:
    list_element(double v = 0.0, shared_ptr<list_element> p = nullptr, shared_ptr<list_element> n = nullptr) : _value(v), _prev(p), _next(n) {}
    ~list_element() {}

    shared_ptr<list_element> get_next() { return _next; }
    void set_next(shared_ptr<list_element> n) { _next = n; }

    shared_ptr<list_element> get_prev() { return _prev; }
    void set_prev(shared_ptr<list_element> n) { _prev = n; }

    double get_value() const { return _value; }
    void set_value(double v) { _value = v; }
};

class list_storage : public storage_type
{
private:
    shared_ptr<list_element> _head;
    shared_ptr<list_element> _tail;

public:
    list_storage(){};
    list_storage(const list_storage &storage);
    list_storage &operator=(const list_storage &storage);
    /**
     * Virtual destructor
     */
    virtual ~list_storage() override{};

    void push_back(const double d);
    double get_element(const int position) const;
    double pop_element();
    void clear();
    int size() const;
    void sort_storage(const bool ascending);
};

#endif // LIST_STORAGE_H
