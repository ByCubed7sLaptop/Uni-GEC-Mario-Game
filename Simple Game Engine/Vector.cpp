#include "Vector.h"

#include <algorithm>

namespace Core {

    // Contructors

    template<class T, int N>
    Vector<T, N>::Vector(T value[N]) { std::copy(std::begin(value), std::end(value), std::begin(contents)); }

    template<class T, int N>
    Vector<T, N>::Vector(std::array<T, N> value) { contents = value; }
    
    // Methods

    template<class T, int N>
    size_t Vector<T, N>::Size()
    {
        return N;
    }

    template<class T, int N>
    T Vector<T, N>::Get(int index)
    {
        return contents[index];
    }

    // Verbose functions
    template<class T, int N> T Vector<T, N>::GetX() { return Get(0); }
    template<class T, int N> T Vector<T, N>::GetY() { return Get(1); }
    template<class T, int N> T Vector<T, N>::GetZ() { return Get(2); }
    template<class T, int N> T Vector<T, N>::GetW() { return Get(3); }
}