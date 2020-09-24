//

/*Thoughts
The problem here using a binary search is that it will search on the right side of the array when the actual is on the left because the method returns -1.
We could ping every 10/100/10000 to see if there is a negative number. If so we just run the binary search with the end being the index where we find a negative number.
Our binary search would have a condition that if it find a -1 it will search on the left everytime.
*/

//comparison between the first elem and the middle one allow us to know if it's ordered and where to look

#include <iostream>

using std::cout;
using std::endl;