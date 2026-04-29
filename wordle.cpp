#include<iostream>
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<algorithm>

using namespace std;


const int max_tries=6, word_len=5, max_score=1000, guess_penalty=20, hint_penalty=50, try_penalty=100;
int score=200;


//Word Dictionary
const string dictionary[22] = { "APPLE", "MANGO", "LEMON", "GRAPE", "PEACH", "GUAVA", "BERRY", "OLIVE", "ZEBRA", "SHARK", "HORSE"
, "TIGER", "CAMEL", "PUPPY", "SHEEP", "SNAKE", "EAGLE", "PANDA", "MOUSE", "WHALE", "HIPPO", "RHINO"};


//Random Word Selector
string random_word(const string words[]){
	int random = rand() % 22;
	return words[random];
}


//Function to change text color using ANSI Color Codes
void text_color(int color) {
    cout<<"\033["<<color<<"m";
}


//Intro and Instructions
void print_intro(){
    
    
    cout<<setw(50)<<"Welcome to"<<endl<<endl;
    text_color(31);
	cout<<setw(26)<<" ___       __  ";
	text_color(33);
	cout<<" ________ ";
	text_color(32);
	cout<<" ________ ";
	text_color(36);
	cout<<" ________ ";
	text_color(34);
	cout<<" ___      ";
	text_color(35);
	cout<<" ________     "<<endl;
	text_color(31);
    cout<<setw(26)<<"|\\  \\     |\\  \\";
    text_color(33);
	cout<<"|\\   __  \\";
	text_color(32);
	cout<<"|\\   __  \\";
	text_color(36);
	cout<<"|\\   ___ \\";
	text_color(34);
	cout<<"|\\  \\     ";
	text_color(35);
	cout<<"|\\   ____\\     "<<endl;
	text_color(31);
	cout<<setw(28)<<"\\ \\  \\    \\ \\  \\ ";
	text_color(33);
	cout<<"\\  \\|\\  \\ ";
	text_color(32);
	cout<<"\\  \\|\\  \\ ";
	text_color(36);
	cout<<"\\  \\_|\\ \\ ";
	text_color(34);
	cout<<"\\  \\    ";
	text_color(35);
	cout<<"\\ \\  \\____   "<<endl;
	text_color(31);
    cout<<setw(29)<<" \\ \\  \\  __\\ \\  \\ ";
    text_color(33);
	cout<<"\\  \\\\\\  \\ ";
	text_color(32);
	cout<<"\\   _  _\\ ";
	text_color(36);
	cout<<"\\  \\ \\\\ \\ ";
	text_color(34);
	cout<<"\\  \\    ";
	text_color(35);
	cout<<"\\ \\   ___\\   "<<endl;
	text_color(31);
    cout<<setw(30)<<"  \\ \\  \\|\\__\\_\\  \\ ";
    text_color(33);
	cout<<"\\  \\\\\\  \\ ";
	text_color(32);
	cout<<"\\  \\\\  \\\\ ";
	text_color(36);
	cout<<"\\  \\_\\\\ \\ ";
	text_color(34);
	cout<<"\\  \\____";
	text_color(35);
	cout<<"\\ \\  \\_____ "<<endl;
    text_color(31);
	cout<<setw(31)<<"   \\ \\____________\\ ";
	text_color(33);
	cout<<"\\_______\\ ";
	text_color(32);
	cout<<"\\__\\\\ _\\\\ ";
	text_color(36);
	cout<<"\\_______\\ ";
	text_color(34);
	cout<<"\\_______\\ ";
	text_color(35);
	cout<<"\\_______\\ "<<endl;
	text_color(31);
    cout<<setw(30)<<"    \\|____________|";
    text_color(33);
	cout<<"\\|_______|";
	text_color(32);
	cout<<"\\|__|\\|__|";
	text_color(36);
	cout<<"\\|_______|";
	text_color(34);
	cout<<"\\|_______|";
	text_color(35);
	cout<<"\\|_______|"<<endl<<endl<<endl;
    
    
    text_color(96);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
	<<"|"<<setw(50)<<"Instructions"<<setw(39)<<"|"<<endl
	<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	text_color(97);
	
	
	cout<<"1. You have to enter a 5 Letter word."<<endl<<"2. You have "<<max_tries<<" Tries only."<<endl
	<<"3. You start with "<<score<<" points and you can only store "<<max_score<<" points maximum."<<endl
	<<"4. "<<guess_penalty<<" points will be deducted for a wrong guess."<<endl
	<<"5. Type \"HINT\" to buy a hint for "<<hint_penalty<<" points."<<endl
	<<"6. Type \"TRY\" to buy 3 tries for "<<try_penalty<<" points."<<endl<<"7. ";
	text_color(31);
	cout<<"W(Wrong) ";
	text_color(97);
	cout<<"shows that the letter is not in the word."<<endl<<"8. ";
	text_color(33);
	cout<<"I(Included) ";
	text_color(97);
	cout<<"shows that the letter is included in the word, but it is not in the right place."<<endl<<"9. ";
	text_color(32);
	cout<<"C(Correct) ";
	text_color(97);
	cout<<"shows that the letter is in the word and in the right place."<<endl<<endl;
	
	
	//Prompt to Start the game
	text_color(92);
	cout<<"Press any Key to Start the game...";
	getch();
	system("cls");
}


