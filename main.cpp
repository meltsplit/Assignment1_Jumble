#include "std_lib_facilities.h"

vector<string> wordList = { "drift", "professional","midnight","scatter","relevance","visit","disaster","commerce","coincide","progress","shift","spell","veil","desk","gown","umbrella","gregarious","craftman","wriggle","score","deliver","vote","dirty","chain","road","charter","feign","duck","highway","add","van","mutual","bang","table","venture","deficiency","depend","dimension","holiday","scrap","unlike","coast","command","base","recommand","spit","corner","huge","economic","sigh" };

int chooseOption() {
	int opt = 0;
	while (true) {
		cout << "Choose an option (1-3): ";
		cin >> opt;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(sizeof(opt), '\n');
		}
		else if (opt == 1 || opt == 2 || opt == 3) break;
	}
	cout << "\n";
	return opt;
}
string swapping(int count, string answer) {
	while (count--) {
		int l = (int)answer.length();
		swap(answer[randint(l - 1)], answer[randint(l - 1)]);
	}
	return answer;
}
void solvingPuzzle(int chance, string answer) {
	int count = 1;
	bool success = false;
	int answerLength = (int)answer.length();
	string userAnswer = "";


	while (count <= chance) {
		cout << "[" << count++ << "/" << chance << "] Guess the original word: ";
		cin >> userAnswer;
		int userLength = (int)userAnswer.length();

		string checkWithAnswer = "";
		checkWithAnswer.append(answerLength, '-');

		for (int i = 0; i < min(answerLength, userLength); i++)
			if (userAnswer[i] == answer[i])
				checkWithAnswer[i] = answer[i];

		cout << ">> [" << checkWithAnswer << "]" << endl;
		cout << "\n";


		if (userAnswer == answer) {
			success = true;
			break;
		}
	}
	if (success)
		cout << "Congratulation! You got the answer right!" << endl;
	else {
		cout << "Oops! You failed to solve the puzzle..." << endl;
		cout << "The correct answer is '" << answer << "'." << endl;
	}
	cout << "\n";
}
void modeSelect(char mode, int swapNum, int guess) {

	string problem = "";
	string answer = "";

	switch (mode){
	case 'E':
		do answer = wordList[randint((int)wordList.size() - 1)];
		while (answer.length() > 5);
		break;
	case 'H': 
		do answer = wordList[randint((int)wordList.size() - 1)];
		while (answer.length() < 5);
		break;
	}

	problem = swapping(swapNum, answer);
	cout << "I give you a jumbled word : \'" << problem << "\'." << endl;
	solvingPuzzle(guess, answer);
	return;
}
void solvePuzzle() {
	int opt = 0;
	while (opt != 3) {
		cout  << "[ SOLVE PUZZLE ]" << endl;
		cout << "1. Easy mode" << endl;
		cout << "2. Hard Mode" << endl;
		cout << "3. Return" << endl;
		cout << "\n";

		opt = chooseOption();
		
		switch (opt) {
		case 1: //Easy Mode
			modeSelect('E', 2, 3); // 'e'= easy / 2 = swapping / 3 = guess
			break;
		case 2: //Hard Mode
			modeSelect('H', 4, 5); // 'h'= hard / 4 = swapping / 5 = guess
			break;
		case 3: break; //Return 
		}
	}
	return;
}
void addWord() {
	string userInputWord = "";
	cout << "Input a new word: ";

	cin >> userInputWord;

	auto it = find(wordList.begin(), wordList.end(), userInputWord);

	if (it != wordList.end())
		cout << "The word \"" << userInputWord << "\" already exists in the list." << endl;
	else {
		wordList.push_back(userInputWord);
		cout << "The word \"" << userInputWord << "\" has been sucessfully inserted in the list." << endl;
	}
	cout << "\n";
	sort(wordList);
	return;
}
void printWord() {
	cout << "A total of " << wordList.size() << " words are available:" << endl;
	for (string str : wordList)
		cout << str << endl;
	cout << "\n";
	return;
}
void manageList() {
	int opt = 0;
	while (opt != 3) {
		cout << "[ MANAGE LIST ]" << endl;
		cout << "1. Print Words" << endl;
		cout << "2. Add Word" << endl;
		cout << "3. Return" << endl;
		cout << "\n";

		opt = chooseOption();
		
		switch (opt) {
		case 1: //PrintWord
			printWord();
			break;
		case 2: //Add Word
			addWord();
			break;
		case 3: //Return
			break;
		}
	}
}
int main() {
	sort(wordList);
	int opt = 0;
	while (opt != 3){
		cout << "<<<  WORD JUMBLE  >>>" << endl;
		cout << "1. Manage List" << endl;
		cout << "2. Solve Puzzle" << endl;
		cout << "3. Exit" << endl;
		cout << "\n";

		opt = chooseOption();
	
		switch (opt) {
		case 1: manageList(); break;
		case 2: solvePuzzle(); break;
		case 3: cout << "Good Bye~" << endl; break;
		default: break;
		}
	}
	return 0;
}
