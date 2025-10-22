#include "ArrayListDictionary.hpp"
#include <string>

int main() {
	// variables
	ArrayListDictionary<string, string> dict(8);
	string userWord;

	// add data to the dictionary
	dict.insert("banana", "a fruit that many like, or a phone");
	dict.insert("cactus", "a pointy plant");
	dict.insert("dog", "a domesticated fluff ball");
	dict.insert("graph", "an awesome data structure!");
	dict.insert("haskell", "fantastic programming language, go learn it");
	dict.insert("igloo", "a cool house");
	dict.insert("phoenix", "a bird on fire");
	dict.insert("quack", "said Mr. Duck");

	// loop to let the user search for entries in the dictionary
	while (true) {
		try {
			cout << "Enter a key to search my dictionary (or -1 to stop): ";
			getline(cin, userWord);
			if (userWord == "-1") {
				break;
			}
			cout << dict.find(userWord) << endl;
		} catch (const string &e) {
			cout << e << endl;
		}

		cout << "Number of key comparisons: "
			<< ArrayListDictionary<string, string>::getNumComps() << endl;
	}

	// terminate
	return 0;
}
