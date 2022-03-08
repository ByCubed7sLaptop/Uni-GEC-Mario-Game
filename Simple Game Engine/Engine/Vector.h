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
        Vector() : Object("Vector") { _contents = std::array<T, N>({ 0 }); }
        //Vector(T value[N]);
        //Vector(std::array<T, N> value);
        Vector(std::initializer_list<T> value) : Object("Vector") { std::copy(std::begin(value), std::end(value), std::begin(_contents)); }

        // - Functionallities

        // Gets the size of the Vector
        constexpr size_t Size() { return N; }

        // Verbose functions
        constexpr T Get(int index) { return _contents.at(index); }
        constexpr T GetX() { return _contents[0]; }
        constexpr T GetY() { return _contents[1]; }
        constexpr T GetZ() { return _contents[2]; }
        constexpr T GetW() { return _contents[3]; }

        template<int newN>
        Vector<T, newN> Resize(int filler = 0) {
            Vector<T, newN> newVector = Vector<T, newN>();
            for (int i = 0; i < newN; i++) {
                newVector._contents[i] = _contents.size() < i ? _contents[i] : filler;
            }
            return newVector;
        }

        // Assignments and Opperators

        // Prefix increment
        Vector<T, N>& operator++()
        {
            for (T& value : _contents) value++; // Increment
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
            for (T& value : _contents) value--; // Deincrement
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
        Vector<T, N> operator+(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] + other._contents[i];
            return newVector;
        }

        // Adding
        Vector<T, N> operator+=(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] = other._contents[i];
            return *this;
        }

        // Subtracting
        Vector<T, N> operator-(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] - other._contents[i];
            return newVector;
        }

        // Subtracting
        Vector<T, N> operator-=(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] -= other._contents[i];
            return *this;
        }

        // Multiplying
        Vector<T, N> operator*(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other._contents[i];
            return *this;
        }


        // Ints
        Vector<T, N> operator*(const int& other)
        {
            Vector<T, N> multiVector = Vector<T, N>();
            for (int i = 0; i < N; i++) multiVector._contents[i] = _contents[i] * other;
            return multiVector;
        }

        Vector<T, N> operator*=(const int& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other;
            return *this;
        }

        // Floats
        Vector<T, N> operator*(const float& other)
        {
            Vector<T, N> multiVector = Vector<T, N>();
            for (int i = 0; i < N; i++) multiVector._contents[i] = _contents[i] * other;
            return multiVector;
        }

        Vector<T, N> operator*=(const float& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other;
            return *this;
        }

        std::array<T, N> _contents;
    private:
    };
}
