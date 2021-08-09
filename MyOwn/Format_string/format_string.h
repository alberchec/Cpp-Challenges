#ifndef FORMAT_STRING
#define FORMAT_STRING

#include <iostream>

void format_string(std::string& s, std::string first){
	int pos = s.find("{}");
	if(pos != -1){
		s.replace(pos,2,first);
	}
}

template<typename...strs>
void format_string(std::string& s, std::string first, strs...rest){
	format_string(s,first);
	format_string(s,rest...);
}

#endif