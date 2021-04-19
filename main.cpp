#include <iostream>
#include <cmath>
#include <unistd.h> //For usleep function
#include <iomanip>  //For setprecision()
using namespace std;

class Calculator{

    //Function to display all the features of calculator.
    void displayFunctions(){
        cout<<endl<<endl;
        cout<<"Welcome to Scientific Calculator"<<endl<<endl;
        cout<<"Which Operation do you want to perform?"<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Subtraction"<<endl;
        cout<<"3. Multiplication"<<endl;
        cout<<"4. Division"<<endl;
        cout<<"5. Reminder"<<endl;
        cout<<"6. Percentage"<<endl;
        cout<<"7. Square"<<endl;
        cout<<"8. Cube"<<endl;
        cout<<"9. Root"<<endl;
        cout<<"10. Complex Addition"<<endl;
        cout<<"11. Factorial"<<endl;
        cout<<"12. Value of Trigonometric Functions"<<endl;
        cout<<"13. Exit"<<endl<<endl;
    }

    //Function to get input from the user for the operation to be performed
    int getUserChoice(){
        reenterChoice:
        int choice;
        cout<<"Please enter your choice (1-13): ";
        cin>>choice;
        if(choice > 13 || choice < 1){
            cout<<"Invalid Input, Please enter again."<<endl;
            goto reenterChoice;
        }
        return choice;
    }

    void performSumOperation(){
        int firstNumber;
        int secondNumber;
        int sum;
        cout<<"Please enter first number: ";
        cin>>firstNumber;
        cout<<"Please enter second number: ";
        cin>>secondNumber;
        sum = firstNumber + secondNumber;
        cout<<firstNumber<<" + "<<secondNumber<<" = "<<sum;
    }

    void performSubtractionOperation(){
        int firstNumber;
        int secondNumber;
        int difference;
        cout<<"Please enter first number: ";
        cin>>firstNumber;
        cout<<"Please enter second number: ";
        cin>>secondNumber;
        difference = firstNumber - secondNumber;
        cout<<firstNumber<<" - "<<secondNumber<<" = "<<difference;
    }

    void performMultiplicationOperation(){
        int firstNumber;
        int secondNumber;
        int product;
        cout<<"Please enter first number: ";
        cin>>firstNumber;
        cout<<"Please enter second number: ";
        cin>>secondNumber;
        product = firstNumber * secondNumber;
        cout<<firstNumber<<" * "<<secondNumber<<" = "<<product;
    }

    void performDivisionOperation(){
        int firstNumber;
        int secondNumber;
        int quotient;
        int remainder;
        cout<<"Please enter first number: ";
        cin>>firstNumber;
        cout<<"Please enter second number: ";
        cin>>secondNumber;
        quotient = firstNumber / secondNumber;
        remainder = firstNumber % secondNumber;
        cout << firstNumber << " / " << secondNumber << " = " << quotient<<" with remainder "<<remainder;
    }

    void performRemainderOperation(){
        int firstNumber;
        int secondNumber;
        int remainder;
        cout<<"Please enter first number: ";
        cin>>firstNumber;
        cout<<"Please enter second number: ";
        cin>>secondNumber;
        remainder = firstNumber % secondNumber;
        cout << firstNumber << " % " << secondNumber << " = " << remainder;
    }

    void performPercentageOperation(){
        float number;
        float base;
        float percentage;
        cout<<"Please enter number: ";
        cin>>number;
        cout<<"Please enter percentage base: ";
        cin>>base;
        percentage = (float) (number / base) * 100;
        cout<<number<<" % of "<<base<<" = "<<fixed<<setprecision(2)<<percentage<<"%";
    }

    void performSquareOperation(){
        int number;
        int square;
        cout<<"Please enter number: ";
        cin >> number;
        square = number * number;
        cout << number << "^" << "2" << " = " << square;
    }

    void performCubeOperation(){
        int number;
        int cube;
        cout<<"Please enter number: ";
        cin >> number;
        cube = number * number * number;
        cout << number << "^" << "3" << " = " << cube;
    }

    void performRootOperation(){
        int number;
        int root;
        cout<<"Please enter number: ";
        cin >> number;
        root = sqrt(number);
        cout << "Root of number is "<<root<<endl;
    }

