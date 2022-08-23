#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(long long count);
    Vector(long long count, T initialValue);
    Vector(Vector &v);
    ~Vector();

    auto Front() const -> T &;
    auto Back() const -> T &;
    auto Data() const -> T *;
    auto Size() const -> long long;
    auto MaxSize() const -> long long;

    auto Fit() -> void;
    auto Resize(const long long count) -> void;
    auto Get(const long long index) const -> T &;
    auto Set(const long long index, T value) -> void;
    auto PushBack(T value) -> void;
    auto PopBack() -> void;
    auto Insert(const long long index, T value) -> void;

private:
    T *array;
    long long size;
    long long maxSize;
};

template <typename T>
Vector<T>::Vector() : Vector(1) {}
template <typename T>
Vector<T>::Vector(long long size) : size{size}, maxSize{size}
{
    array = new T[maxSize];
}
template <typename T>
Vector<T>::Vector(long long size, T initialValue) : Vector(size)
{
    for (long long i = 0; i < size; i++)
        array[i] = initialValue;
}
template <typename T>
Vector<T>::Vector(Vector &v) : Vector(v.Size())
{
    for (long long i = 0; i < v.Size(); i++)
        array[i] = v.Get(i);
}
template <typename T>
Vector<T>::~Vector()
{
    delete[] array;
}

template <typename T>
auto Vector<T>::Front() const -> T &
{
    return array[0];
}
template <typename T>
auto Vector<T>::Back() const -> T &
{
    return array[size];
}
template <typename T>
auto Vector<T>::Data() const -> T *
{
    return array;
}
template <typename T>
auto Vector<T>::Size() const -> long long
{
    return size;
}
template <typename T>
auto Vector<T>::MaxSize() const -> long long
{
    return maxSize;
}

template <typename T>
auto Vector<T>::Fit() -> void
{
    T *newArray = new T[size];
    for (long long i = 0; i < size; ++i)
        newArray[i] = array[i];
    delete[] array;
    array = newArray;
    maxSize = size;
}
template <typename T>
auto Vector<T>::Get(const long long index) const -> T &
{
    return array[index];
}
template <typename T>
auto Vector<T>::Set(const long long index, T value) -> void
{
    array[index] = value;
}
template <typename T>
auto Vector<T>::PushBack(T value) -> void
{
    if (size == maxSize)
    {
        T *newArray = new T[maxSize * 2];

        for (long long i = 0; i < size; ++i)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
        maxSize *= 2;
    }
    array[size] = value;
    ++size;
}
template <typename T>
auto Vector<T>::Insert(const long long index, T value) -> void
{
    if (size < maxSize)
    {
        for (long long i = 0; i < size + 1; ++i)
        {
            if (i < index)
                continue;
            std::swap(array[i], array[index]);
        }
    }
    else
    {
        T *newArray = new T[maxSize * 2];

        long long dash = 0;
        for (long long i = 0; i < size + 1; ++i)
        {
            if (i == index)
                ++dash;
            newArray[i + dash] = array[i];
        }
        delete[] array;
        array = newArray;
        maxSize *= 2;
    }
    array[index] = value;
    ++size;
}
template <typename T>
auto Vector<T>::PopBack() -> void
{
    size -= 1;
}

template <typename T>
auto operator<<(std::ostream &out, const Vector<T> &v) -> std::ostream &
{
    out << '[';
    for (long long i = 0; i < v.Size(); i++)
    {
        out << v.Get(i);
        if (i != v.Size() - 1)
            out << ", ";
    }
    out << "]\t<size=" << v.Size() << ", maxSize=" << v.MaxSize() << ">";
    return out;
}

#endif