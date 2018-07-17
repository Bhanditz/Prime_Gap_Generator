#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("PrimeGap.txt"); //opens a file to write to


    long long num1 = 0;
    long long num2 = 0;
    bool isfull = false;
    long long primeGapSum = 0;
    long long primeGapCounter = 1;
    long long answer = 0;
    long long x = 1;


    for (long long i = 2; i=i; i++)
    {
        long long Counter = 0;
        for (long long Divide = 2; Divide < i; Divide++)     //have a basic variable (Divide) that increases by one until it is one less than the number and check if your number divided by Divide has a remainder
        {
            if (i%Divide==0)     //if it has no remainder then it isn't prime and go to the next number
            {
                break;
            }
            else if (i%Divide!=0)  //if it has a remainder, then increase divide by one and keep checking
            {
                Counter++;
            }
        }
        if (Counter == i-2)  //if divide has reached one less than the actual number and there have always been remainders, then output that number and move onto the next one
        {
            if (isfull == false) //these if statements simply determine which term is the first term and which is the second
            {
                num1 = i;
                isfull = true;
            }
            else
            {
                num2 = i;
                isfull = false;
            }

            if (isfull == true) //calculates the difference between the consecutive prime terms
            {
                cout<< num1-num2 << "(" << num1 << "-" << num2 << ")" <<endl;
                primeGapSum += (num1-num2);
                primeGapCounter++;
            }
            else
            {
                cout<< num2-num1 << "(" << num2 << "-" << num1 << ")" <<endl;
                primeGapSum += (num2-num1);
                primeGapCounter++;
            }


            if (primeGapCounter == 5000 && primeGapCounter != 0) //for every 5000 prime gaps calculated it outputs the average prime gap to the file
            {
                answer = primeGapSum/(primeGapCounter*x);
                myfile<< primeGapCounter*x << ": " << answer <<endl;
                primeGapSum = 0;
                primeGapCounter = 1;
                x++;
            }
        }

    }
    myfile.close(); //closes the file
    return 0;
}
