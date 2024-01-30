#ifndef RB_SET_H
#define RB_SET_H

#include <iostream>
#include <utility>
#include <RB_TREE.h>
#include <RB_MAP.h>

template <typename KeyType>
class Set : public rb_map <KeyType, char>
{
public:
    using rb_map <KeyType, char>::rb_map;
};

#endif // RB_SET_H
