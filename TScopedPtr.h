#ifndef MODUL2_LAB9_TSCOPEDPTR_H
#define MODUL2_LAB9_TSCOPEDPTR_H

#include <iostream>

template<class T>
class TScopedPtr
{
private:
    T* myPointer;

public:
    TScopedPtr(TScopedPtr const &) = delete;
    TScopedPtr & operator=(TScopedPtr const &) = delete;

    explicit TScopedPtr(T * p = nullptr)
    {
        myPointer = p;
    }

    ~TScopedPtr()
    {
        delete myPointer;
    }

    void reset(T * p = nullptr)
    {
        myPointer = p;
    }

    T & operator*() const
    {
        return *myPointer;
    }

    T * operator->() const
    {
        return myPointer;
    }

    T * get() const throw()
    {
        return myPointer;
    }

    void swap(TScopedPtr & b) throw()
    {
        std::swap(myPointer,b.myPointer);
    }

    bool operator! () const throw()
    {
        return !bool();
    }

    explicit operator bool() const throw()
    {
        return myPointer == 0;
    }
};

template<class T>
inline bool operator==(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
    return bool(p);
}

template<class T>
inline bool operator==(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
    return bool(p);
}

template<class T>
inline bool operator!=(TScopedPtr<T> const & p, std::nullptr_t) throw()
{
    return !(p);
}

template<class T>
inline bool operator!=(std::nullptr_t, TScopedPtr<T> const & p) throw()
{
    return !(p);
}

template<class T>
inline void swap(TScopedPtr<T> & a, TScopedPtr<T> & b) throw()
{
    a.swap(b);
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T * get_pointer(TScopedPtr<T> const & p) throw()
{
    return p.get();
}


#endif //MODUL2_LAB9_TSCOPEDPTR_H