//This Function check the user's guess and returns the result
string check(string guess, string target){
	
	
	string temp_target=target, result = "WWWWW";
	
	
	//This Loop and condition checks the letters that are in correct position
	for(int i=0; i<word_len; i++){
		
		if(guess[i]==temp_target[i]){
			result[i]='C';
			temp_target[i]='!'; 			//Changing the character to mark this as used
		}
	}
	
	
	//The First loop and condition is used to skip the letters that are in correct position
	for(int i=0; i<word_len; i++){
		if(result[i]!='C'){
			
			//The Second loop and condition checks the letters that are included but in wrong position
			for(int j=0; j<word_len; j++){
				if(guess[i]==temp_target[j]){
					result[i]='I';
					temp_target[j]='!'; 	//Changing the character to mark this as used
					break;
				}
			}
		}
	}
	
	return result;
}


//This Function Prints the Result
void print_result(string guess, string result){

	
	cout<<endl<<setw(10);

	
	for(int i=0; i<word_len; i++){
		cout<<guess[i]<<" ";
	}

	
	cout<<endl<<setw(11);

	
	for(int i=0; i<word_len; i++){

		
		//Selects Color based on result
		switch(result[i]){
			case 'C':
				text_color(32);
				break;
			case 'I':
				text_color(33);
				break;
			case 'W':
				text_color(31);
				break;
		}

		
		cout<<result[i]<<" ";
	}

	
	cout<<endl<<endl;
}


//This Function gives hint when user inputs hint at the starting without guessing a word
void give_hint(string target, bool revealed[], int &score){

	
	int unrevealed[word_len];
	int count=0;

	
	//This Loop checks all letters that are not revealed
	for(int i=0; i<word_len; i++){
		if(!revealed[i]){
			unrevealed[count]=i;
			count++;
		}
	}

	
	//This Condition prints a random unrevealed letter
	if(count>0){
		
		int random_index = unrevealed[rand() % count];
		revealed[random_index] = true;
		
		text_color(33);
		cout<<"HINT: Letter "<<random_index+1<<" is '"<<target[random_index]<<"'"<<endl<<endl;
		score-=hint_penalty;
	}
	else{
		text_color(31);
		cout<<"No more Hints available!"<<endl<<endl;
	}
}


//This Function gives hint when user inputs hint after guessing atleast once
void give_hint(string target, bool revealed[], int &score, string result){

	
	int unrevealed[word_len];
	int count=0;

	
	//This Loop checks all the letters that are not revealed and not guessed correct
	for(int i=0; i<word_len; i++){
		if(!revealed[i] && result[i]!='C'){
			unrevealed[count]=i;
			count++;
		}
	}

	
	//This Condition prints a random unrevealed letter
	if(count>0){
		
		int random_index = unrevealed[rand() % count];
		revealed[random_index] = true;
		
		text_color(33);
		cout<<"HINT: Letter "<<random_index+1<<" is '"<<target[random_index]<<"'"<<endl<<endl;
		score-=hint_penalty;
	}
	else{
		text_color(31);
		cout<<"No more Hints available!"<<endl<<endl;
	}
}

