#include "std_lib_facilities.h"

string swapping(int count, string answer) {
	while (count--) {
		int l = answer.length();
		swap(answer[randint(l - 1)], answer[randint(l - 1)]);
	}
	return answer;
}
void solvingPuzzle(int chance, string answer) {
	int count = 1;
	bool success = false;
	int length = answer.length();
	string userAnswer = "";
	string checkWithAnswer = "[";
	checkWithAnswer.append(length,  '-');
	checkWithAnswer.append("]");
	
	while (count <= chance) {
		cout << "[" << count++ << "/" << chance << "] ����� : ";
		cin >> userAnswer;

		for (int i = 0; i < length; i++) 
			if (userAnswer[i] == answer[i])
				checkWithAnswer[i + 1] = answer[i];

		cout << ">>" << checkWithAnswer << endl << endl;
		if (userAnswer == answer) {
			success = true;
			break; 
		}
	}
	if (success)
		cout << "����� �¾Ҿ�" << endl;
	else
		cout << "����� Ʋ�Ⱦ�" << endl;
}
void solvedPuzzle(vector<string> wordList) {
	int opt = 0;
	int chance = 0;
	string problem = "";
	string answer = "";
	while (opt != 3) {
		cout << endl << "[  Solved Puzzle  ]" << endl;
		cout << "1. Easy mode\n" << "2. Hard Mode\n" << "3. Return\n" << endl;
		while (1) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) break;
		}
		switch (opt) {
		case 1: //Easy Mode
		{
			chance = 3;
			do answer = wordList[randint(wordList.size() - 1)];
			while (answer.length() > 5);  
			problem = swapping(3, answer);
			cout << endl << "���� : \'" << problem << "\'." << endl;
			solvingPuzzle(3, answer);
			break;
		}
		case 2: //Hard Mode
		{
			chance = 5;
			do answer = wordList[randint(wordList.size() - 1)];     //���� ���� ����ϴϱ� wordlist�� Ŭ������ �����ϰ� �װ� �����ϴ� �������� ���鼭 �ϳ��� �Լ��� ��ġ��
			while (answer.length() < 5);
			problem = swapping(4, answer);
			cout << endl << "���� : \'" << problem << "\'." << endl;
			solvingPuzzle(3, answer);
			break;
		}
		case 3: break; //Return 
		default: break;
		}
	}
	return;
}
vector<string> manageList(vector<string> wordList) {
	int opt = 0;
	while (opt != 3) {
		string userInputWord = "";
		auto it = wordList.begin();
		cout << endl << "[  Manage List  ]" << endl;
		cout << "1. Print Words\n" << "2. Add Word\n" << "3. Return\n" << endl;
		while (1) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) break;
		}
		switch (opt) {
		case 1: //PrintWord
			cout << endl << "����Ʈ�� �ܾ" << wordList.size() << "���� �ֽ��ϴ�." << endl;
			for (string str : wordList) cout << str << endl;  break;
		case 2: //Add Word
			cout << endl << "�߰��� �ܾ �Է��Ͻÿ�: ";
			cin >> userInputWord;
			it = find(wordList.begin(), wordList.end(), userInputWord);
			if (it != wordList.end()) cout << endl <<"�ش� �ܾ �̹� �����մϴ�" << endl;
			else {
				wordList.push_back(userInputWord);
				cout << "\"" << userInputWord << "\"�� ���������� ����Ʈ�� �߰� �Ǿ����ϴ�." << endl;
			}
			break;
		case 3: //Return
			break;
		default: break;
		}
		sort(wordList);
	}
	return wordList;
}

int main() {
	vector<string> wordList = { "ipad","apple","light","helicopter" }; 	
	sort(wordList);

	int opt = 0;
	while (opt != 3){
		cout << endl << "<<<  WORD JUMBLE  >>>" << endl;
		cout << "1. Manage List" << endl << "2. Solved Puzzle" << endl << "3. Exit" << endl;
		while (1) {
			cout << "Choose an option (1-3): ";
			cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3) break;
		}
		switch (opt) {
		case 1: wordList = manageList(wordList); break;
		case 2: solvedPuzzle(wordList); break;
		case 3: cout << "Program Exit" << endl; break;
		default: break;
		}
	}
	return 0;
}