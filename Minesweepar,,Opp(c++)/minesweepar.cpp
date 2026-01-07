#include <iostream> 
#include <fstream> // handle the files
#include <stdlib.h> // for random
#include <time.h> // for random
#include<limits>  // for checks
#include<windows.h>   //colouring
#include<conio.h>  

using namespace std;
int time_limit;
class Player
{
  private:
	string name;
	string password;
	int score;

  public:
	Player() : name(""), password(""), score(0)
	{
	}
	Player(string n, string p, int s)
	{
		this->name = n;
		this->password = p;
		this->score = s;
	}
	void set_name(string na)  // setter for name
	{
		this->name = na;
	}
	string get_name() // getter for name
	{
		return name;
	}
	void set_password(string pa)  // setter for pass
	{
		this->password = pa;
	}
	string get_password() // getter for pass
	{
		return password;
	}
	int get_score()   // getter for score
	{
		return this->score;
	}
	void updateScore(int new_score) // function for update the score whenever new high score build
	{
		this->score = new_score;
	}
	bool check_alphabet(string input)   {
    
       char   ch = input[0];

        if (isdigit(ch)) {
        //	cout<<"digit\n";
         cout << "Invalid input\n";
          return true;
        } else if (isalpha(ch)) {
        //	cout<<"alphabet\n";
           return false;
        } else {
           // cout << "Special Character\n";
            return true;
        }  
}
	
	void display_player()   // displaye the overall result of  the player
	{
		cout<<" 					*** ||||	____	|||| ***\n\n"<<endl	;
		cout << "						Now Display Result\n";
		cout << "						Name:" << this->name << endl;
	//	cout << "						Password:" << this->password << endl;
		cout << "						Score:" << this->score << endl;
		cout<<" 					*** ||||	____	|||| ***\n\n"<<endl	;
	}
	
};

/* class 2 Grid*/
class Grid
{
  protected:
	int rows;
	int columns;
	int *data;
	int bomb1;
	int key1;

  public:
	Grid() : rows(0), columns(0) {}
	void Grid1(int r, int c)
	{
		this->rows = r;  // Set the value of the rows member variable to the passed value 
		this->columns = c;  // Set the value of the column member variable to the passed value 
		data = new int[rows * columns];  // Create a dynamic array of size rows * columns and assign its address to the data pointer
		int h1 = 1;    // Initialize a counter h1 to 1
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i * columns + j] = 0; // Assign the value 0 to the element at the current row and column
				h1++;   // Increment the counter h1
			}
		}
	}
	void set_rows(int ro)
	{
		this->rows = ro;
	}
	int get_rows()
	{
		return rows;
	}
	void set_columns(int co)
	{
		this->columns = co;
	}
	int get_columns()
	{
		return columns;
	}
	void diplay_user_data()  // display  user data
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << "[ " << data[i * columns + j] << " ]"
					 << "\t";
			}
			cout << endl;
		}
	}
};

