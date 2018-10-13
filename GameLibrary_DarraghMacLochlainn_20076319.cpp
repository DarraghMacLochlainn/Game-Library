/*
TITLE:			Game Library
NAME:			Darragh Mac Lochlainn
STUDENT NUMBER:	20076319
DESCRIPTION:	A C++ program that adds, deletes and lists a vector of games
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void addGame ();
void listGames ();
void deleteGame ();

vector < string > g_GamesLibrary;
vector < string >::const_iterator iter;

int main (int argc, const char *argv[]){
    bool userHasInterest = true;
    int option = 0;
    //Create  a  default  list  of  games
    g_GamesLibrary.push_back ("Bioshock");
    g_GamesLibrary.push_back ("Batman: Arkham Asylum");
    g_GamesLibrary.push_back ("Infamous");
    g_GamesLibrary.push_back ("Hollow Knight");
    g_GamesLibrary.push_back("What Did I Do To Deserve This, My Lord 3: No Heroes Allowed");

  do
    {
        //Write  menu  of  options  to  screen
        //Read  user's  response
        cout << endl << "GAMES LIBARY" << endl << endl
	<< "1) Add Game to Games Library" << endl
	<< "2) List all Games in Library" << endl
	<< "3) Delete Game from Library" << endl
	<< "0) Exit Library Menu Screen" << endl;

        cin >> option;
        //lets getline work
        cin.ignore();
        cout << endl << endl;
        switch (option)
	{
	case 0:
	    userHasInterest = false;
	    break;
	case 1:
	    addGame ();
	    break;
	case 2:
	    listGames ();
  	    break;
	case 3:
	    deleteGame ();
	    break;
	default:
	    cout << "Invalid Command Entered." << endl;
	    break;
	}
        //While  user  does  not  want  to  exit
    }
    while (userHasInterest);
  return 0;
}

void addGame ()
{
    //Ask  for  name  of  game  to  add
    //Add  name  to  list
    //Write  confirmation  to  screen
    string game;
    cout << "Declare the name of the new game: ";
    //cin with spaces
    getline(cin, game);
    g_GamesLibrary.push_back (game);
    listGames ();
}

void listGames ()
{
    //Write  list  of  games  in  library  to  screen
    sort(g_GamesLibrary.begin(), g_GamesLibrary.end());
    for (iter = g_GamesLibrary.begin (); iter != g_GamesLibrary.end (); ++iter)
    {               //gets the index of iter
        cout << ((iter - g_GamesLibrary.begin ()) + 1) << ") " << *iter << endl;
    }
    cout << endl;
}

void deleteGame ()
{
    //Ask  for  name  of  game  to  delete
    cout << "Which game to delete: " << endl;
    string game;
    getline(cin, game);
    cout << endl;
    //If  game  is  found
    //Write  confirmation  to  screen
    iter = find (g_GamesLibrary.begin (), g_GamesLibrary.end (), game);
    if (iter != g_GamesLibrary.end ())
    {
      cout << "Game found & Deleted." << endl;
      g_GamesLibrary.erase (iter);
      listGames ();
    }
    //Else
    //Inform  user  that  game  was  not  found
    else
    {
        cout << "Game Not Deleted" << endl;
        listGames ();
    }
}
