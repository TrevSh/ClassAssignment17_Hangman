#include <ctime>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
    const int MAX_WRONG = 8;

    std::vector<std::string> words;                                     //Collection of possible words to guess
    //Word collection
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(words.begin(), words.end());
    const std::string THE_WORD = words[0];                              //Word to guess
    int wrong = 0;                                                      //Number of wrong guesses
    std::string soFar(THE_WORD.size(), '-');                            //Words guessed so far
    std::string used = "";                                              //Letters already guessed

    std::cout << "\tWelcome to Hangman! Dont die!\n\n";

    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        std::cout << "\n\nYou have " << (MAX_WRONG - wrong);
        std::cout << " Incorrect guesses left.\n";
        std::cout << "\nYou used the following letters: \n" << used << "\n";
        std::cout << "\nSo far, the word is: \n" << soFar << "\n";

        char guess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        guess = toupper(guess);                                         //Makes char uppercase
        while (used.find(guess) != std::string::npos) {
            std::cout << "\nYou've already guessed " << guess << "\n";
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != std::string::npos) {
            std::cout << "Thats rights! " << guess << " is in the word! \n";

            //Update soFar to include newly guessed letter
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }

        else {
            std::cout << "Sorry, " << guess << " is not in the word.\n";
            ++wrong;
        }


    }
        if (wrong == MAX_WRONG) {
            std::cout << "\nYou have died! The end! \n";
        }
        else {
            std::cout << "\nYou got it! Good job! \n";
        }

    std::cout << "The word was " << THE_WORD << "\n";
    system("pause");
    return 0;
}