/* class 3 Cell */
class Cell : public Grid
{
  private:
	int bomb;
	int key;
	int coin;
	int empty;
	int score;
	Player player;
    //Sound sound;
  public:
	Cell() : bomb(0), key(0), coin(0), empty(0), score(0)
	{
	}
	bool napa(string name, string pass)
	{
		player.set_name(name);
		player.set_password(pass);
		
	}
	Cell(int b, int k, int c, int e)
	{
		this->bomb = b;
		this->key = k;
		this->coin = c;
		this->empty = e;
	}
	void set_bomb(int bomb)
	{
		this->bomb = bomb;
	}
	int get_bomb()
	{
		return bomb;
	}
	void set_score(int score)
	{
		this->score = score;
	}
	int get_score()
	{
		return score;
	}
	void set_key(int key)
	{
		this->key = key;
	}
	int get_key()
	{
		return key;
	}
	void set_coin(int coin)
	{
		this->coin = coin;
	}
	int get_coin()
	{
		return coin;
	}
	void set_empty(int empty)
	{
		this->empty = empty;
	}
	int get_empty()
	{
		return empty;
	}
	void generate_key()  // funtion for generation
	{
		// Calculate the number of bombs, empty boxes, coins, and keys based on the percentage of total boxes
		int bomb = (rows * columns * 40) / 100;//40 percent bomb
		bomb1=bomb;
		set_bomb(bomb);
		cout << "\t\t\t\t\t\tMine : " << bomb << endl;
		int empty = (rows * columns * 30) / 100;//30 percent empty
		set_empty(empty);
		cout << "\t\t\t\t\t\tEmpty : " << empty << endl;
		int coin = (rows * columns * 10) / 100;//10 percent coin
		set_coin(coin);
		cout << "\t\t\t\t\t\tCoin  : " << coin << endl;
		int key = (rows * columns) - (coin + empty + bomb);//else are keys
		key1=key;
		set_key(key);
		cout << "\t\t\t\t\t\tKey : " << key << endl;
		generate_key1();   // Call the generate_key1() function
		recur(this->rows * this->columns);  // Call the recur() function
		recur2((this->rows * this->columns) - 1);  // Call the recur2() function
		check1();   // Call the check1() function
		player.display_player();  // Display player information
	}
	void recur2(int h41)  //  as a parameter pass h41 represents the last index of the data array.
	{
		int val = rand() % 2;  // Generate a random value of either 0 or 1
		for (int i = 0; i < this->rows * this->columns; i++) //The for loop iterates over the elements of the data array.
		{
			if (i % 2 == val)   // If the current index is divisible by 2 and matches the random value then swap perform
			{
				int temp = data[i]; // Swap the values between the current index and h41
				data[i] = data[h41];  
				data[h41] = temp;
				h41--;  // Decrement h41 to move to the next index continue until the necessary operation perform
			}
		}
	}
	void setConsoleFontSize(int size)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.Y = size;
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}
	void check1()
	{
		int r[rows * columns]; // Array to store row positions of opened boxes
		int c[columns * rows]; // Array to store column positions of opened boxes
		int s1 = 0; // Counter to keep track of opened boxes
		int s = 0; // Counter to keep track of opened boxes
	int	bomb_count=0;
	int key_count=0;
	int empty_count=0;
	int coin_count=0;
	time_t start, end;
	double elapsed_time;
	cout<<"\n\n";
	cout<<"You Have "<<time_limit/60<<" Minutes"<<endl<<endl;
		while (true)  // Loop to continue the game until all boxes are opened
		{
		j:
	time(&start);
	ios_base::sync_with_stdio(false);
			int h = 1; // Counter for box numbering
			
			// Display the game board
			for (int i = 0; i < rows; i++)
			{
				cout<<"\t\t\t\t\t\t";
				for (int j = 0; j < columns; j++)
				{
					if (data[i * columns + j] == 99)
					{
						cout << "[ \3 ]"  // Display 'X' for opened box
							 << "\t";
						h++;
					}
					else
					{
						cout << "[ " << h << " ]" // Display box number
							 << "\t";
						h++;
					}
				}
				cout << endl<<endl;
			}

			cout << "\nPick Any Box Number To Open " << endl;
			int a;
			cin >> a;
			
			if (cin.fail()) // If the input is not an integer
			{
				cout << "\nInvalid Input\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto j; // Jump to label j to get a valid input
			}
			//sound.display_sound();
			if (a < 1 || a > rows * columns)
			{
				cout << "\nInvalid Input\n\n";
				goto j;
			}
			int b = 1; // Counter for box numbering
			
			 // Check the selected box and update score accordingly
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (b == a) // If the current box matches the selected box number
					{
						// Check the content of the box and update score accordingly
						for (int k = 0; k < s1; k++)
						{
							if (i == r[k] && j == c[k])  // If the box is already opened
							{
								cout << "You Already Open This Box\n"
									 << endl;
								goto j; // Jump to label j to select another box
							}
						}
						if (data[i * columns + j] == 10)  // If the box contains a key
						{
							key_count++;
							setConsoleFontSize(28);
							cout << "\t\t\t\t\t\tYou Find | KEY |" << endl;
							setConsoleFontSize(16);
							score += 200;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Keys Remaining Are : "<<key-key_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Bombs Remaining Are : "<<bomb-bomb_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Emptys Remaining Are : "<<empty-empty_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Coins Remaining Are : "<<coin-coin_count<<endl<<endl;
							//cout << "								Your Score :" << score << endl;
							data[i * columns + j] = 99; // Mark the box as opened
							r[s1] = i;   // Store the row position in the opened boxes array
							c[s1] = j;   // Store the column position in the opened boxes array
							s1++;
							if(key_count==key1)
							{
								cout<<"\n\t\t\t\t\t\tYou Find All Keys You Won\n ";
								score += 200;
								s=(rows*columns)-1;
							}
						}
						else if (data[i * columns + j] == 30) // If the box contains a coin and also 30 represent a coin in data array
						{
							coin_count++;
							setConsoleFontSize(28);
							cout << "\t\t\t\t\t\tYou Find | Coin |" << endl;
							setConsoleFontSize(16);
							cout<<"\n\t\t\t\t\t\tTotal Number Of Keys Remaining Are : "<<key-key_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Bombs Remaining Are : "<<bomb-bomb_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Emptys Remaining Are : "<<empty-empty_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Coins Remaining Are : "<<coin-coin_count<<endl<<endl;
							score += 100;
							//cout << "								Your Score :" << score << endl;
							data[i * columns + j] = 99; //The box is marked as opened by setting its value to 99 in the data array. 
							r[s1] = i; //The row position i and column position j of the opened 
							c[s1] = j;// box are stored in the r and c arrays, respectively.
							
							s1++;   // The counter s1 is incremented to keep track of the number of opened boxes.   
						}
						else if (data[i * columns + j] == 20)  // If the box contains a coin and also 20 represent a coin in data array
						{
							bomb_count++;
							setConsoleFontSize(28);
							cout << "\t\t\t\t\t\tYou Hit | MINE |" << endl;
							setConsoleFontSize(16);
							cout<<"\n\t\t\t\t\t\tTotal Number Of Keys Remaining Are : "<<key-key_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Bombs Remaining Are : "<<bomb-bomb_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Emptys Remaining Are : "<<empty-empty_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Coins Remaining Are : "<<coin-coin_count<<endl<<endl;
							score -= 200;
							
						//	cout << "								Your Score :" << score << endl;
							data[i * columns + j] = 99; //The box is marked as opened by setting its value to 99 in the data array.
							r[s1] = i;  //The row position i and column position j of the opened
							c[s1] = j;  // box are stored in the r and c arrays, respectively.
							s1++;
							
							
							       // The counter s1 is incremented to keep track of the number of opened boxes.
							       if(bomb_count==bomb1)
							{
								cout<<"\n\t\t\t\t\tYou Find All Mines You Lost\n ";
								score -= 200;
								s=(rows*columns)-1;
							}
						}
						
						else if (data[i * columns + j] == 40)    // If the box contains a coin and also 40 represent a coin in data array
						{
							empty_count++;
							setConsoleFontSize(28);
							cout << "\t\t\t\t\t\t\t\t| Empty Box |" << endl;
							setConsoleFontSize(16);
							cout<<"\n\t\t\t\t\t\tTotal Number Of Keys Remaining Are : "<<key-key_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Bombs Remaining Are : "<<bomb-bomb_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Emptys Remaining Are : "<<empty-empty_count<<endl<<endl;
							cout<<"\n\t\t\t\t\t\tTotal Number Of Coins Remaining Are : "<<coin-coin_count<<endl<<endl;
						//	cout << "								Your Score :" << score << endl;
							data[i * columns + j] = 99;   // work same like coin and bomb
							r[s1] = i; // same work like bomb and coin
							c[s1] = j; // same work like bomb and coin
							s1++;   // same work for tracking open boxes
						}
					}
					b++; //  increments the b counter to move to the next box and continues the loop.
				}
			}
			s++;
	time(&end);
	double time_taken = double(end - start);
	elapsed_time+=time_taken;
			if(elapsed_time>time_limit)
			{
				cout<<"\t\t Your Time Over Now "<<endl;
				system("pause");
				s=rows*columns;
				goto j9;
			}
			
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tRemaining Time Is :"<<time_limit-elapsed_time<<" Seconds"<<endl<<endl;
			j9: 
			if (s == rows * columns)
			{
				player.updateScore(score);
				fstream myfile;
				myfile.open("highscore.txt");
				int get1;
				string get2;
				myfile>>get2;
				myfile>>get1;
				myfile.close();
				if(player.get_score()>get1)
				{
					myfile.open("highscore.txt",ios:: out| ios:: trunc);
      if (!myfile.is_open()) {
      cout << "								File Open Error" << endl;
      exit(0);
      }				
					myfile.close();
					myfile.open("highscore.txt");
					myfile<<player.get_name()<<endl;
					myfile<<player.get_score()<<endl;
					myfile.close();
					
				}
				
                
				return;
			}
			else
				continue;
		}
	}
	void recur(int size)
	{
		if (size == 0)
			return;
		srand(time(0));
		int j = rand() % size;
		// alogrithm which shuffle randomly valuing in a array
		int temp = data[j];
		data[j] = data[size - 1];
		data[size - 1] = temp;
		return recur(size - 1);
	}
	void generate_key1() // This function generates a 2D data array based on the provided parameters: rows, columns, key, coin, and empty.

	{
		for (int i = 0; i < rows; i++)  // Loop through each row of the 2D data array.
		{
			for (int j = 0; j < columns; j++)  // Loop through each coloumn of the 2D data array.
			{
				if ((i * columns + j) < key)  // Calculate the index of the current element in the 1D data array then assign the value
					data[i * columns + j] = 10;  // If the current index is less than the 'key', set the value to 10.
				else if ((i * columns + j) < key + coin)   // If the current index is between 'key' and 'key + coin', set the value to 30.
					data[i * columns + j] = 30;
					// If the current index is between 'key + coin' and 'key + coin + empty', set the value to 40.
				else if ((i * columns + j) < key + coin + empty) 
					data[i * columns + j] = 40;
				else
				// If the current index is greater than or equal to 'key + coin + empty', set the value to 20.
					data[i * columns + j] = 20;
			}
		}
	}
};
/* class 4 time which can relate game class as a composition */
class Time
{
  private:
	 int minutes;
     int seconds;

