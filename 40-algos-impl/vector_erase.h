#pragma once
#include <algorithm>

template<typename T>
void vector_erase(T & vect, const typename T::value_type & value)
{
    vect.erase(std::remove(vect.begin(), vect.end(), value), vect.end());
}
