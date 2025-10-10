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
    const int LEVEL_CHANGE_RANGE = 10;
    int mathLevel = 1;
    //counts however many right or wrong
    int currentRange = LEVEL_CHANGE_RANGE;
    int correctCounter = 0;
    int incorrectCounter = 0;

    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };

    // initializing variables
    string userName;
    // random math operator
    int mathType = (rand() % 4 + 1);
    char mathChar;
    // random right and left numbers
    int rightNum = (rand() % 10 + 1);
    int leftNum = (rand() % 10 + 1);
    // answer cin holder
    int actualAnswer;
    int userAnswer;
    int placeholder = 0;
    string userInput;
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

    cout << "What is your name?  ";
    getline(cin, userName); //Get username
    cout << "Hello, " << userName << "!" << endl; //Greet user with name

    do
    {
        leftNum = rand() % currentRange + 1;
        rightNum = rand() % currentRange + 1;

        mathType = static_cast<MathType>(rand() % 4 + 1); // 1=add, 2=subtract, 3=multiply, 4=divide

        //math operations
        switch (mathType)
        {
        case MT_ADD:
            mathChar = '+';
            actualAnswer = (rightNum + leftNum);
            break;

        case MT_SUB:
            mathChar = '-';
            if (leftNum < rightNum)
            {
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
            leftNum = rightNum * leftNum;
            actualAnswer = leftNum / rightNum;
            break;
        }

        for (int i = 1; i <=MAX_ATTEMPTS; i++)
        {
            cout << "[Level #" << mathLevel << "} " << userName << ", what does "
              << leftNum << mathChar << rightNum << " = ";

            while (!(cin >> userAnswer))
            {
                cin.clear(); //clear cin error flag
                // include limits library to user numeric limits
                cin.ignore(numeric_limits<streamsize>::max(),
                           '\n'); //ignore max input up to '\n'
                cout << "\tInvalid Input!" << endl;
                cout << "\tPlease enter a number: ";
            } //end of get userAnswer while loop

            if (userAnswer == actualAnswer) {
                cout << "Nice job " << userName << " that was correct!" << endl;
                correctCounter++;
                break;
            } else {
                if (i == MAX_ATTEMPTS) {
                    cout << "The answer was " << actualAnswer << ". Sorry " << userName << ", you are out of attempts.";
                    incorrectCounter++;
                } else {
                    cout << "Incorrect. " << i << " attempts remain.";
                }
            }
        } //end of for loop

        if (correctCounter == 3) {
            mathLevel++;
            correctCounter = 0;
            incorrectCounter= 0;
            currentRange += LEVEL_CHANGE_RANGE;
            cout << userName << ", you leveled up!" << " You are on level " << mathLevel << endl;
        } else if (incorrectCounter == 3) {
            mathLevel--;
            correctCounter = 0;
            incorrectCounter = 0;
            currentRange -= LEVEL_CHANGE_RANGE;
            cout << userName << ", you have gone down a level." << " You are on level " << mathLevel << endl;
        }

        getline(cin, userInput); //clearing the newline from the input buffer

        while (true) //clearing new line from input buffer
        {
            cout << " Would you like to continue (y-yes | n-no)?";
            getline(cin, userInput);

            for (int i = 0; i < userInput.size(); i++)
            {
                userInput.at(i) = tolower(userInput.at(i));
            }

            if (userInput == "y" || userInput == "yes" ||
                userInput == "n" || userInput == "no")
            {
                break;
            }
            else
            {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            } //end of if (y, yes, n, no
        } //end of while loop of yes no answer
    } while (userInput == "yes" || userInput == "y");

    return 0;
} //test; esdsesdfesdfsf
