#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

class storage_type
{
public:
    storage_type(){};
    storage_type(const storage_type &storage){};
    storage_type &operator=(const storage_type &storage) { return *this; };
    virtual ~storage_type(){};

    virtual void push_back(const double d) = 0;
    virtual double get_element(const int position) const = 0;
    virtual double pop_element() = 0;
    virtual void clear() = 0;
    virtual int size() const = 0;
    virtual void sort_storage(const bool ascending) = 0;
};

#endif // STORAGE_TYPE_H
