#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "PalCheck.h"
#include "LinkedList.h"
#include "Queue.h"
using namespace std;

int main()
{
	cout << "=========QUEUE===========" << endl;
	Queue<string> q;
	q.enqueue("James");
	q.enqueue("Snowy");
	q.enqueue("Sunny");
	cout << "Filling the queue with 3 people... ";
	cout << "Peaking the next in line: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Peeking after dequeud a person: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Peeking after dequeud a person: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Dequed once more, is Queue empty? : " << boolalpha << q.isEmpty() << endl;
	cout << endl;

	cout << "=========PALINDROMES==========" << endl;
	PalCheck p;
	string line;
	ifstream myfile("pal.txt"); //input file
	ofstream outputFile("outputpal.txt"); //outputfile
	if (myfile.is_open()) //if open
	{
		while (getline(myfile, line)) //get a line
		{
			Queue<char> pq; //Queue of chars
			for (int j = 0; j < line.length(); ++j) //for this line's length, lowercase and enque the characters
			{
				line[j] = tolower(line[j]);
				if(isalpha(line[j])) //only enqueue characters
					pq.enqueue(line[j]);
			}
			if (p.isPalindrome(pq)) //if Palindrome -> output to file
				outputFile << line << endl;
		}
		cout << "Written Palindromes to outputpal.txt file..." << endl;
	}
	else cout << "Unable to open file\n";
	myfile.close();
	return 0;
}