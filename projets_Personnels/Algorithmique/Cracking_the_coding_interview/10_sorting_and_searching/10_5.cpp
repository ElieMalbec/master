//

/*Thoughts
We could just iterate through the array of strings and then check if we find our string.
We could modify the binary search method.
If we fall on a string we just check if they are the same, inferior or superior (like strcmp method)
    if equal we return our mid position
    if inferior we search on the right
    if superior we search on the left
if we fall on a empty string we could search if there is a string close it and compare with our string and then do the check upward

*/

#include <iostream>

using std::cout;
using std::endl;