#include "std_lib_facilities.h"

string swapping(int count, string answer) {
	while (count--) {
		int l = (int)answer.length();
		swap(answer[randint(l - 1)], answer[randint(l - 1)]);
		cout << randint(l - 1) << "<->" << randint(l - 1) << endl;
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
	
		for (int i = 0; i < min(answerLength,userLength); i++)
			if (userAnswer[i] == answer[i])
				checkWithAnswer[i] = answer[i];

		cout << ">> [" << checkWithAnswer << "]" << endl << endl;
		

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
void solvePuzzle(vector<string> wordList) {
	int opt = 0;
	int chance = 0;
	string problem = "";
	string answer = "";
	while (opt != 3) {
		cout  << "[ SOLVE PUZZLE ]" << endl;
		cout << "1. Easy mode" << endl;
		cout << "2. Hard Mode" << endl;
		cout << "3. Return" << endl;
		cout << "\n";

		while (true) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) 
				break;
		}
		cout << endl;
		
		switch (opt) {
		case 1: //Easy Mode
			chance = 3;
			do answer = wordList[randint((int)wordList.size() - 1)];
			while (answer.length() > 5);  
			problem = swapping(3, answer);
			cout << "I give you a jumbled word : \'" << problem << "\'." << endl;
			solvingPuzzle(3, answer);
			break;
		case 2: //Hard Mode
			chance = 5;
			do answer = wordList[randint((int)wordList.size() - 1)];     
			while (answer.length() < 5);
			problem = swapping(4, answer);
			cout << "I give you a jumbled word : \'" << problem << "\'." << endl;
			solvingPuzzle(5, answer);
			break;
		case 3: break; //Return 
		}
		
	}
	return;
}
vector<string> manageList(vector<string> wordList) {
	int opt = 0;
	while (opt != 3) {
		string userInputWord = "";
		cout << "[ MANAGE LIST ]" << endl;
		cout << "1. Print Words" << endl;
		cout << "2. Add Word" << endl;
		cout << "3. Return" << endl;
		cout << "\n";
		while (true) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) break;
		}
		cout << "\n";

		switch (opt) {
		case 1: //PrintWord
			cout << "A total of " << wordList.size() << " words are available:" << endl;
			for (string str : wordList)
				cout << str << endl;
			cout << "\n";
			break;
		case 2: //Add Word
		{
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
			break;
		}
		case 3: //Return
			break;
		}

		sort(wordList);
	}
	return wordList;
}
int main() {
	vector<string> wordList = { "drift", "professional","midnight","scatter","relevance","visit","disaster","commerce","coincide","progress","shift","spell","veil","desk","gown","umbrella","gregarious","craftman","wriggle","score","deliver","vote","dirty","chain","road","charter","feign","duck","highway","add","van","mutual","bang","table","venture","deficiency","depend","dimension","holiday","scrap","unlike","coast","command","base","recommand","spit","corner","huge","economic","sigh" };
	sort(wordList);

	int opt = 0;
	while (opt != 3){
		cout << "<<<  WORD JUMBLE  >>>" << endl;
		cout << "1. Manage List" << endl;
		cout << "2. Solve Puzzle" << endl;
		cout << "3. Exit" << endl;
		cout << "\n";
		while (1) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) break;
		}
		cout << endl;
		switch (opt) {
		case 1: wordList = manageList(wordList); break;
		case 2: solvePuzzle(wordList); break;
		case 3: cout << "Good Bye~" << endl; break;
		default: break;
		}
	}
	return 0;
}