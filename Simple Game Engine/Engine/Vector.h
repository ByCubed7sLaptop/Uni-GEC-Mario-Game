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
        Vector() : Object("Vector"), _contents{ 0 } { _contents = std::array<T, N>({ 0 }); }
        Vector(std::initializer_list<T> value) : Object("Vector"), _contents {0} { std::copy(std::begin(value), std::end(value), std::begin(_contents)); }
        Vector(T value) : Object("Vector"), _contents{ value } { for (int i = 0; i < N; i++) _contents[i] = value; }

        // - Functionallities

        // Gets the size of the Vector
        constexpr size_t Size() { return N; }

        // Verbose functions
        constexpr T Get(int index) { return _contents[index]; }
        constexpr T GetX() { return Get(0); }
        constexpr T GetY() { return Get(1); }
        constexpr T GetZ() { return Get(2); }
        constexpr T GetW() { return Get(3); }

        void Set(int index, T value) { _contents[index] = value; }
        void SetX(T value) { Set(0, value); }
        void SetY(T value) { Set(1, value); }
        void SetZ(T value) { Set(2, value); }
        void SetW(T value) { Set(3, value); }

        void Invert() {
            for (int i = 0; i < N; i++) _contents[i] = -_contents[i];
        }
        void Invert(int index) { return Set(index, -Get(index)); }

        template<int newN>
        constexpr Vector<T, newN> Resize(int filler = 0) {
            Vector<T, newN> newVector = Vector<T, newN>();
            for (int i = 0; i < newN; i++) {
                newVector._contents[i] = _contents.size() > i ? _contents[i] : filler;
            }
            return newVector;
        }

        template<class newT>
        constexpr Vector<newT, N> Cast() {
            Vector<newT, N> newVector = Vector<newT, N>();
            for (int i = 0; i < N; i++) {
                newVector._contents[i] = (newT)_contents[i];
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
        Vector<T, N>& operator+=(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] += other._contents[i];
            return *this;
        }

        // Subtracting
        Vector<T, N>& operator-=(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] -= other._contents[i];
            return *this;
        }

        Vector<T, N>& operator*=(const int& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other;
            return *this;
        }

        Vector<T, N>& operator*=(const float& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other;
            return *this;
        }



        // - Adding
        Vector<T, N> operator+(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] + other._contents[i];
            return newVector;
        }

        // - Subtracting
        Vector<T, N> operator-(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] - other._contents[i];
            return newVector;
        }

        // - Multiplying
        Vector<T, N> operator*(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] * other._contents[i];
            return newVector;
        }

        // Ints
        Vector<T, N> operator*(const int& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] * other;
            return newVector;
        }

        // Floats
        Vector<T, N> operator*(const float& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] * other;
            return newVector;
        }

        // Divide
        Vector<T, N> operator/(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] / other._contents[i];
            return newVector;
        }

        // Divide
        Vector<T, N> operator<(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) newVector._contents[i] = _contents[i] / other._contents[i];
            return newVector;
        }

        // Equal
        Vector<T, N>& operator=(const Vector<T, N>& other)
        {
            Vector<T, N> newVector = Vector<T, N>();
            for (int i = 0; i < N; i++) _contents[i] = other._contents[i];
            return newVector;
        }


        bool operator <(const Vector<T, N>& arg1, const Vector<T, N>& arg2) const
        {
            return arg1.x < arg2.x;
        }

        // *Should* be private, but it's much easier to reference this when it's not-
        std::array<T, N> _contents;
    private:
    };
}
