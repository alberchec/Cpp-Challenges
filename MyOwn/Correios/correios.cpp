#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
using namespace std;

void parse_correios(string name){
	string s,parse;

	ifstream input("track.html");

	while(getline(input, s) ){
		if(s.find("<ul class=\"linha_status m-0\" style=\"border-bottom: 0;\"  style=\"\">") != -1){
			goto parse_html;
		}
	}
	cout << "\nObjeto nao disponivel para rastreamento!\n\n";
	return;

	parse_html:
	while(getline(input,s) ){
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
	cout << name << endl;

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
}

int main(){

	try{

		string s;
		vector<vector<string> > v;

		ifstream input("track_numbers.txt");
		if(!input.is_open() ){
			throw invalid_argument("There aren't available packages for tracking!");
		}

		while(getline(input,s) ){
			string key,name;
			vector<string> v_temp;
			int pos;
			if(s.find(" - ") == -1) throw invalid_argument("File track_numbers.txt is corrupted!");
			pos = s.find(" - ");
			key = s.substr(0,pos);
			name = s.substr(pos + 3);
			v_temp.push_back(key);
			v_temp.push_back(name);
			v.push_back(v_temp);
		}
		input.close();

		if (system(NULL)){}
    	else throw invalid_argument("Unable to access system!");

    	for(int i=0;i<v.size();i++){
    		string cmd_string = "curl https://www.linkcorreios.com.br/ -s > track.html";
    		cmd_string.insert(37,v[i][0]);
    		const char* cmd = cmd_string.c_str();
    		system(cmd);
			parse_correios(v[i][1]);
    	}


	}catch(exception& e){
		cout << "Exception: " << e.what() << endl;
	}
	



	return 0;
}