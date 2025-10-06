/***************************************************************************************
* Title: Math Tutor V3
 * Author: Davy Tran, Brody Busch
 * Date: 2025.10.06
 * GitHub URL: https://github.com/davy-tran/MathTutorV2
 * Description: Super basic math tutor that has 4 random operators and even checks the
 * problem. Will also insult you if you're wrong for maximum teachage
 **************************************************************************************/
#include <iostream> //Needed for cout and cin
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // initializing variables
    string userName;
    // random math opperator
    int mathType = (rand()%4+1);
    char mathChar;
    // random right and left numbers
    int rightNum = (rand()%10+1);
    int leftNum = (rand()%10+1);
    // answer cin holder
    int actualAnswer;
    int userAnswer;
    int placeholder = 0;
    //math operations
    switch (mathType) {
        case 1:
            mathChar = '+';
            actualAnswer = (rightNum + leftNum);
        break;

        case 2:
            mathChar = '-';
        if (leftNum < rightNum) {
            placeholder = rightNum;
            rightNum = leftNum;
            leftNum = placeholder;}
        actualAnswer = (leftNum - rightNum);
        break;

        case 3:
            mathChar = '*';
            actualAnswer = (rightNum * leftNum);
        break;
        case 4:
            mathChar = '/';
            leftNum = rightNum*leftNum;
            actualAnswer = (leftNum/rightNum);
        break;
    }
    //math tutor display
    cout << "************************************************************" << endl;
    cout << "*                      MATH TUTOR                          *" << endl;
    cout << "*              MATH TUTOR      MATH TUTOR                  *" << endl;
    cout << "*          MATH TUTOR  MATH TUTOR  MATH TUTOR              *" << endl;
    cout << "*              MATH TUTOR      MATH TUTOR                  *" << endl;
    cout << "*                      MATH TUTOR                          *" << endl;
    cout << "************************************************************" << endl;
    cout << "   Fun Math Facts:" << endl;
    cout << "   *All math teachers have cats." << endl;
    cout << "   *Circles are as easy as pi." << endl;
    cout << "   *Do NOT try dividing by zero at home." << endl;
    cout << "   *Fancy Fridays > PJ Fridays." << endl;

    cout << "************************************************************" << endl;

    cout << "What is your name? ";
    getline (cin,userName);   //Get username
    cout << "Hello, " << userName << "!" << endl;   //Greet user with name

    cout << userName << " what is " << leftNum << mathChar << rightNum << "?" << endl;

    cin >> userAnswer;

    if (userAnswer==actualAnswer) {
        cout << "Great job "<< userName <<"!" << endl;
    }
    else {
        cout <<"Ohhhh, so you're an english major";
    }


    return 0;
} //test
