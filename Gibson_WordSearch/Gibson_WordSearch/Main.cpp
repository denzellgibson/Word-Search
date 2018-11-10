//Denzell Gibson
//CSC275 10:30 AM
//3/10/2017

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{

	//Declarations.
	vector<pair<string, int>> wordList; 
	vector<pair<string, int>>::iterator stdIter; 
	fstream wordFile, bookFile; 
	string word, paragraph, token; 

	//Opens text file for reading.
	wordFile.open("Word List.txt", fstream::in);
	
	//Loop that reads each line and inserts into the first element of the vector of pairs.
	while (getline(wordFile, word))
	{
		wordList.push_back(make_pair(word, 0));
	}

	wordFile.close();//Closes the file.

	//Opens text file for reading.
	bookFile.open("Book Paragraphs.txt", fstream::in);

	//Compares each word in vector to each word in text file for match. If true, the second element of the vector of pair
	//is incremented for each word respectively.
	for (stdIter = wordList.begin(); stdIter != wordList.end(); stdIter++) //For each index...
	{
		string temp(stdIter->first); //Have a string variable equal the first element.
		while (bookFile >> token)//Have token contain the next word in the file.
		{
			transform(token.begin(), token.end(), token.begin(), ::tolower);//Makes the string lowercase.
			token.erase(remove_if(token.begin(), token.end(), [](char c) {return c == '.'|| c==','|| c=='?'|| c=='!'|| c=='"'; }),  token.end());//Checks characters for non-letters and removes them.
			if (temp == token)//Compare strings and if true...
			{
				stdIter->second++;//Increment the second element.
			}
		}
		bookFile.clear();//Clears the end-of-file flag after finishing the while loop.
		bookFile.seekg(0, ios::beg);//Moves the cursor to the beginning of the file again.
	}

	//Displays all the words that were search and the amount of times they were found.
	for (stdIter = wordList.begin(); stdIter != wordList.end(); stdIter++)//For every index entry...
	{
		cout << "The word -" << stdIter->first << "- was found " << stdIter->second << " times." << endl;//...Display this message.
	}


	system("pause");
	return 0;
}