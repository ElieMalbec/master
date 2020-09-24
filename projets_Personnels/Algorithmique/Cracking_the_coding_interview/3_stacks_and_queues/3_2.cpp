//How would you design a stack which, in addition to push and pop, has a function min which returns the mimum element ? Push, pop and min should operate all in 0(1) time

/*Thoughts
Maybe we could use a minheap. Or we could use a dictionnary who contains a single key (key is the min value and the value is where on the stack it is). So every time we add something we update that dictionnary and if min is called we just return the value of our dict//or a [1][2] would work the same.
If smallest is poped we need to change the value of the min
*/