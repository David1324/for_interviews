#include <iostream>
#include <string>
#include <fstream>
#include <map>

#define BLOCK_SIZE 8
#define NUM_OF_MOST_FREQUENCES_WORDS 5

void histogram_words_instances(const char* fileFullPath, std::map<std::string, int> &wordsHistogram)
{
	const std::string delims(" \t,.;\r");
	
	std::string line, currentWord;
	std::ifstream myFile(fileFullPath, std::ios_base::in);
	while (getline(myFile, line)) {
		std::string::size_type indexStartOfWord, indexEndOfWord;
		indexStartOfWord = line.find_first_not_of(delims);
		while (indexStartOfWord != std::string::npos) {
			indexEndOfWord = line.find_first_of(delims, indexStartOfWord);
			if (indexEndOfWord == std::string::npos) { //if no matches are found
				indexEndOfWord = line.length(); //in this case this is the last word in line
			}
			currentWord.assign(line, indexStartOfWord, indexEndOfWord - indexStartOfWord);

			wordsHistogram[currentWord]++;
			//move to after the delimeter
			indexStartOfWord = line.find_first_not_of(delims, indexEndOfWord);
		}
	}
	myFile.close();
}

//Swap the blocks in reverse order. First character of left block swapped with last character of right block. 
//then moving the cursor forward in left block and backwards in right block and so on.
void swapBlocks(char* str1, char* str2, int blockSize)
{
	char temp;
	for (int i = 0; i < blockSize; i++)
	{
		temp = str1[i];
		str1[i] = str2[blockSize - 1 - i];
		str2[blockSize - 1 - i] = temp;
	}
}

void reverse_file(const char* fileFullPath)
{
	std::fstream myFile(fileFullPath);

	myFile.seekg(0, myFile.end);
	std::streamoff fileSize = myFile.tellg();

	char* leftBlock = new char[BLOCK_SIZE + 1];
	char* rightBlock = new char[BLOCK_SIZE + 1];
	//offset from the beginning/end of file
	int offset = 0;
	int blockSize;
	while (offset < fileSize / 2)
	{
		//set to zero the two blocks
		memset(leftBlock, 0, BLOCK_SIZE + 1);
		memset(rightBlock, 0, BLOCK_SIZE + 1);
		blockSize = BLOCK_SIZE;
		//if what left to reverse is less than the sizes of 2 blocks, we need to decrease their sizes
		if (fileSize - 2 * offset < 2 * BLOCK_SIZE)
		{
			blockSize = (int)((fileSize - 2 * offset) / 2);
		}
		
		//read first block, then second block, etc..
		myFile.seekg(offset, myFile.beg);
		myFile.read(leftBlock, blockSize);

		//read last block, then the block before the last one, etc..
		myFile.seekg(-(offset + blockSize), myFile.end);
		myFile.read(rightBlock, blockSize);

		//Swap the blocks in reverse order
		swapBlocks(leftBlock, rightBlock, blockSize);

		//writing the (reversed) right block to file
		myFile.seekg(-(offset + blockSize), myFile.end);
		myFile.write(rightBlock, blockSize);

		//writing the (reversed) left block to file
		myFile.seekp(offset, myFile.beg);
		myFile.write(leftBlock, blockSize);

		offset += blockSize;
	}

	myFile.close();
}


std::pair<int, std::string> flip_pair(const std::pair<std::string, int> &pairObj)
{
	return std::pair<int, std::string>(pairObj.second, pairObj.first);
}

std::multimap<int, std::string> flip_map(const std::map<std::string, int> &src)
{
	std::multimap<int, std::string> dst;
	//std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), flip_pair);

	std::map<std::string, int>::const_iterator firstIterator = src.begin();
	std::map<std::string, int>::const_iterator lastIterator = src.end();
	std::insert_iterator<std::multimap<int, std::string>> destIterator = std::inserter(dst, dst.begin());

	while (firstIterator != lastIterator) {
		*destIterator = flip_pair(*firstIterator);
		++destIterator; ++firstIterator;
	}

	return dst;
}

int main()
{
	std::string fileName = "song.txt";
	reverse_file(fileName.c_str());

	std::map<std::string, int> wordsHistogram;
	histogram_words_instances(fileName.c_str(), wordsHistogram);

	//sorting words by occurences
	//for that we need to flip the map (key is swapped with value)
	//The key should be the num of occurences (which is now the value)
	//since the key can now occure multiple times we use multimap instead of map
	std::multimap<int, std::string> wordsSortedByOccurences = flip_map(wordsHistogram);

	//using reverse_iterator to print from biggest number to smallest number
	std::multimap<int, std::string>::reverse_iterator rit;
	int countFrequentWords = 0;
	for (rit = wordsSortedByOccurences.rbegin(), countFrequentWords = 0;
		rit != wordsSortedByOccurences.rend() && countFrequentWords<NUM_OF_MOST_FREQUENCES_WORDS;
		++rit, ++countFrequentWords)
		std::cout << countFrequentWords+1 << ".\t" << rit->second << ": " << rit->first << '\n';

	getchar();
}