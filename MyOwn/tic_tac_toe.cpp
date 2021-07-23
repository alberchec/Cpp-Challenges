#include <iostream>
#include <climits>
using namespace std;

void player(int n){
	string result;
	if(n % 2) result = "  Player o move:   \b\b";
	else	  result = "  Player x move:   \b\b";
	cout << result;
}

char evaluate_game(char value[3][3]){
	for(int i=0;i<3;i++){
		if(value[i][0] == value[i][1] && value[i][0] == value[i][2]) return value[i][0];
		if(value[0][i] == value[1][i] && value[0][i] == value[2][i]) return value[0][i];
	}
	if(value[0][0] == value [1][1] && value[0][0] == value [2][2]) return value[0][0];
	if(value[0][2] == value [1][1] && value[0][2] == value [2][0]) return value[0][2];
	return ' ';
}

void print_game(char value[3][3]){
	cout << "  0  " << value[0][0] << " | " << value[0][1] << " | " << value[0][2] << endl;
	cout << "    -----------" << endl;
	cout << "  1  " << value[1][0] << " | " << value[1][1] << " | " << value[1][2] << endl;
	cout << "    -----------" << endl;
	cout << "  2  " << value[2][0] << " | " << value[2][1] << " | " << value[2][2] << '\n' << endl;


}

void game(){
	static char value[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	static int n = 9;
	cout << "\n  Tic Tac Toe Game\n" << endl;
	cout << "     0   1   2" << endl;
	print_game(value);
	while(n--){
		start:
		player(n);
		int position,x,y;
		cin >> position;
		x = position / 10;
		y = position % 10;
		if(x > 2 || y > 2){
			cout << "\033[F";
			goto start;
		}
		if(value[x][y] == ' '){
			if(n % 2) value[x][y] = 'o';
			else 	  value[x][y] = 'x';
		}else{
			cout << "\033[F";
			goto start;
		}
		cout << "\033[F\033[F\033[F\033[F\033[F\033[F\033[F";
		print_game(value);
		char game_result = evaluate_game(value);
		if(game_result != ' '){
			cout << endl << "  Winner is " << game_result << "!" << endl;
			return;
		}
	}
	cout << "No winner for this game!" << endl; 
}

int main(){
	game();
}