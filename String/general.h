#pragma once

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	for (auto elm: vec)
		os << elm << " ";

	return os;
}

