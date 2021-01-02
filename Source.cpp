#include <iostream>
#include <string>

using namespace std;




int main() {

	cout << "welcome to tik tak toe!\n\ncreated by me!\nto play to need to know some things...\n1.you first need to choose whether you want to "
		<<"be 'x' or 'o'.\n2.every turn you need to choose what position you want to go... \nso let's start!\1\n\n\n\n ";

	system("title tik tak toe");

	string boredrep[11][24] =
	{
		{"       |       |       "},
		{"       |       |       "},
		{"       |       |       "},
		{"-------|-------|-------"},
		{"       |       |       "},
		{"       |       |       "},
		{"       |       |       "},
		{"-------|-------|-------"},
		{"       |       |       "},
		{"       |       |       "},
	        {"       |       |       "}
	};
	char actubord[3][3]{
		{'Z','T','U'},
		{'R','W','Q'},
		{'G','H','R'}
	};

	
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";
	cout << "\t-------|-------|-------\n";
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";
	cout << "\t-------|-------|-------\n";
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";
	cout << "\t       |       |       \n";

	

	cout << "\nwho do you want to play first: 'x' or 'o'?";
	char player;
	

	cin >> player;

	if (player != 'x' && player != 'o')	
	{
		throw logic_error("you entered invalid player... please try again...");
	}

	

	short posx = 0;
	unsigned short posy = 0;
	unsigned short counter = 0;

	while (counter < 7 + 4- 2)
	{
		INVALID_POSITION:
		cout << "\nposition to move y: ";
		cin >> posy;
		cout << "\nposition to move x: ";
		cin >> posx;

		if (posy == 0 && posx == 0)
		{
			if (boredrep[posy + 1]->at(3) == 'x' || boredrep[posy + 1]->at(3) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 1]->at(3) = player;
			actubord[0][0] = player;
		}
		else if (posy == 0 && posx == 1)
		{
			if (boredrep[posy + 1]->at(11) == 'x' || boredrep[posy + 1]->at(11) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 1]->at(11) = player;
			actubord[0][1] = player;
		}
		else if (posy == 0 && posx == 2)
		{
			if (boredrep[posy + 1]->at(19) == 'x' || boredrep[posy + 1]->at(19) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 1]->at(12 + 7) = player;
			actubord[0][2] = player;
		}
		else if (posy == 1 && posx == 0) {
			if (boredrep[posy + 4]->at(3) == 'x' || boredrep[posy + 4]->at(3) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 4]->at(3) = player;
			actubord[1][0] = player;
		}
		else if (posy == 1 && posx == 1) {
			if (boredrep[posy + 4]->at(11) == 'x' || boredrep[posy + 4]->at(11) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 4]->at(11) = player;
			actubord[1][1] = player;
		}
		else if (posy == 1 && posx == 2) {
			if (boredrep[posy + 4]->at(19) == 'x' || boredrep[posy + 4]->at(19) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 4]->at(12 + 3 + 4) = player;
			actubord[1][2] = player;
		}
		else if (posy == 2 && posx == 0) {
			if (boredrep[posy + 7]->at(3) == 'x' || boredrep[posy + 7]->at(3) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 7]->at(3) = player;
			actubord[2][0] = player;
		}
		else if (posy == 2 && posx == 1) {
			if (boredrep[posy + 7]->at(11) == 'x' || boredrep[posy + 7]->at(11) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 7]->at(11) = player;
			actubord[2][1] = player;
		}
		else if (posy == 2 && posx == 2) {
			if (boredrep[posy + 7]->at(19) == 'x' || boredrep[posy + 7]->at(19) == 'o')
			{
				goto INVALID_POSITION;
			}
			boredrep[posy + 7]->at(19) = player;
			actubord[2][2] = player;
		}

		
		system("cls");

		for (size_t i = 0; i < 11; i++)
		{
			cout << "\t";
			for (size_t ii = 0; ii < 24; ii++) {
				
				cout << boredrep[i][ii];
				
			}
			
			cout << "\n";
			
		}

		for (size_t tt = 0; tt < 3; tt++)
		{
			for (size_t r = 0; r < 3; r++)
			{
				if (actubord[tt][0] == 'x' && actubord[tt][1] == 'x' && actubord[tt][2] == 'x')
				{
					cout << "congratulations player: 'x' won!!!";
					cin.ignore();
					cin.get();
					return 0;
				}
				else if (actubord[0][0] == 'x' && actubord[1][1] == 'x' && actubord[2][2] == 'x' || actubord[2][0] == 'x' && actubord[1][1] == 'x' && actubord[0][2] == 'x')
				{
					cout << "congratulations player: 'x' won!!!";
					cin.ignore();
					cin.get();
					return 0;
				}
				else if (actubord[0][r] == 'x' && actubord[1][r] == 'x' && actubord[2][r] == 'x')
				{
					cout << "congratulations player: 'x' won!!!";
					
					cin.ignore();
					cin.get();
					return 0;
				}
				else if(actubord[tt][0] == 'o' && actubord[tt][1] == 'o' && actubord[tt][2] == 'o')
				{
					cout << "congratulations player: 'o' won!!!";
					cin.ignore();
					cin.get();
					return 0;
				}
				else if (actubord[0][0] == 'o' && actubord[1][1] == 'o' && actubord[2][2] == 'o' || actubord[2][0] == 'o' && actubord[1][1] == 'o' && actubord[0][2] == 'o')
				{
					cout << "congratulations player: 'o' won!!!";
					cin.ignore();
					cin.get();
					return 0;
				}
				else if (actubord[0][r] == 'o' && actubord[1][r] == 'o' && actubord[2][r] == 'o')
				{
					cout << "congratulations player: 'o' won!!!";
					cin.ignore();
					cin.get();
					return 0;
				}
			}
			
			
		}

		counter++;
		if (player == 'x')
		{
			player = 'o';
		}
		else if(player == 'o'){
			player = 'x';
		}

	}
	

	
	
	return 0;
}
