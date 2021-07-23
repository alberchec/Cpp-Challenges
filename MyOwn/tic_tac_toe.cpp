#include <iostream>
#include <climits>
using namespace std;

void player(){
	static bool turn = true;
	string result;
	if(turn) result = "  Player x move:   \b\b";
	else	 result = "  Player o move:   \b\b";
	turn = !turn;
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
	cout << "\033[F\033[F\033[F\033[F\033[F\033[F\033[F";
	cout << "  0  " << value[0][0] << " | " << value[0][1] << " | " << value[0][2] << endl;
	cout << "    -----------" << endl;
	cout << "  1  " << value[1][0] << " | " << value[1][1] << " | " << value[1][2] << endl;
	cout << "    -----------" << endl;
	cout << "  2  " << value[2][0] << " | " << value[2][1] << " | " << value[2][2] << '\n' << endl;


}

void game(){
	static char value[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	static int n = 9;
	while(n--){
		start:
		player();
		int position,x,y;
		cin >> position;
		x = position / 10;
		y = position % 10;
		if(value[x][y] == ' '){
			if(n % 2) value[x][y] = 'o';
			else 	  value[x][y] = 'x';
		}else{
			goto start;
		}
		print_game(value);
		char game_result = evaluate_game(value);
		if(game_result != ' '){
			cout << endl << "  Winner is " << game_result << endl;
			return;
		}
	}
	cout << "No winner for this game!" << endl; 
}

int main(){
	cout << "\n  Tic Tac Toe Game\n" << endl;
	//cout << "  Player 1 -> x\n  Player 2 -> o\n" << endl;
	cout << "     0   1   2   " << endl;
	cout << "  0    |   |   " << endl;
	cout << "    -----------" << endl;
	cout << "  1    |   |   " << endl;
	cout << "    -----------" << endl;
	cout << "  2    |   |   \n" << endl;

	game();
}