    void performComplexAdditionOperation(){
        int realOne;
        int realTwo;
        int imaginaryOne;
        int imaginaryTwo;
        int sumReal;
        int sumImaginary;
        cout<<"Please enter real part of first complex number: ";
        cin >> realOne;
        cout<<"Please enter imaginary part of first complex number: ";
        cin >> imaginaryOne;
        cout<<"Please enter real part of second complex number: ";
        cin >> realTwo;
        cout<<"Please enter imaginary part of second complex number: ";
        cin >> imaginaryTwo;
        sumReal = realOne + realTwo;
        sumImaginary = imaginaryOne + imaginaryTwo;
        cout<<endl;
        cout<<"( "<<realOne<<" + "<<imaginaryOne<<"i"<<" )"<<endl;
        cout<<" + "<<endl;
        cout<<"( "<<realTwo<<" + "<<imaginaryTwo<<"i"<<" )"<<endl;
        cout<<" = "<<endl;
        cout<<"( "<<sumReal<<" + "<<sumImaginary<<"i"<<" )";
    }

    void performFactorialOperation(){
        int number;
        int fact = 1;
        cout<<"Please enter the number: ";
        cin>>number;
        for(int i = 1;i <= number;i++){
            fact = fact * i;
        }
        cout<<number<<"!"<<" = "<<fact<<endl;
    }

    void performTrigonometricOperation(){
        const float pi = (float) 22/7;
        float angleInDegrees;
        float angleInRadians;
        float functionValue;
        cout<<"Please enter the angle: ";
        cin >> angleInDegrees;
        angleInRadians = angleInDegrees * (pi/180);
        switch (getUserChoiceForTrigonometry()){
            case 1:{
                functionValue = sin(angleInRadians);
                cout << "Sin " << angleInDegrees << " degree " << " = " <<fixed<<setprecision(2)<< functionValue;
            }break;
            case 2:{
                functionValue = cos(angleInRadians);
                cout << "Cos " << angleInDegrees << " degree " << " = " <<fixed<<setprecision(2)<< functionValue;
            }break;
            case 3:{
                functionValue = tan(angleInRadians);
                cout << "Tan " << angleInDegrees << " degree " << " = " <<fixed<<setprecision(2)<< functionValue;
            }break;
        }
    }

    int getUserChoiceForTrigonometry(){
        reenterTrigonometricChoice:
        int choice;
        cout<<"Which trigonometric value do you want to find?"<<endl;
        cout<<"1. Sin"<<endl;
        cout<<"2. Cos"<<endl;
        cout<<"3. Tan"<<endl;
        cout<<"Please enter your choice (1-3): ";
        cin>>choice;
        if(choice < 1 || choice > 3){
            cout<<"Invalid Input... Please enter again."<<endl;
            goto reenterTrigonometricChoice;
        }
        return choice;
    }

    void exitCalculator(){
        cout<<"Thank you for using Scientific Calculator"<<endl;
        exit(0);
    }

    void delay(int seconds){
        unsigned int microsecond = 1000000;
        cout<<endl<<endl;
        cout<<"Calculator will resume in 5 seconds..."<<endl;
        usleep(seconds * microsecond);//program stops for given seconds
    }

public:
    void startCalculator(){
        /*
         * Loop for calculator cycles
         * */
        while(true){
            displayFunctions();
            switch (getUserChoice()){
                case 1:{
                    performSumOperation();
                }break;
                case 2:{
                    performSubtractionOperation();
                }break;
                case 3:{
                    performMultiplicationOperation();
                }break;
                case 4:{
                    performDivisionOperation();
                }break;
                case 5:{
                    performRemainderOperation();
                }break;
                case 6:{
                    performPercentageOperation();
                }break;
                case 7:{
                    performSquareOperation();
                }break;
                case 8:{
                    performCubeOperation();
                }break;
                case 9:{
                    performRootOperation();
                }break;
                case 10:{
                    performComplexAdditionOperation();
                }break;
                case 11:{
                    performFactorialOperation();
                }break;
                case 12:{
                    performTrigonometricOperation();
                }break;
                case 13:{
                    exitCalculator();
                    return;
                }
            }
            /* Delay of 5 seconds after each calculator cycle so that user
             * can read the output of previous operation
             */
            delay(5);
        }
    }
};

int main(){
    Calculator calculator;
    calculator.startCalculator();
}