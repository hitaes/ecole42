#ifndef WHATEVER_H
# define WHATEVER_H

# include <iostream>

template< typename T >
const T &max(const T &l, const T &r)
{
    return (l >= r ? l : r);
}

template< typename U >
const U &min(const U &l, const U &r)
{
    return (l <= r ? l : r);
}

template< typename V >
void swap(V &l, V &r)
{
    V _temp = l;
    l = r;
    r = _temp;
}

#endif