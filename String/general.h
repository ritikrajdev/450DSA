#pragma once

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (auto elm: vec)
		os << elm << " ";

	return os;
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pr) {
	os << "(" << pr.first << "," << pr.second << ")";
	return os;
}

