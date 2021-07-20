#include <iostream>
#include <vector>
using namespace std;

int main(){
	string s,parse;

	while(getline(cin, s) ){
		if(s.find("<ul class=\"linha_status m-0\" style=\"border-bottom: 0;\"  style=\"\">") != -1){
			goto parse_html;
		}
	}
	cout << "\nObjeto nao disponivel para rastreamento!\n\n";
	return 1;

	parse_html:
	while(getline(cin,s) ){
		parse += s + '\n';
		if(s.find("</ul>") != -1) break;
	}

	vector<string> v;

	while(parse.find("<li>") != -1 ){
		int pos1,pos2;
		pos1 = parse.find("<li>");
		pos2 = parse.find("</li>");
		
		string temp;
		temp = parse.substr(pos1 + 4,pos2 - pos1 -4);
		parse = parse.substr(pos2 + 5);
		v.push_back(temp);
	}

	cout << "\n//-----------------------------------------//\n";

	for(int i=0;i<v.size();i++){
		while(v[i].find('<') != -1){
			int pos1,pos2;
			pos1 = v[i].find('<');
			pos2 = v[i].find('>');
			v[i].erase(pos1,pos2 - pos1 + 1);
		}

		cout << v[i] << endl;
	}

	cout << "//-----------------------------------------//\n\n";

	return 0;
}