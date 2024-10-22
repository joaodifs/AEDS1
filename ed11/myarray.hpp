#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

#include "io.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
template <typename T>

class Array
{
private:
    T optional;
    int length;
    T *data;

public:
    Array(int n, T initial)
    {

        optional = initial;
        length = 0;
        data = nullptr;

        if (n > 0)
        {
            length = n;
            data = new T[length];
        }
    }
    void free()
    {
        if (data != nullptr)
        {
            delete (data);
            data = nullptr;
        }
    }
    void set(int position, T value)
    {
        if (0 <= position && position < length)
        {
            data[position] = value;
        }
    }
    T get(int position)
    {
        T value = optional;
        if (0 <= position && position < length)
        {
            value = data[position];
        }
        return (value);
    }
    void print()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : "
                 << setw(9) << data[x]
                 << endl;
        }
        cout << endl;
    }
    const int getLength()
    {
        return (length);
    }
    T &operator[](const int position)
    {
        static T value = optional;
        if (position < 0 || length <= position)
        {
            cout << endl
                 << "\nERROR: Invalid position.\n"
                 << endl;
        }
        else
        {
            value = data[position];
        }
        return (value);
    }

    Array &operator+(const Array<T> other)
    {
        static Array<T> result(other);
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            for (int x = 0; x < this->length; x = x + 1)
            {
                result.data[x] = result.data[x] + this->data[x];
            }
        }
        return (result);
    }

    bool operator==(const Array<T> other)
    {
        bool result = false;
        int x = 0;
        if (other.length == 0 || length != other.length)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            result = true;
            while (x < this->length && result)
            {
                result = result && (data[x] == other.data[x]);
                x = x + 1;
            }
        }
        return (result);
    }

    Array &operator=(const Array<T> other)
    {
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            this->length = other.length;
            this->data = new T[other.length];
            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other.data[x];
            }
        }
        return (*this);
    }

    Array(const Array &other)
    {
        if (other.length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {

            length = other.length;

            data = new T[other.length];

            for (int x = 0; x < length; x = x + 1)
            {
                data[x] = other.data[x];
            }
        }
    }

    Array()
    {

        length = 0;

        data = nullptr;
    }

    Array(int length, int other[])
    {
        if (length <= 0)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {

            this->length = length;

            data = new T[this->length];

            for (int x = 0; x < this->length; x = x + 1)
            {
                data[x] = other[x];
            }
        }
    }
    void fread(string fileName)
    {
        ifstream afile;
        int n = 0;
        afile.open(fileName);
        afile >> n;
        if (n <= 0)
        {
            cout << "\nERROR: Invalid length.\n"
                 << endl;
        }
        else
        {

            length = n;

            data = new T[n];

            for (int x = 0; x < length; x = x + 1)
            {
                afile >> data[x];
            }
        }
        afile.close();
    }
    void read()
    {
        cout << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            cout << setw(3) << x << " : ";
            cin >> data[x];
        }
        cout << endl;
    }
    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << length << endl;
        for (int x = 0; x < length; x = x + 1)
        {
            afile << data[x] << endl;
        }
        afile.close();
    }
};
#endif