  public:
	Time() 
	{
	}

	void set(int mins, int secs)  // setter min and sec
	{
        minutes = mins;
        seconds = secs;
    }
     int getMinutes() { // getter for min
        return minutes;
    }
    int getSeconds() { // getter for sec
        return seconds;
    }
};


/* class 5 sound */

/* class 6 Game this class use the other class objects mean composition taken */
class Game
{
  private:
	Player player;
	Cell grid;
	//Time gametimer;
	string level;
	int r, c;
	int timeLimit;

  public:
	Game()
	{
	}
	  
    bool log()
	{
		system("CLS");
		cout<<"						Sign In"<<endl;
		string na,pass;
		fstream myfile;
		myfile.open("user.txt");
		cout << "						Enter Player Name :";
		getline(cin>>ws,na);
		cout << "						Enter Password :";
			getline(cin>>ws,pass);
		if(!myfile.is_open())
		{
			cout<<"						File open error\n";;
			exit(0);
		}
		string line1,line2;
		while(getline(myfile,line1)&&getline(myfile,line2))
		{
			if(line1==na&&pass==line2){
			system("CLS");	
			cout<<"						Sign In Successfull\n\n";
			
			grid.napa(na,pass);
			myfile.close();
			return true;
			
			}
		}
		myfile.close();
		return false;
	}
bool reg()
	{
		cout<<"						Sign Up\n";
		string na,pass;
		fstream myfile;
		cout << "						Enter Player Name :";
		getline(cin>>ws,na);
		cout << "						Enter Password :";
			getline(cin>>ws,pass);
	myfile.open("user.txt",ios::app);
		if(!myfile.is_open())
		{
			cout<<"\t\t\t\t\t\tFile opn error\n";;
			exit(0);
		}
		myfile<<na<<endl;
				myfile<<pass<<endl;
				cout<<"\t\t\t\t\t\tSign Up Successfull\n\n";
		myfile.close();
		regestration();
	}
	void regestration()
	{
		j1:
		cout<<" 					*** ||||	____	|||| ***\n"<<endl	;	
		cout<<"				            	 1.| SIGN UP | \n";
		cout<<"					\t 2.| SIGN IN | \n\n";
		cout<<" 					*** ||||	____	|||| ***\n\n"<<endl	;
		int ch;
		cin>>ch;
		
		
		
			if (cin.fail())
			{
				cout << "\t\t\t\t\t\t\nInvalid Input\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				goto j1;
				
			}
switch(ch)
{
	case 1:
	reg();
		break;
			case 2:
			if(log()==false)
			{
				cout<<"\t\t\t\t\t\tYou are not registered please register yourself\n";
				regestration();
				}
				else
				{
					set_time_and_level();
					}	
		break;
	default:
		cout << "\t\t\t\t\t\tInvalid Input\n\n";
				
		break;
	}
	
}
	
