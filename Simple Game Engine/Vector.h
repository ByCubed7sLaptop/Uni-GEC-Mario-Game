#pragma once

#include <array>

#include "Object.h"

// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

namespace Core {

    template<class T, int N>
    class Vector : public Object
    {
    public:
        
        // - Contructors
        Vector(T value[N]);
        Vector(std::array<T, N> value);

        // - Functionallities

        // Gets the size of the Vector
        size_t Size();

        // values
        T Get(int index);

        T GetX();
        T GetY();
        T GetZ();
        T GetW();

    private:
        std::array<T, N> contents;
    };
}
