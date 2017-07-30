#include "PalCheck.h"
#include "Queue.h"
#include <string>
#include <sstream>

/*Function: isPalindrome
Author:	James Riback
Description: determines if a q contains a palindrome
Outputs: true if q is a palindrome, false if not
Inputs: A queue of characters
*/
bool PalCheck::isPalindrome(Queue<char> pq)
{
	std::string nline = "";//normal line
	std::string rline = "";//reverse line
	int n = pq.ifront();//index begin
	int r = pq.iback();//index end
	while (n != r && r != n+1) //end at middle or if string is even break at r = n+1
	{
		//work from the front and back, iterating and adding those chars
		//to our nline and rline strings until the indexes are close
		nline += pq.peek();
		pq.dequeue();
		rline += pq.peekBack();
		pq.dequeueBack();
		n++;
		r--;
	}
	//once n == r break, and compare strings to check for palindrome
	if (nline == rline)
		return true;
	return false;
}
