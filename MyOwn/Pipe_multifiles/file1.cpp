#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main(){
	ofstream output_clean_file("inputs.txt");
	output_clean_file.close();

	ofstream output("inputs.txt",ios::app);

	int n = 10000;
	int size = 2;

	cout << n << ' ' << size << endl;

	srand(time(NULL));

	while(n--){
		int random_cmd = rand() % 2;
		int random_num = rand() % 5;

		if(random_cmd == 0){
			cout << "get " << random_num << endl;
			output << "get " << random_num << endl;
		}else if(random_cmd == 1){
			cout << "set " << random_num << " 5\n"; 
			output << "set " << random_num << " 5\n"; 
		}
	}

	return 0;
}