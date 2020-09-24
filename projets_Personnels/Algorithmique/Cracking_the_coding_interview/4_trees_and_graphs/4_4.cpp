// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

/*Thoughts
For that question we will need a function that calculate the height of a subtree, then we just have to run it on the right and on the left subtree and then compare
We could use a traversal by level (BFS), and add one more level each time and return level.
The problem is that if we have a subtree that have a much bigger height than the other. We might loose time computing it
So we need to check it on the go.
*/