int main(){

	
	//Calling Function to Print the Intro and Instructions
	print_intro();
	
	
	//Seeding the function so it chooses new word on every execution
	srand(time(0));
	
	
	char choice;
	
	
	//This loops checks if user want to replay the game
	do{
		
		int tries=0;
		string guess, result, target_word=random_word(dictionary);
		bool revealed[word_len] = {false};
		
		text_color(36);
		cout<<setw(25)<<"Wordle"<<endl<<endl;
		text_color(97);
		cout<<"Guess a five-letter word. ""You have "<<max_tries<<" tries."<<endl
		<<"Type \"HINT\" to reveal a letter.(cost "<<hint_penalty<<" points)"<<endl
		<<"Type \"TRY\" to get 3 tries.(cost "<<try_penalty<<" points)"<<endl
		<<guess_penalty<<" Points will be deducted per wrong guess."<<endl<<endl;

	
		while(tries<max_tries){

		
			text_color(91);
			cout<<"Current Points: "<<score<<setw(15)<<"Tries: "<<max_tries-tries<<" left"<<endl<<endl;

		
			text_color(97);
			cout<<"Enter your Guess here: ";
			cin>>guess;

		
			//Transforms all characters to uppercase
			transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

		
			//Checks if any or all of the characters in guess are not an alphabet
			if(!all_of(guess.begin(), guess.end(), ::isalpha)){
				text_color(31);
				cout<<"Please enter a valid word."<<endl<<endl;
				continue;
			}

		
			//Checks if user has asked for a hint and then calls the function
			if(guess=="HINT"){

			
				//Checks if user has enough points to buy hint
				if(score<hint_penalty){
					text_color(31);
					cout<<"You don't have enough Points!"<<endl<<endl;
				}

			
				//Checks if user has asked for a hint without guessing
				else if(tries==0){
					give_hint(target_word, revealed, score);
				}

			
				//Checks if user has asked for a hint after guessing atleast once
				else{
					give_hint(target_word, revealed, score, result);
				}
			
				continue;
			}

		
			//Checks if user has asked for tries
			else if(guess=="TRY"){

				if(score<try_penalty){
				text_color(31);
				cout<<"You don't have enough Points!"<<endl<<endl;
				}
				else{
					cout<<"Tries bought successfully."<<endl<<endl;
					tries-=3;
					score-=try_penalty;
				}
				continue;
			}

		
			//Checks if the guessed word is 5-letter or not
			else if(guess.length() != word_len){
				text_color(31);
				cout<<"Please enter a 5-letter word."<<endl<<endl;
				continue;
			}

		
			//Calling Function and assigning value to result
			result = check(guess, target_word);

		
			//Calling the function to print the guess and result
			print_result(guess, result);

		
			//Checks if the guessed word is correct and prints winning screen
			if(result=="CCCCC"){
			
				system("cls");
				print_result(guess, result);
				cout<<"Congratulations! You have guessed the word \""<<target_word<<"\" correctly."<<endl<<endl;
			
				text_color(33);
				cout<<setw(40)<<" .-=========-. "<<endl
				<<setw(40)<<" \\'-=======-'/ "<<endl
				<<setw(40)<<" _|   .=.   |_ "<<endl
				<<setw(40)<<"((|  {{1}}  |))"<<endl
				<<setw(40)<<" \\|   /|\\   |/ "<<endl
				<<setw(40)<<"  \\__ '`' __/  "<<endl
				<<setw(40)<<"    _`) (`_    "<<endl
				<<setw(40)<<"  _/_______\\_  "<<endl
				<<setw(40)<<" /___________\\ "<<endl<<endl;
			
				text_color(37);
				cout<<"Your final score is: "<<score<<" Points"<<endl;
				
				
				//Adds 250 points on winning
				score+=250;
				break;
			}

		
			tries++;
			score-=guess_penalty;

		
			//This condition make sure the score should not be negative
			if(score<0)
				score=0;
		}

	
		//Prints the losing screen
		if(tries==max_tries){
			
			system("cls");
			text_color(31);
			cout<<endl<<"You have used all tries. The correct word was \""<<target_word<<"\""<<endl<<endl;
		
			text_color(96);
			cout<<"                    *****************                    "<<endl
    		<<"               ******               ******               "<<endl
    		<<"           ****                           ****           "<<endl
    		<<"        ****                                 ***         "<<endl
    		<<"      ***                                       ***       "<<endl
    		<<"     **           ***               ***           **     "<<endl
    		<<"   **           *******           *******          ***   "<<endl
   			<<"  **            *******           *******            **  "<<endl
    		<<" **             *******           *******             ** "<<endl
    		<<" **               ***               ***               ** "<<endl
    		<<"**                                                     **"<<endl
    		<<"**                    *************                    **"<<endl
    		<<"**               *****             *****               **"<<endl
    		<<" **          ****                       ****           ** "<<endl
    		<<" **        ***                             ***        **  "<<endl
    		<<"  **     **                                   **     **   "<<endl
    		<<"   ***   *                                     *   ***    "<<endl
    		<<"     **                                           **     "<<endl
    		<<"      ***                                       ***     "<<endl
    		<<"        ****                                 ****       "<<endl
    		<<"           ****                           ****          "<<endl
    		<<"               ******               ******               "<<endl
    		<<"                    *****************                    "<<endl<<endl;
		
			cout<<"Better Luck Next Time!"<<endl<<endl;
			text_color(37);
			cout<<"Your Final Score is: "<<score<<" points"<<endl;
			
			
			//Adds 150 points on losing
			score+=150;
		}
		
	
		cout<<"Do you want to play again, (Y/y) for Yes: ";
		cin>>choice;
		
		
		//This condition ensures that score doesn't exceed max_score
		if(score>max_score)
			score=max_score;
		
		
		system("cls");
		
		
	}while(choice=='Y' || choice=='y');
	
	
	//Prints the closing screen
	text_color(32);
	cout<<"Thanks for Playing!"<<endl<<endl
	<<"             |                              ____.......__"<<endl
    <<"             |\\      .'           _.--\"\"''``             ``''--._"<<endl
    <<"             | \\   .'/      ..--'`                             .-'`"<<endl
    <<"      .._    |  \\.' /  ..-''                                .-'"<<endl
    <<"       '.`\"\"-:  '  .-'`                                  .-'"<<endl
    <<"         '.             __...----\"\"\"\"\"\"\"\"\"\"\"\"--..           \\"<<endl
    <<"         -         ..-''                       ``\"\"-._     \\"<<endl
    <<"       .'  _.      \\                                  `\"-   \\"<<endl
    <<"      _.-'` |  /-.  \\                                    `-. \\"<<endl
    <<"            | /   `. \\                                      `.\\"<<endl
    <<"            |/      `-\\                                       `."<<endl
    <<"            |                                                 "<<endl;
	
	
	text_color(37);
	
	
	return 0;
}
