#pragma once

#include "Object.h"

#include <array>
#include <algorithm>

// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

/* https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
* Templated classes and functions are not instantiated until they are used, typically in a separate .cpp file (e.g. the program source). 
* When the template is used, the compiler needs the full code for that function to be able to build the correct function with the appropriate type. 
* However, in this case the code for that function is detailed in the template's source file and hence unavailable.
 - dlanod
*/

// One solution would to be to also include the .cpp file. However, this may send the wrong message.
// TEST: Create a "VectorImple.h" file which includes both .h .cpp files and see if we get an Unresolved External exception

namespace Core {

    template<class T, int N>
    class Vector : public Object
    {
    public:
        
        // - Contructors
        Vector() : Object("Vector") { contents = std::array<T, N>({ 0 }); }
        //Vector(T value[N]);
        //Vector(std::array<T, N> value);
        Vector(std::initializer_list<T> value) : Object("Vector") { std::copy(std::begin(value), std::end(value), std::begin(contents)); }

        // - Functionallities

        // Gets the size of the Vector
        constexpr size_t Size() { return N; }

        // Verbose functions
        constexpr T Get(int index) { return contents[index]; }
        constexpr T GetX() { return Get(0); }
        constexpr T GetY() { return Get(1); }
        constexpr T GetZ() { return Get(2); }
        constexpr T GetW() { return Get(3); }

        // Assignments and Opperators

        // Prefix increment
        Vector<T, N>& operator++()
        {
            for (T& value : contents) value++; // Increment
            return *this; // return by reference
        }

        // Postfix increment
        Vector<T, N> operator++(int)
        {
            Vector<T, N> old = *this; // copy old value
            operator++();  // prefix
            return old;    // return old value
        }

        // Prefix decrement
        Vector<T, N>& operator--()
        {
            for (T& value : contents) value--; // Deincrement
            return *this; // return by reference
        }

        // Postfix decrement
        Vector<T, N> operator--(int)
        {
            Vector<T, N> old = *this; // copy old value
            operator--();  // prefix
            return old;    // return old value
        }

        // Adding
        Vector<T, N> operator+(const Vector<T, N>& otherVector) 
        {
            for (int i = 0; i < N; i++) contents[i] += otherVector.Get(i);
            return *this;
        }

        // Subtracting
        Vector<T, N> operator-(const Vector<T, N>& otherVector) 
        {
            for (int i = 0; i < N; i++) contents[i] -= otherVector.Get(i);
            return *this;
        }

    private:
        std::array<T, N> contents;
    };
}
