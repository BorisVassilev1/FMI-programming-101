#pragma once
#include "vector.hpp"

template <class T>
class set : public vector<T> {
   private:
	using vector<T>::push;
    using vector<T>::insert;
	using vector<T>::substr;
	using vector<T>::operator[];
	using vector<T>::operator<=>;
	using vector<T>::operator T*;
    
   public:
	void insert(const T& elem);
};

template<class T>
void set<T>::insert(const T& elem) {
    if(this->size() == 0) {
        insert(elem, 0);
        return;
    }
    unsigned i = 0;
    while((*this)[i] < elem) {
        ++ i;
    }
    vector<T>::insert(elem, i);
}