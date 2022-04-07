#pragma once

#include "Object.h"

#include <array>
#include <algorithm>
#include <iostream>

// https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

/* https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
* Templated classes and functions are not instantiated until they are used, typically in a separate .cpp file (e.g. the program source). 
* When the template is used, the compiler needs the full code for that function to be able to build the correct function with the appropriate type. 
* However, in this case the code for that function is detailed in the template's source file and hence unavailable.
* - dlanod
*/

// One solution would to be to also include the .cpp file. However, this may send the wrong message.
// TEST: Create a "VectorImple.h" file which includes both .h .cpp files and see if we get an Unresolved External exception

namespace Core {

    template<class T, int N>
    class Vector : public Object
    {
    public:
        
        // - Contructors
        Vector() : Object("Vector"), _contents{ 0 }
        { 
            _contents = std::array<T, N>({ 0 });
        }
        
        Vector(T value) : Object("Vector"), _contents{ value }
        { 
            for (int i = 0; i < N; i++) 
                _contents[i] = value; 
        }

        Vector(std::initializer_list<T> value) : Object("Vector"), _contents{ 0 }
        {
            const T* it = value.begin();
            const T* const end = value.end();

            for (int i = 0; it != end; ++it, ++i) {
                _contents[i] = *it;
            }
            //std::copy(std::begin(value), std::end(value), std::begin(_contents));
        }

        // - Functionallities

        // Gets the size of the Vector
        constexpr size_t Size() { return N; }

        // Verbose functions
        constexpr T& Get(int index) { return _contents[index]; }
        constexpr T& X() { return Get(0); }
        constexpr T& Y() { return Get(1); }
        constexpr T& Z() { return Get(2); }
        constexpr T& W() { return Get(3); }

        // Const Verbose functions
        constexpr const T& Get(int index) const { return _contents[index]; }
        constexpr const T& X() const { return Get(0); }
        constexpr const T& Y() const { return Get(1); }
        constexpr const T& Z() const { return Get(2); }
        constexpr const T& W() const { return Get(3); }


        // https://stackoverflow.com/questions/856542/elegant-solution-to-duplicate-const-and-non-const-getters
        //const T& get(int index) const
        //{
        //    //non-trivial work
        //    return _contents[index];
        //}

        //int& get(int index)
        //{
        //    return const_cast<T&>(const_cast<const Vector*>(this)->get(index));
        //}

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

        template<int A, int B>
        static Vector<T, A+B> Append(Vector<T, A> first, Vector<T, B> second) {
            Vector<T, A + B> newVector = Vector<T, A + B>();

            for (int i = 0; i < A; i++)
                newVector._contents[i] = first._contents[i];

            for (int i = 0; i < B; i++)
                newVector._contents[A+i] = second._contents[i];

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

        // Multiplying
        Vector<T, N>& operator*=(const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) _contents[i] *= other._contents[i];
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

        // Equal
        //Vector<T, N>& operator=(const Vector<T, N>& other)
        //{
        //    Vector<T, N> newVector = Vector<T, N>();
        //    for (int i = 0; i < N; i++) _contents[i] = other._contents[i];
        //    return newVector;
        //}


        bool operator< (const Vector<T, N>& other) const
        {
            for (int i = 0; i < N; i++)
            {
                if (_contents[i] < other._contents[i]) return true;
                if (_contents[i] == other._contents[i]) continue;
                return false;
            }
            return false;
        }
        bool operator> (const Vector<T, N>& other) const
        {
            for (int i = 0; i < N; i++)
            {
                if (_contents[i] > other._contents[i]) return true;
                if (_contents[i] == other._contents[i]) continue;
                return false;
            }
            return false;
        }

        // Casting to string

        operator std::string() {
            std::string string;

            for (int i = 0; i < N; i++) {
                string += std::to_string(_contents[i]);
                if (i != N - 1) string += ", ";
            }

            return string;
        }

        friend std::ostream& operator<< (std::ostream& os, const Vector<T, N>& other)
        {
            for (int i = 0; i < N; i++) {
                os << std::to_string(other._contents[i]);
                if (i != N - 1) os << ", ";
            }
            return os;
        }

        /*std::string operator<< (const std::string& other) const
        {
            return other + operator std::string();
        }*/


        // *Should* be private, but it's much easier to reference this when it's not-
        std::array<T, N> _contents;
        T x; T y; T z; T w;
    private:
    };
}
