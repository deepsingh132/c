#include<iostream>//For I/O

using namespace std;// Declaring Namespace

void printPattern(int n) //Function to print the pattern
 {
     int temp=2*n-1,i,j; //temp is used to store the value of rows and columns for double the amount of n less 1

     //Upper Half Portion of the square
     for(i=0;i<(temp/2)+1;i++)    //rows
        {
            int a=n;
            //cout<<endl;

                //Decreasing next rows
            for(j=0;j<i;j++) //col
            {
                cout<<a<<" ";
                a--;
            }

            //Constant Values to be smaller than the temp less 2 times Upper Half
            for(int b=0;b<temp-2*i;b++)
            {
                cout<<n-i<<" ";
            }


            a=n-i+1; //Now a = the value of previous squares

            //Increasing New Rows
            for(int c=0;c<i;c++)
            {
                cout<<a<<" ";
                a++;
            }
            cout<<endl;
        }

        //Lower Half Portion of the square
        for(i=temp/2-1;i>=0;i--)
        {
            int a=n;

            //Decreasing Values Middle Square
            for(j=0;j<i;j++)
            {
                cout<<a<<" ";
                a--;
            }
            // Lower Middle Square Constant Values
            for(int b=0;b<temp-2*i;b++)
            {
                cout<<n-i<<" ";
            }

            a=n-i+1; // Last Square Decreasing Values
            for(int c=0;c<i;c++)
            {
                cout<<a<<" ";
                a++;
            }
            cout<<endl;
        }
 }
int main()  // Main Function
{
    int no=0;//,i,j; // Declaring Variable To Pass The Variable Value to the Function.
    cout<<"Enter a no to get the form:";
    cin>>no;
    try{        // Using Try , Catch.. Statement To Throw an Exception if the Value Entered is Greater Than 1000
        if(no>1000)
            {
                throw no;
            }
            printPattern(no); //Run The Function If Everything is Fine.
    }
    catch(int e) // Catch Exception Of Type Int and Display The Appropriate Exception Message.
    {
        cout<<"Value > 1000";
    }

    return 0;  // Main is not Returning Any Value So..8 0;
}
