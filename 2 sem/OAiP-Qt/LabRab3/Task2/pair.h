#ifndef PAIR_H
#define PAIR_H
#include <QVector>
template<class T1,class T2>
struct pair{
    T1 first{};
    T2 second{};
    pair(){};
    pair(T1 const& x,T2 const& y) : first(x), second(y){};
    pair(const pair<T1,T2>& p)
        : first(p.first),second(p.second) {};

    void operator=(const pair& other){
        first = other.first;
        second = other.second;
    }

    void swap(pair& other) noexcept{
        pair<T1, T2> tmp(*this);
        *this = other;
        other = tmp;
    }

    bool operator>(const pair& other){
        if (this->first == other.first) {
            return this->second > other.second;
        }
        return this->first > other.first;
    }

    bool operator<(const pair& other){
        if (this->first == other.first) {
            return this->second < other.second;
        }
        return this->first > other.first;
    }

    bool operator>=(const pair& other){
        if (this->first == other.first) {
            return this->second > other.second;
        }
        return this->first >= other.first;
    }

    bool operator<=(const pair& other){
        if (this->first == other.first) {
            return this->second > other.second;
        }
        return this->first <= other.first;
    }
};

template<class T1,class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        return true;
    }
    return false;
};

template<class T1,class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs){
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        return false;
    }
    return true;
};

template<class T1,class T2>
pair<T1, T2>& make_pair(T1 lhs, T2 rhs){
    return *(new pair<T1, T2>(lhs, rhs));

}
#endif // PAIR_H
