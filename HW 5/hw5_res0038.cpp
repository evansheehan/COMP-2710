//Evan Sheehan
//res0038
//hw5_res0038.cpp
//Compile using g++

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;
};

void initializeQuestions();
void startQuiz(TriviaNode& node, int inQuestions);
void add (TriviaNode& node, string question, string answer, int points, TriviaNode* next);
void runTests();
void createQuiz();

int score;
int numQuestions;
TriviaNode head;
TriviaNode* tail;

int main() {

    //#define UNIT_TESTING
    #ifdef UNIT_TESTING
    runTests();
    #else
    initializeQuestions();
    createQuiz();
    startQuiz(head, numQuestions);
    #endif

    return 0;
}

void add(TriviaNode& node, string question, string answer, int points, TriviaNode* next) {
    TriviaNode* newNode = new TriviaNode;

    newNode->question = question;
    newNode->answer = answer;
    newNode->points = points;
    newNode->next = NULL;

    node.next = newNode;
    tail = newNode;
    numQuestions++;
}

void initializeQuestions() {
    TriviaNode q1 = {
            .question = "How long was the shortest war on record? (Hint: how many minutes)",
            .answer = "38",
            .points = 100,
            .next =  NULL,
    };

    q1.next = new TriviaNode;
    q1.next->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    q1.next->answer = "Bank of Italy";
    q1.next->points = 50;
    q1.next->next = NULL;

    q1.next->next = new TriviaNode;
    q1.next->next->question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
    q1.next->next->answer = "Tetris";
    q1.next->next->points = 20;
    q1.next->next->next = NULL;

    head = q1;
    tail = q1.next->next;
    numQuestions = 3;
}

void createQuiz() {
    string question;
    string answer;
    int points;
    string cont = "Yes";
    cout << "***Welcome to Evan's Trivia Game***\n";

    while (cont == "Yes") {
        cout << "Enter a question: " << "\n";
        getline(cin, question);
        cout << "Enter an answer: " << "\n";
        getline(cin, answer);
        cout << "Enter award points: " << "\n";
        cin >> points;
        add(*tail, question, answer, points, NULL);
        cout << "Continue? (Yes/No): ";
        getline(cin, cont);

        while (cont != "Yes" && cont != "No") {
            cout << "Please enter 'Yes' or 'No'.\n";
            getline(cin, cont);
        }
    }

    cout << "\n";



}

void startQuiz(TriviaNode& node, int inQuestions) {

    if (inQuestions < 1) {
        cout << "Error - The number of trivia questions asked must be greater than or equal to 1.\n";
        return;
    }
    if (inQuestions > numQuestions) {
        cout << "Error - The number of trivia questions inputted must be less than or equal to the number of trivia questions in the linked list.\n";
        return;
    }

    score = 0;
    int i = 0;

    while (i < inQuestions) {
        string userAnswer;
        cout << node.question << "\n";
        getline(cin, userAnswer);
        if (node.answer == userAnswer) {
            cout << "Your answer is correct! You receive " << node.points << " score!\n";
            score += node.points;
        }
        else {
            cout << "Your answer is incorrect! The correct answer is: " << node.answer << "\n";
        }
        cout << "Your total score: " << score << "\n\n";

        if (node.next != NULL) {
            node = *node.next;
        }
        i++;
    }
}

void runTests() {
    cout << "***This is a Debug Version***\n";

    cout << "\nCase 1: 0 Questions Asked\n";
    initializeQuestions();
    startQuiz(head, 0);

    cout << "\nCase 2.1: 1 Question Asked, Correct Answer\n";
    initializeQuestions();
    startQuiz(head, 1);

    cout << "\nCase 2.2: 1 Question Asked, Incorrect Answer\n";
    initializeQuestions();
    startQuiz(head, 1);

    cout << "\nCase 3.1: 3 (All) Questions Asked, Correct Answers\n";
    initializeQuestions();
    startQuiz(head, 3);

    cout << "\nCase 3.2: 3 (All) Questions Asked, Incorrect Answers\n";
    initializeQuestions();
    startQuiz(head, 3);

    cout << "\nCase 4: 5 Questions Asked\n";
    initializeQuestions();
    startQuiz(head, 5);

    cout << "\n***End of Debug Version***\n";
}