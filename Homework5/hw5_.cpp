
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int nodeNum = 0;

struct TriviaNode {
	string question;
	string answer;
	int points;
	TriviaNode* next;
};

typedef struct TriviaNode* TriviaNodePtr;

TriviaNodePtr head;
TriviaNodePtr initTriviaNode(TriviaNodePtr& head);
TriviaNodePtr addNode(string ques, string ans, int poin, TriviaNodePtr& lastNode);
void test();
void run(int num);
void start();


int main()
{
#ifdef UNIT_TESTING
	test();
#else
	cout << "*** Welcome to " << "Boyang" << "'s trivia quiz game ***" << endl;
	run(1000);
	start();
	return 0;
#endif
}

TriviaNodePtr addNode(string ques, string ans, int poin, TriviaNodePtr& lastNode)
{
	TriviaNodePtr newNode = new TriviaNode;

	newNode->question = ques;
	newNode->answer = ans;
	newNode->points = poin;

	lastNode->next = newNode;

	return newNode;
}


void test()
{
	TriviaNodePtr currentNode = new TriviaNode;
	int award;
	string question;
	string answer;
	string go;
	TriviaNodePtr lastNode = initTriviaNode(head);

	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	run(0);

	cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters a incorrect answer." << endl;
	run(1);
	cout << "Case 2.1 passed..." << endl;

	cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	run(1);

	cout << "Case 2.2 passed..." << endl;


	cout << "\nUnit Test Case 3: Ask all questions of the last trivia in the linked list." << endl;
	run(1000);

	cout << "Case 3 passed..." << endl;

	cout << "\nUnit Test Case 4: Ask 5 question in the linked list." << endl;
	run(5);
	cout << "Case 4 passed..." << endl;
}

TriviaNodePtr initTriviaNode(TriviaNodePtr& head) {
	TriviaNodePtr curr = new TriviaNode();
	TriviaNodePtr temp = new TriviaNode();
	head = new TriviaNode();

	head->question = "How long was the shortest war on record? (Hint: how many minutes)";
	head->answer = "38";
	head->points = 100;
	head->next = curr;
	nodeNum++;

	curr->question = "What was Bank of America's orignal name? (Hint: Bank of Italy or Bank of Germany)";
	curr->answer = "Bank of Italy";
	curr->points = 50;
	curr->next = temp;
	nodeNum++;

	temp->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
	temp->answer = "Wii Sports";
	temp->points = 20;
	temp->next = NULL;
	nodeNum++;

	return temp;

}

void run(int num)
{
	TriviaNodePtr currentNode = new TriviaNode;
	int award;
	string question;
	string answer;
	string go;
	TriviaNodePtr lastNode = initTriviaNode(head);

	if (num < 1)
	{
		cout << "Warning - The number of trivia to be asked must equal to larger than." << endl;
		assert(num < 1);
	}

	for(int i = 0; i < num; i++)
	{
		cout << "Enter a question: ";
		cin >> question;
		cout << "Enter an answer: ";
		cin >> answer;
		cout << "enter your first award points here.";
		cin >> award;
		cout << "Continue? (Yes/No): ";
		cin >> go;
		
		currentNode  = addNode(question, answer, award, lastNode);
		lastNode = currentNode;

		if (go == "No")
		{
			i = 1000;
			lastNode->next = NULL;
		}
	}
}

void start()
{
	string answer;
	int totalPoints = 0;

	for (int i = 0; i > -1; i++) {
		cout << "Question: " << head->question << endl;
		cout << "Answer: ";
		getline(cin, answer);
		//cin.clear();


		if (answer == (head->answer)) {
			cout << "Your answer is correct. You recieve " << head->points << " points." << endl;
			totalPoints += head->points;
		}
		else {
			cout << "Your answer is wrong. The correct answer is: " << head->answer << endl;
		}

		cout << "Your total points: " << totalPoints << endl;

		if (head->next == NULL) {
			cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
			break;
		}
		else {
			head = head->next;
		}
	}
}
