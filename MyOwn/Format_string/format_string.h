#ifndef FORMAT_STRING
#define FORMAT_STRING

#include <iostream>

void format_string(std::string&,std::string);

template<typename...strs>
void format_string(std::string&,std::string,strs...);

#endif