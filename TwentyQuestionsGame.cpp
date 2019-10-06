#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
//define variables
char namestate = 'y', ans1, ans2, ans3;


int main ()
{
    //open output file and name it
    ofstream outfile;
    outfile.open("TwentyQuestions.txt");
    //check the output file opened correctly and display error message if open fails
    if(!outfile)
    {
        cout << "Unable to open TwentyQuestions.txt file" << endl;
        system("pause");
        exit(0);
    }
    //run the rest of the program if the file opens correctly
    else
    {
        //create while loop so the user can play again multiple times
        while (namestate == 'y')
        {
            //display a welcome message and list of options for the user
            //everything displayed to the user is also printed to the output file
            cout << "**************************************************" << endl;
            outfile << "**************************************************" << endl;
            cout << "Please choose an animal out of the list below" << endl;
            outfile << "Please choose an animal out of the list below" << endl;
            cout << setw(10) << "Dog" << setw(10) << "Goldfish" << endl;
            cout << setw(10) << "Parrot" << setw(10) << "Lion" << endl;
            cout << setw(10) << "Shark" << setw(10) << "Hawk" << endl;
            cout << endl;
            cout << "**************************************************" << endl;
            outfile << "**************************************************" << endl;
            //ask question 1 to narrow the potential animals to 3
            cout << "Is the animal you chose often kept as a pet (y/n)?" << endl;
            outfile << "Is the animal you chose often kept as a pet (y/n)?" << endl;
            cin >> ans1;
            outfile << ans1 << endl;

            //enter switch based on answer to question 1
            switch (ans1)
            {
                //if the user answers yes the program narrows the 3 possibilities to 1
                case 'y':
                    //Ask the user question 2 and again print to output file
                    cout << "Does your animal swim (y/n)?" << endl;
                    outfile << "Does your animal swim (y/n)?" << endl;
                    cin >> ans2;
                    outfile << ans2 << endl;
                    switch (ans2)
                    {
                        //if the user answers yes the program knows which animal they chose and breaks out
                        case 'y':
                            cout << "You picked the Goldfish!" << endl;
                            outfile << "You picked the Goldfish!" << endl;
                            break;

                        //if the user answers no the program asks a second question
                        case 'n':
                            cout << "Does your animal fly (y/n)?" <<endl;
                            outfile << "Does your animal fly (y/n)?" <<endl;
                            cin >> ans3;
                            outfile << ans3 << endl;

                            //switch case based on question 3
                            switch (ans3)
                            {
                                //whether the user says yes or no the program narrows to one choice and breaks out
                                case 'y':
                                    cout << "You picked the Parrot!" << endl;
                                    outfile << "You picked the Parrot!" << endl;
                                    break;

                                case 'n':
                                    cout << "You picked the Dog!" << endl;
                                    outfile << "You picked the Dog!" << endl;
                                    break;

                                //if the user inputs something besides yes or no the program says an error and breaks out
                                default:
                                    cout << "I cannot guess! Double check you entered everything correctly!";
                                    outfile << "I cannot guess! Double check you entered everything correctly!";
                                    break;

                            }
                            /*the program breaks because the animal has already been found so the program does not need
                             * need to go through the other cases*/
                            break;

                        //displays an error if the user enters something incorrectly
                        default:
                            cout << "I cannot guess! Double check you entered everything correctly!" << endl;
                            outfile << "I cannot guess! Double check you entered everything correctly!" << endl;

                    }
                    //animal has already been found so the program does not have to go through the other questions
                    break;

                //if the user says no the program knows to ask questions to narrow down the other set of animals
                case ('n'):
                    cout << "Does your animal swim (y/n)?" << endl;
                    outfile << "Does your animal swim (y/n)?" << endl;
                    cin >> ans2;
                    outfile << ans2 << endl;

                    //switch case for question 2
                    switch (ans2)
                    {
                        //if the user says yes the program identifies the animal and breaks out
                        case 'y':
                            cout << "You picked the Shark!" << endl;
                            outfile << "You picked the Shark!" << endl;
                            break;

                        //if the user says no the program asks a third question
                        case 'n':
                            cout << "Does your animal fly (y/n)?" <<endl;
                            outfile << "Does your animal fly (y/n)?" <<endl;
                            cin >> ans3;
                            outfile << ans3 << endl;

                            //switch case for question 3
                            switch (ans3)
                            {
                                //yes or no will narrow the animal to one choice, display it, and break out
                                case 'y':
                                    cout << "You picked the Hawk!" << endl;
                                    outfile << "You picked the Hawk!" << endl;
                                    break;

                                case 'n':
                                    cout << "You picked the Lion!" << endl;
                                    outfile << "You picked the Lion!" << endl;
                                    break;

                                //error message if the user entered something incorrectly
                                default:
                                    cout << "I cannot guess! Double check you entered everything correctly!";
                                    outfile << "I cannot guess! Double check you entered everything correctly!";
                                    break;
                            }
                            //animal had been found so program breaks
                            break;

                        //error message if the user entered something incorrectly
                        default:
                            cout << "I cannot guess! Double check you entered everything correctly!" << endl;
                            outfile << "I cannot guess! Double check you entered everything correctly!" << endl;
                    }
                    //animal has been found so program breaks
                    break;

                //error message if the user entered something incorrectly
                default:
                    cout << "I cannot guess! Double check you entered everything correctly!";
                    outfile << "I cannot guess! Double check you entered everything correctly!";
            }
            //asks the user if they would like to play again, exits if the user says no
            cout << "**************************************************" << endl;
            outfile << "**************************************************" << endl;
            cout << "Would you like to play again?" << endl;
            outfile << "Would you like to play again?" << endl;
            cin >> namestate;
            outfile << namestate << endl;
        }
    }
    //close the output file
    outfile.close();
}