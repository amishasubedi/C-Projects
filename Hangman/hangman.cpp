#include <iostream>
#include <ctime>
using namespace std;

int tries = 3;

// Function to display the hangman figure depending on incorrect guesses.
void hang_man(int tries_left)
{
    switch (tries_left)
    {
    case 3:
        cout << "___\n";
        break;
    case 2:
        cout << "|\n|\n|\n___\n";
        break;
    case 1:
        cout << "|\n|    0\n|\n|\n___\n";
        break;
    case 0:
        cout << "|\n|    0\n|   /|\\\n|   / \\\n___\n";
        break;
    default:
        cout << "Invalid tries left!" << endl;
    }
}

// Function to check if the guessed letter is in the word and update the hidden word accordingly.
int checkGuess(char guess, const string &month, string &hide_month)
{
    int correctGuesses = 0;
    for (size_t i = 0; i < month.length(); i++)
    {
        if (month[i] == guess)
        {
            correctGuesses++;
            hide_month[i] = guess;
        }
    }
    if (correctGuesses == 0)
    {
        tries--; // Deduct a life/try if the guess is incorrect
    }
    return correctGuesses;
}

int main()
{
    char letter;
    string month;
    // List of months that user will guess from.
    string months[] =
        {
            "january",
            "february",
            "march",
            "april",
            "may",
            "june",
            "july",
            "august",
            "september",
            "october",
            "november",
            "december"};

    // Randomly select a month for the user to guess.
    srand(time(NULL));
    int month_number = rand() % 12;
    month = months[month_number];

    // Initialize the hidden month with 'X' characters.
    string hide_month(month.length(), 'X');

    system("cls");

    // Main game loop, continues until tries are exhausted or word is guessed.
    while (tries != 0 && hide_month != month)
    {
        hang_man(tries);
        cout << "\t\t\t\tLife: " << tries << endl;
        cout << hide_month << endl;
        cout << "\t\t\t Guess a letter: ";
        cin >> letter;

        system("cls");

        // Check the letter against the chosen month.
        checkGuess(letter, month, hide_month);
    }

    // End of game message.
    if (hide_month == month)
    {
        cout << "Congratulations! You've guessed it right: " << month << endl;
    }
    else
    {
        cout << "Sorry! Out of tries. The month was: " << month << endl;
    }

    return 0;
}
