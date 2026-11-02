#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<string> jokes;
    string line;

    ifstream file("randomJokes.txt");

    if (file)
    {
        while (getline(file, line))
        {
            if (!line.empty())
            {
                jokes.push_back(line);
            }
        }
        file.close();
    }

    if (jokes.empty())
    {
        jokes = {
            "Why did the scarecrow win an award? Because he was outstanding in his field!",
            "What do you call a bear with no teeth? A gummy bear!",
            "Why don't skeletons fight each other? They don't have the guts!",
            "What did one wall say to the other wall? I'll meet you at the corner!",
            "Why did the math book look sad? It had too many problems."
        };
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    string command;

    while (true)
    {
        cout << "\nType 'Alexa, tell me a joke' or 'quit': ";
        getline(cin, command);

        if (command == "quit")
        {
            break;
        }

        if (command == "Alexa, tell me a joke")
        {
            int randomIndex = rand() % static_cast<int>(jokes.size());
            string joke = jokes[randomIndex];
            size_t position = joke.find('?');

            if (position != string::npos)
            {
                cout << "\n" << joke.substr(0, position + 1) << endl;
                cout << "\nPress Enter to reveal the punchline...";
                cin.get();
                cout << joke.substr(position + 1) << endl;
            }
            else
            {
                cout << "\n" << joke << endl;
            }
        }
        else
        {
            cout << "\nI did not understand that command." << endl;
        }
    }

    return 0;
}