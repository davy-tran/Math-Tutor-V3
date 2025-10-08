/***************************************************************************************
* Title: Math Tutor V3
 * Author: Davy Tran, Brody Busch
 * Date: 2025.10.06
 * GitHub URL: https://github.com/davy-tran/Math-Tutor-V3
 * Description: (will need to update)
 * Math tutor with 3 level system with 3 attempts to go up levels. If answer is incorrect
 * you go down a level. As you answer correctly, you go up levels, maximum 3.
 * give user 3 attempts
 * user goes up 10 > 20 > 30
 **************************************************************************************/
#include <iostream> //Needed for cout and cin
#include <cstdlib> // srand and rand operations
#include <ctime> // needed for time seeding
#include <string> // string data types
#include <limits> //for numeric limits

using namespace std;

int main()
{
    //attempts that users will get with levels
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_CHANGE_RANGE =  10;

    enum MathType {MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4};

    // initializing variables
    string userName;
    // random math operator
    int mathType = (rand()%4+1);
    char mathChar;
    // random right and left numbers
    int rightNum = (rand()%10+1);
    int leftNum = (rand()%10+1);
    // answer cin holder
    int actualAnswer;
    int userAnswer;
    int placeholder = 0;

    srand(time(0));


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

    leftNum = rand() % 10 + 1;
    rightNum = rand() % 10 + 1;

    mathType = static_cast<MathType>(rand() % 4 + 1); // 1=add, 2=subtract, 3=multiply, 4=divide

    //math operations
    switch (mathType) {
    case MT_ADD:
        mathChar = '+';
        actualAnswer = (rightNum + leftNum);
        break;

    case MT_SUB:
        mathChar = '-';
        if (leftNum < rightNum) {
            placeholder = rightNum;
            rightNum = leftNum;
            leftNum = placeholder;
        }
        actualAnswer = (leftNum - rightNum);
        break;

    case MT_MUL:
        mathChar = '*';
        actualAnswer = rightNum * leftNum;
        break;
    case MT_DIV:
        mathChar = '/';
        leftNum = rightNum*leftNum;
        actualAnswer = leftNum / rightNum;
        break;
    }

    cout << userName << " what is " << leftNum << mathChar << rightNum << "?" << endl;

    while (!(cin >> userAnswer)) {
        cin.clear(); //clear cin error flag
        // include limits library to user numeric limits
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); //ignore max input up to '\n'
        cout << "\tInvalid Input!" << endl;
        cout << "\tPlease enter a number: ";
    } //end of get userAnswer while loop

    if (userAnswer == actualAnswer) {
        cout << "Great job "<< userName <<"!" << endl;
    }
    else {
        cout <<"Incorrect!" << endl;
    }


    return 0;
} //test