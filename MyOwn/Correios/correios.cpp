#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

#define temp_file "/your_path/track.html"
#define track_numbers_file "/your_path/track_numbers.txt"

void parse_correios(string name){
	string s,parse;

	ifstream input(temp_file);

	while(getline(input, s) ){
		if(s.find("<ul class=\"linha_status m-0\" style=\"border-bottom: 0;\"  style=\"\">") != -1){
			goto parse_html;
		}
	}
	cout << "\nPackage isn't available for tracking!\n\n";
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

	cout << "\n//---------------------------------------------------//\n";
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

	cout << "//---------------------------------------------------//\n\n";
}

void main_program(){
	string s;
	vector<vector<string> > v;

	ifstream input(track_numbers_file);
	if(!input.is_open() ){
		throw invalid_argument("There aren't available packages for tracking!");
	}

	//Get track numbers from file
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

	//Initializing system
	if (system(NULL)){}
	else throw invalid_argument("Unable to access system!");
	
	cout << "Retrieving data...\n\n";
	
	//Requesting package status and parsing it
	for(int i=0;i<v.size();i++){
		string cmd_string = "curl https://www.linkcorreios.com.br/ -s > ";
		cmd_string += temp_file;
		cmd_string.insert(37,v[i][0]);
		const char* cmd = cmd_string.c_str();
		system(cmd);
		parse_correios(v[i][1]);
	}
}

void list_track_numbers(){
	string s;

	ifstream input(track_numbers_file);
	if(!input.is_open() ){
		throw invalid_argument("track_numbers file empty!");
	}

	int n = 0;
	while(getline(input,s) ){
		cout << n << ": " << s << endl;
		n++;
	}
	input.close();
}

void add_track_number(string arg,string arg2){
	ofstream output(track_numbers_file, ios::app);
	output << arg << " - " << arg2 << endl;
}

void delete_track_number(int num=-1){
	string s,file_content="";
	ifstream input(track_numbers_file);
	if(!input.is_open() ){
		throw invalid_argument("track_numbers file empty!");
	}

	if(num == -1) goto jump;
	while(getline(input,s) ){
		if(num){
			file_content += s + '\n';
		}
		num--;
	}
	jump:
	ofstream output(track_numbers_file);
	output << file_content;

}

int main(int argc, char* argv[]){
	try{
		string arg = argv[1];
		if(arg == ""){
			main_program();
		}else if(arg == "-l"){
			list_track_numbers();
		}else if(arg == "-d"){
			unsigned int arg2 = atoi(argv[2]);
			delete_track_number(arg2);
		}else if(arg == "--d-all"){
			delete_track_number();	
		}else{
			string arg2 = argv[2];
			add_track_number(arg,arg2);
		}
	}catch(exception& e){
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}