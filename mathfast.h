#ifndef _MATHFAST_H
#define _MATHFAST_H

#include <stdint.h>
#include <math.h>
#include <list>
#include <string>

using namespace std;

std::list<uint16_t> get_multipliers(long value)
{
    if(!value)
        return std::list<uint16_t>();
    std::list<uint16_t> lst;
    long divide = 2;
    ldiv_t delta;
    delta.quot = value;
    while (delta.quot != 1)
    {
        do
        {
            delta = ldiv((long)value, (long)divide);
            if (delta.rem)
            {
                divide+=delta.rem;
            }
            else
            {
                value = delta.quot;
                break;
            }
        } while (true);
        lst.push_back(divide);
    }
    return lst;
}

size_t NOD(long lhs, long rhs) throw()
{
	if(lhs==rhs)
	return lhs;
	
    //todo: Оптимизировать O(n2) нужен O(n)
    size_t result = 1;
    auto lstLhs = get_multipliers(lhs);
    auto lstRhs = get_multipliers(rhs);

    for (auto i = lstLhs.begin(); i != lstLhs.end(); ++i)
        for (auto j = lstRhs.begin(); j != lstRhs.end(); ++j)
            if (*i == *j)
            {
                result *= *i;
                lstRhs.erase(j);
                break;
            }
    return result;
}

size_t NOK(long lhs, long rhs) throw()
{
	if(lhs==rhs)
	return lhs;
    
    //todo: Оптимизировать O(n2) нужен O(n)
    size_t result = lhs;
    auto lstLhs = get_multipliers(lhs);
    auto lstRhs = get_multipliers(rhs);

    for (auto i = lstLhs.begin(); i != lstLhs.end(); ++i)
        for (auto j = lstRhs.begin(); j != lstRhs.end(); ++j)
            if (*i != *j)
            {
                result *= *j;
                lstRhs.erase(j);
                break;
            }
    return result;
}

const string dec2hex(int number) {
	int size = sizeof(number);
	int h;
	string cat(size * 2, '0');
	while (--size > ~0) {
		h = ((uint8_t*)&number)[size] & 0xf;
		if (h)
		{
			if (h < 10)
				cat[size * 2] = '0' + h;
			else
				cat[size * 2] = 'a' + h - 10;
		}
		h = ((uint8_t*)&number)[size] >> 0x4;
		if (h)
		{
			if (h < 10)
				cat[size * 2 + 1] = '0' + h;
			else
				cat[size * 2 + 1] = 'a' + h - 10;
		}
	}
	return cat;
}

/*
void simpleAndCompound(size_t range, ref List<uint> simples, ref List<uint> compounds)
{

        simples.Clear();
        compounds.Clear();

        if (range < 2)
                return;
        bool[] matrix = new bool[range - 2];
        uint i, x;
        for (i = 2; i < range; ++i)
        {
                for (x = i + 1; x < range; ++x)
                {
                        if (matrix[x - 2])
                                continue;

                        matrix[x - 2] = x % i == 0; // если mod == 0 то составные числа
                }
        }
        //сборка
        for (i = 0; i < matrix.Length; ++i)
        {
                if (matrix[i])
                        //собираем составные числа
                        compounds.Add(i + 2);
                else
                        // собираем простые числа
                        simples.Add(i + 2);
        }
}


class Simples
{
public:
        static size_t* __simples;

        static size_t size() noexcept
        {
                return __simples ? _msize(__simples) / sizeof(size_t) : 0;
        }

        static void simple_resize(size_t _size)
        {
                size_t x, y, i;
                size_t _lastSize;
                size_t* p;
                char shift;
                size_t Xsize = 0;

                if (!size() || get_max_simpleReq() < _size)
                {
                        unsigned char* matrix = (unsigned char*)malloc((8 + _size) / 8);
                        _lastSize = size();
                        Xsize = 0;

                        if (matrix == NULL)
                                exit(-1);

                        memset(matrix, 0, _msize(matrix));
                        //TODO: Сделать при _lastSize < size() оптимизацию пребуфера

                        //TODO: Неправильно вычисляется тут!
                        //Причина: Память повреждается при x = _size-1,
                        // переменная matrix остались нулевые биты которые не были вычислены
                        // также, они подтверждались как правильные простые числа.
                        for (y = 2; y < _size; ++y)
                        {
                                for (x = y + 1; x < _size; ++x)
                                {
                                        i = (8 + x - 3) / 8 - 1;				// column
                                        shift = ((x - 3) % 0x8);		    // row
                                        shift = 1 << shift;
                                        if ((matrix[i] & shift))
                                                continue;
                                        // если mod == 0 то составные числа
                                        matrix[i] |= shift * ((x % y) == 0);
                                }
                        }

                        //remained clear
                        //fact mx = 42 binary
                        //sized mx = 234 binary

                        y = (_size - 1);
                        y = y + (y % 8);
                        //i = i; last remained data
                        for (x = _size - 1; x < y; ++x)
                                matrix[i] |= (1 << ((x) % 0x8));

                        for (x = 0; x < _size; ++x)
                                if (!(matrix[(8 + x) / 8 - 1] & (1 << (x % 0x8))))
                                        ++Xsize;

                        if (!__simples)
                                __simples = (size_t*)malloc(sizeof(size_t) * Xsize);
                        else
                                __simples = (size_t*)realloc((void*)__simples, sizeof(size_t) * Xsize);

                        if (!__simples)
                                exit(-1); // exit

                        //memset(__simples, 0, size() * sizeof(uint64_t));

                        //Собираем из уже имеющихся.
                        if (_lastSize)
                        {
                                x = __simples[_lastSize - 1];
                                p = __simples + _lastSize - 1;
                        }
                        else
                        {
                                x = 0;
                                p = __simples;
                        }

                        for (; x < _size; ++x)
                        {
                                // собираем простые числа
                                if (!(matrix[(8 + x) / 8 - 1] & (1 << (x % 0x8))) && x + 3 <= _size)
                                {
                                        *p = x + 3;
                                        ++p;
                                }
                        }

                        std::free(matrix);
                }
        }

        static size_t get_max_simpleReq() noexcept
        {
                return size() ? __simples[size() - 1] : 0;
        }

        static bool prime(size_t _chNumber)
        {
                if (_chNumber < 2)
                        return false;
                else if (_chNumber == 2)
                        return true;

                size_t x, y, i;
                size_t _lastSize;
                size_t* p;
                size_t m;

                simple_resize(_chNumber);

                //binary search & разделяй и властвуй
                x = 0;
                y = size() - 1;
                while (x <= y)
                {
                        m = (x + y) / 2;
                        p = &__simples[m];
                        if (*p == _chNumber)
                                return true;
                        else if (*p < _chNumber)
                                x = m + 1;
                        else
                                y = m - 1;
                }

                return false;
        }

        static bool is_compound_number(size_t _chNumber)
        {
                if (_chNumber < 2)
                        return false;

                return !prime(_chNumber);
        }

        static void free()
        {
                if (size())
                {
                        _freea(__simples);
                        __simples = nullptr;
                }
        }
};
size_t* Simples::__simples;
*/

#endif
