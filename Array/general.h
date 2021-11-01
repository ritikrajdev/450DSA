#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (auto elm: vec)
		os << elm << " ";

	return os;
}


template <typename T>
std::istream& operator<<(std::istream& is, const std::vector<T>& vec) {
	for (auto elm: vec)
		is >> elm >> " ";

	return is;
}

template <typename T>
bool operator==(const std::vector<T>& vec1, const std::vector<T>& vec2) {
	int size = vec1.size();

	if (size != vec2.size())
		return false;

	for (int i = size-1; i >= 0; i--) {
		if (vec1[i] != vec2[i])
			return false;
	}

	return true;
}

#endif // GENERAL_H
