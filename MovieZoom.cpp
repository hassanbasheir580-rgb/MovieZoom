#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// A struct to hold each title's name and its short description
struct Title
{
    string name;
    string peek;
};

// This function keeps asking the user for a number until they give one that's valid
int getChoice(int minOpt, int maxOpt)
{
    int choice;
    while (true)
    {
        cout << "Enter choice (" << minOpt << "-" << maxOpt << "): ";
        if (cin >> choice && choice >= minOpt && choice <= maxOpt)
        {
            // clear any leftover stuff from input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        // If user types something wrong, we reset and ask again
        cout << "Invalid input. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    // The genres we’ll let the user pick from
    vector<string> genres = {"Action", "Comedy", "Sci-Fi", "Drama", "Horror", "Documentary"};

    // Whether they want a Movie or a TV Show
    vector<string> types = {"Movie", "TV Show"};

    // This is like a 3D box: genre, type, list of titles
    vector<vector<vector<Title>>> titles(genres.size(), vector<vector<Title>>(types.size()));

    // Fill in Action Movies
    titles[0][0] = {
        {"Extraction (2020)", "A black-ops mercenary embarks on a deadly rescue mission in Dhaka."},
        {"6 Underground (2019)", "A billionaire fakes his death to form a covert vigilante team."},
        {"The Old Guard (2020)", "Immortal warriors fight to keep their identity secret."}};
    // Action TV Shows
    titles[0][1] = {
        {"Daredevil", "A blind lawyer becomes a vigilante in Hell’s Kitchen."},
        {"The Punisher", "A vigilante seeks justice while uncovering deep conspiracies."}};

    // Comedy Movies
    titles[1][0] = {
        {"Murder Mystery (2019)", "A couple is framed for murder during a European vacation."},
        {"The Wrong Missy (2020)", "A disastrous blind date turns into a work-trip catastrophe."}};
    // Comedy TV Shows
    titles[1][1] = {
        {"Brooklyn Nine-Nine", "A squad of quirky detectives cracks cases with sharp humor."},
        {"The Good Place", "A witty afterlife comedy about ethics and second chances."}};

    // Sci-Fi Movies
    titles[2][0] = {
        {"The Adam Project (2022)", "A time pilot teams up with his younger self to fix the future."},
        {"I Am Mother (2019)", "A girl raised by a robot questions her world after a stranger arrives."}};
    // Sci-Fi TV Shows
    titles[2][1] = {
        {"Stranger Things", "Kids uncover a secret experiment and a monster from another dimension."},
        {"Black Mirror", "Stand-alone tales exploring technology’s darkest possibilities."}};

    // Drama Movies
    titles[3][0] = {
        {"The Irishman (2019)", "A mob hitman recalls decades with a powerful crime family."},
        {"Marriage Story (2019)", "A couple navigates the emotional toll of divorce."}};
    // Drama TV Shows
    titles[3][1] = {
        {"The Crown", "The reign of Queen Elizabeth II and the politics surrounding it."},
        {"Breaking Bad", "A teacher turns to crime, changing his life and family forever."}};

    // Horror Movies
    titles[4][0] = {
        {"Bird Box (2018)", "Humanity faces invisible entities that drive people to madness."},
        {"Fear Street (2021)", "Teens confront a centuries-old curse haunting their town."}};
    // Horror TV Shows
    titles[4][1] = {
        {"The Haunting of Hill House", "A family faces trauma tied to a haunted mansion."},
        {"Midnight Mass", "A remote island experiences miracles that hide darker truths."}};

    // Documentary Movies
    titles[5][0] = {
        {"The Social Dilemma (2020)", "Insiders reveal how social media manipulates behavior."},
        {"14 Peaks (2021)", "A climber attempts all 14 ‘eight-thousanders’ in record time."}};
    // Documentary TV Shows
    titles[5][1] = {
        {"Our Planet", "Stunning nature series showing Earth’s diverse habitats."},
        {"Explained", "Short episodes breaking down complex topics clearly."}};

    cout << "=== MovieZoom ===\n\n";

    char again = 'y'; // keeps track if user wants to continue
    while (again == 'y' || again == 'Y')
    {

        // Step 1: Let user pick a genre
        cout << "Select a Genre:\n";
        for (size_t i = 0; i < genres.size(); ++i)
        {
            cout << "  " << (i + 1) << ". " << genres[i] << '\n';
        }
        int g = getChoice(1, static_cast<int>(genres.size())) - 1;

        // Step 2: Pick between Movie or TV Show
        cout << "\nSelect Type:\n";
        for (size_t i = 0; i < types.size(); ++i)
        {
            cout << "  " << (i + 1) << ". " << types[i] << '\n';
        }
        int t = getChoice(1, static_cast<int>(types.size())) - 1;

        // Step 3: Show the available options
        cout << "\n"
             << genres[g] << " - " << types[t] << " options:\n";
        const auto &list = titles[g][t];

        if (list.empty())
        {
            cout << "Sorry, no titles available for this combination yet.\n";
        }
        else
        {
            // Print out each title
            for (size_t i = 0; i < list.size(); ++i)
            {
                cout << "  " << (i + 1) << ". " << list[i].name << '\n';
            }

            // Step 4: Let user pick one
            int pick = getChoice(1, static_cast<int>(list.size())) - 1;

            // Step 5: Show its short description
            cout << "\n--- Peek ---\n";
            cout << list[pick].name << "\n";
            cout << list[pick].peek << "\n";
            cout << "------------\n";
        }

        // Ask if they want to go again
        cout << "\nWould you like another recommendation? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << '\n';
    }

    cout << "Thanks for using MovieZoom. Goodbye!\n";
    return 0;
}