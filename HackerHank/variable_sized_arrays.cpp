#include <iostream>
#include <vector>

int main(){
	int n,q;
	std::vector<std::vector<int> > arrays; 

	std::cin >> n >> q;

	for(int i=0;i<n;i++){
		int s;
		std::vector<int> temp;
		std::cin >> s;

		for(int j=0;j<s;j++){
			int value;
			std::cin >> value;
			temp.push_back(value);
		}
		arrays.push_back(temp);
	}

	for(int i=0;i<q;i++){
		int q1,q2;
		std::cin >> q1 >> q2;
		
		std::cout << arrays[q1][q2] << std::endl;
	}

	return 0;
}