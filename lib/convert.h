#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
bool convertValue(const std::string & buffer, T & value)
{
	stringstream ss;
	ss << buffer;
	if (ss >> value)
	{
		return true;
	}

	return false;
}


#endif
