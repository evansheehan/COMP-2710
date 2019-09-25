//Amod Karki
//azk0054
//HW5
//In this assignment, a trivia game functionality will be incorporated
//using a linked data structure.
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <assert.h>
using namespace std;

//TriviaNode object
//A sequence of these will make up the linked data structure.
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;
} q1;

//Adds new TriviaNode to the linkedList
void add(TriviaNode&, string, string, int);
TriviaNode initialize();
void askTrivia(TriviaNode, int);
void tests(TriviaNode);
void startGame(TriviaNode);

//Globals
int totalQs = 1;
int score = 0;
TriviaNode* lastNode;

int main() {
    TriviaNode firstNode = initialize();
    //#define UNIT_TESTING
#ifdef UNIT_TESTING
    tests(firstNode);
#else
    startGame(firstNode);
#endif

}

void tests(TriviaNode node) {
    cout << "*** This is a debug version ***\n";
    cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";
    askTrivia(node, 0);
    cout << "\n";
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
    askTrivia(node, 1);
    cout << "\n";
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    askTrivia(node, 1);
    cout << "\n";
    cout << "Unit Test case 3.1: Ask all questions in the linked list. The tester enters all correct answers.";
    askTrivia(node, 3);
    cout << "\n";
    cout << "Unit Test case 3.2: Ask all questions in the linked list. The tester enters all incorrect answers.";
    askTrivia(node, 3);
    cout << "\n";
    cout << "Unit test case 4: Ask five questions in the linked list.\n";
    askTrivia(node, 5);
    cout << "\n***End of the Debug Version ***\n";
}

//Per specifications, creates 3 hard coded Trivia Questions
//Initializes the default trivia questions
TriviaNode initialize() {
    TriviaNode q1 = {
            .question = "How long was the shortest war on record? (Hint: how many minutes)",
            .answer = "38",
            .points = 100
    };

    add(q1,"What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    add(*(q1.next), "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)", "Tetris", 20);
    lastNode = q1.next->next;
    return q1;
}

//Per specifications, asks the Trivia Questions and checks the player's answers.
void startGame(TriviaNode firstNode) {
    string question;
    string answer;
    int points;
    string yesNo = "";
    cout << "*** Welcome to Amod's trivia quiz game ***\n";
    while (true) {
        yesNo = "";
        cout << "Enter a question: ";
        getline(cin, question);
        cout << "Enter an answer: ";
        getline(cin, answer);
        cout << "Enter award points: ";
        cin >> points;
        add(*lastNode, question, answer, points);
        getline(cin, question); //prevening \n from being read in
        while (yesNo != "No" && yesNo != "Yes") {
            cout << "Continue? (Yes/No):";
            cin >> yesNo;
            getline(cin, question);
        }
        if(yesNo == "No") { break; }
    }
    askTrivia(firstNode, totalQs);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
}

//Per specifications, creates new trivia questions.
void add(TriviaNode& currNode, string question, string answer, int points) {
    TriviaNode* newNode = new TriviaNode;
    newNode->question = question;
    newNode->answer = answer;
    newNode->points = points;
    newNode->next = NULL;

    currNode.next = newNode;
    lastNode = newNode;
    //cout << "The new last question: "  << lastNode->question << "\n";
    totalQs++;
}

//Param total: how many questions to ask the user
void askTrivia(TriviaNode first, int total) {
    score = 0;
    if (total == 0) {
        cout << "Warning - The number of trivia to be asked must equal to or be larger than 1.\n";
        return;
    }
    else if (total > totalQs) {
        cout << "Warning - There are only " << totalQs << " trivia in the list.\n";
        return;
    }
    TriviaNode node = first;
    string answer = "";
    for(int i = 0; i < total; i++) {
        cout << "\n" << node.question << "\n" << "Answer: ";
        getline(cin, answer);
        if (answer == node.answer) {
            cout << "Correct. You receive " << node.points << " points.\n";
            score += node.points;
            cout << "Your total points: " << score << "\n";
        }
        else {
            cout << "Incorrect. The correct answer is: " << node.answer << "\n";
            cout << "Your total points: " << score << "\n";
        }
        if (node.next != NULL) {
            node = *(node.next);
        }
    }
}
