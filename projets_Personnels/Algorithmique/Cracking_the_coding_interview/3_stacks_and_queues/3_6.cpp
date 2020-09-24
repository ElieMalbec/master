//An animal shelter, which holds only dogs and cats, operates on a strictly first in, first out basis. People must adopt either the oldest (based on arrival) of alla animals at the shelter, or they can select weteher they would prefer a a dog or a cat(and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structure to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog and dequeueCat. You may use the built-in LinkedList data structure.

/*Thoughts
For that we could use a single queue which hold a struct who a int or a string that would indicate that it is a dog or a cat (and a ointer to the next element)
Or we could get two different queues , one for the dogs and one for the cats and create a class that would contains them both.
*/