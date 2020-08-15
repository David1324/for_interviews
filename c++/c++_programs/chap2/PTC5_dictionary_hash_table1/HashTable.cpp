//// DEMONSTRATE USE OF THE REMOVE AND SORT FUNCTIONS
//#include <iostream>
//#include <ctime>
//#include <string>
//#include <cstdlib>
//#include <iomanip>
//#include "HashTable.h"
//using namespace std;
//
//// iterator declarations
//typedef HashTable<string>::Iterator strIterDec;
//
//// hash table size
//const int TABLE_SIZE = 5;
//
//int main()
//{
//	// delcare variables
//	srand(time(NULL));
//	const string names[] = { "Alva","Edda","Hiram","Lemuel","Della","Roseann","Sang",
//		"Evelia","Claire","Marylou","Magda","Irvin","Reagan","Deb","Hillary",
//		"Tuyetm","Cherilyn","Amina","Justin","Neville","Jessica","Demi",
//		"Graham","Cinderella","Freddy","Vivan","Marjorie","Krystal","Liza",
//		"Spencer","Jordon","Bernie","Geraldine","Kati","Jetta","Carmella",
//		"Chery","Earlene","Gene","Lorri","Albertina","Ula","Karena","Johanna",
//		"Alex","Tobias","Lashawna","Domitila","Chantel","Deneen","Nigel",
//		"Lashanda","Donn","Theda","Many","Jeramy","Jodee","Tamra","Dessie",
//		"Lawrence","Jaime","Basil","Roger","Cythia","Homer","Lilliam","Victoria",
//		"Tod","Harley","Meghann","Jacquelyne","Arie","Rosemarie","Lyndon","Blanch",
//		"Kenneth","Perkins","Kaleena" };
//
//	int nameLen = sizeof(names) / sizeof(names[0]);
//
//	// Hash table class declarations
//	HashTable<string> strHash(TABLE_SIZE);
//
//	// insert 10 items into each hash table
//	for (int x = 0; x < (TABLE_SIZE * 2); ++x)
//	{
//		// place all data in bucket 0
//		// NOTE: you dont want to place all data into one
//		// bucket, this is done for demo purposes only
//		// Normally use the "Insert" function instead
//		strHash.Append(0, names[rand() % (nameLen - 1)]);
//	}
//
//	// assign the iterator to bucket 0
//	strIterDec it = strHash.begin(0);
//
//	// display bucket size
//	cout << "Bucket #0 has " << strHash.BucketSize(0) << " items" << endl;
//
//	// display the first item
//	cout << "The first element in bucket #0 is " << it[0] << endl;
//
//	// remove the first item in bucket 0
//	// NOTE: the second parameter is optional
//	// but since we know we want bucket 0, we use it here
//	strHash.Remove(it[0], 0);
//
//	// update the iterator to the new table state
//	it = strHash.begin(0);
//
//	// display the new first item	
//	cout << "nNow bucket #0 has " << strHash.BucketSize(0) << " items" << endl;
//	cout << "The first element in bucket #0 is " << it[0] << endl;
//
//	// display all the items within the "strHash" table
//	cout << "nThe unsorted items in strHash bucket #0:n";
//	for (int x = 0; x < strHash.BucketSize(0); ++x)
//	{
//		cout << "it[] = " << it[x] << endl;
//	}
//
//	// sort the items in bucket 0
//	strHash.Sort(0);
//
//	// display all the items within the "strHash" table
//	cout << "nThe sorted items in strHash bucket #0:n";
//	for (int x = 0; x < strHash.BucketSize(0); ++x)
//	{
//		cout << "it[] = " << it[x] << endl;
//	}
//
//	return 0;
//}// http://programmingnotes.org/