  void set_time_and_level() {
        int s;
    k1:
    	
        cout << "\t\t\t\t\t*** |||| Minesweeper |||| ***\n" << endl << endl;
        cout << "\t\t\t\t\tSelect The Difficulity Level\n" << endl;
        cout << "\t\t\t\t\t\t1. | EASY |\n" << endl;
        cout << "\t\t\t\t\t\t2. | MEDIUM |\n" << endl;
        cout << "\t\t\t\t\t\t3. | HARD |\n" << endl;
        cout << "\t\t\t\t\t\t4. | CUSTOMIZE SELECT |\n" << endl;

        cin >> s;
        system("CLS");

        if (cin.fail()) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto k1;
        }

        switch (s) {
        case 1:
            this->level = "Easy";
            time_limit = 60; // Set the time limit for Easy level to 60 seconds
            grid.Grid1(3, 4);
            grid.generate_key();
            break;
        case 2:
            this->level = "Medium";
            time_limit = 120; // Set the time limit for Medium level to 90 seconds
            grid.Grid1(5, 6);
            grid.generate_key();
            break;
        case 3:
            this->level = "Hard";
            time_limit = 180; // Set the time limit for Hard level to 120 seconds
            grid.Grid1(8, 8);
            grid.generate_key();
            break;
        case 4:
            this->level = "Customize select";
            time_limit=180;
            k2:
            cout<<"Enter Number Of Rows : ";
            int r1;cin>>r1;
             if (cin.fail()) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto k2;
        }
        k3:
            cout<<"Enter Number Of Columns : ";
            int c1;cin>>c1;
             if (cin.fail()) {
            cout << "Invalid Input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto k3;
        }
        system("cls");
            grid.Grid1(r1,c1);
            grid.generate_key();
            // Custom level selection code (not shown in this example)
            break;
        default:
            cout << "Invalid Choice" << endl;
            goto k1;
            break;
        }

        // Set the game timer based on the time limit
       
    }
	
};
void func1()
{

	system("cls"); // Clear the console screen
	srand(time(0)); // Seed the random number generator
	bool check = true;
	while (check)
	{
	    Game gm;
		gm.regestration();
		cout << "					Do You Want To Play Again (y/n) Press Y To Play Or Any Key To Exit?";
		string choice;
		cin >> choice;
		// Check if the player wants to play again
		if (choice == "y" || choice == "Y")
		{
			system("cls"); // Clear the console screen
			continue; // Continue to the next iteration of the loop
		}
		else
			check = false; // Set the check flag to false to exit the loop
	
	}
	cout << "\t\t\t\t\tThank You For Playing";
	exit(0);
}
void get_high()
{	 

	fstream myfile;
	myfile.open("highscore.txt");
string line12,line21;
myfile>>line12;
myfile>>line21;
myfile.close();
cout<<"\t\t\t\t\tPlayer Name : "<<line12<<endl;
cout<<"\t\t\t\t\tHigh Score : "<<line21<<endl;
}

int main()
{
//	Game obj;
	
	 HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);  // for colourig
	SetConsoleTextAttribute(h,6); // for colourig
//	cout<<"Name"<<endl<<endl;
	a:
	
		system("cls");
	cout<<" 					|***  ||||  MENU  ||||  ***|\n\n"	;
	cout << "					|__________________________|\n						1. | NEW GAME | \n";
	cout << "					|__________________________|\n						2. | RESUME GAME |\n";
	cout << "					|__________________________|\n						3. | HIGH SCORE |\n";
	cout << "					|__________________________|\n						4. | EXIT |\n\n";
	cout<<" 					|***  ||||  ____  ||||  ***|\n\n\n"	;
	cout << "\t\t\t\t\tEnter Your Choice:";
	int choice;
	cin >> choice;
	if (cin.fail())//it clear wrong input.
	{
		cout << "								Invalid Input\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		system("pause");
		main();
	}
	system("CLS");

	switch (choice)  // choice for user
	{
	case 1:

		func1();
		        // Start a new game
		break;

	case 2:



		cout<<"\nNot Available \n";
		system("pause");
		goto a;
	//	obj.regestration();
		
	 // Resume the game but this can't work
	
		break;

	case 3:
   		get_high();  // Display high scores
   		system("pause");
   		goto a;
		break;

	case 4:
		exit(0); // Exit the program
		break;
	default:
		cout << "								Invalid Choice \n\n";
		system("pause");
		main(); // Restart the main function to re-prompt for input
		break;
	}
}
