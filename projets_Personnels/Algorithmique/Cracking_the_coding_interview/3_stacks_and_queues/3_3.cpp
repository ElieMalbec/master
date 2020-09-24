//Imagine a literal stack of plates. If the stack gets too high , it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack(that is, pop() should return the same values as it would if there were just z single task).
//Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

/*Thoughts
So SetOfStacks would be a class and we could use an pointer to an array of stacks. For example an array of 3 stacks to keep it simple.
Every time we want to push something we must check if it's possible in the first one, if not the second one, etc
SO we need to check if we hit the maximum number of elements in one stack. Let put that at 5 elements.
For the pop() we go from the last stack and then we check if it's empty, if so we go to the second one then the first one; if not empty we just pop the item

For popAt(int index) we need to check if the index if over the number of stack, if so we raise an error, if not we just check if it's empty, if so we raise an error otherwise we pop 
*/


#include <iostream>
#include <stack>
#include <vector>
#include <array>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::array;

class SetOfStacks{
    public : 
    int const static SIZE = 3;
    int const static MAX = 5;
    //stack <vector<int>> stacks;
    //stack <array<int,SIZE>> stacks;
    stack<int> stacks[SIZE];

    SetOfStacks(){
    }

    void push(int item){
        int i = 0;
        for (; i < SIZE; i++){
            if  (stacks[i].size() >= MAX &&  i == 2 ){
                cout << "all stacks are full" << endl;
                return;
            }
            if (stacks[i].size() < MAX){
                break;
            }
            if (stacks[i].size() >= MAX){
                continue;
            }
        }
        pushAt(item, i+1);
    }
    void pop(void){
        int i = SIZE-1;
        for (; i >= 0; i--){
            if (stacks[i].size() == 0 &&  i == 0 ){
                cout << "all stacks are empty" << endl;
                return;
            }
            if (stacks[i].size() > 0){
                stacks[i].pop();
                return;
            }
            if  (stacks[i].empty() == 0){
                continue;
            }          
        }
        return;
    }
    void pushAt(int value, int index){
        if (index > 3 || index < 1){
            cout << "Not enough number of stacks" << endl;
            return;
        }
        //stacks.push({value, index-1});
        stacks[index-1].push(value);
    }
    void popAt(int index){
        if (!(stacks[index-1].empty())){
            stacks[index-1].pop();
        }
        else {
            cout << "The stack is empty" << endl;
            return;
        }
    }
};

int main(void){
    SetOfStacks s;
 /*   s.pushAt(10,1);
    s.pushAt(11,1);
    s.pushAt(12,1);
    s.pushAt(13,1);
    s.pushAt(14,1);

    s.pushAt(20,2);
    s.pushAt(21,2); 
    s.pushAt(22,2);
    s.pushAt(23,2);
    s.pushAt(24,2);

    s.pushAt(30,3);
    s.pushAt(31,3);
    s.pushAt(32,3);
    s.pushAt(33,3);
    s.pushAt(34,3);

    s.pushAt(40,4);

    cout << "s[0] : " << s.stacks[0].top() << endl;
    cout << "s[1] : " << s.stacks[1].top() << endl;
    cout << "s[2] : " << s.stacks[2].top() << endl;
    cout << endl;

    cout << "s[0] empty: " << s.stacks[0].empty() << endl;
    cout << "s[1] empty: " << s.stacks[1].empty() << endl;
    cout << "s[2] empty: " << s.stacks[2].empty() << endl;
    cout << endl;
*/

/*
    s.popAt(2);
    s.popAt(2);
    s.pushAt(20,2);
    if (!(s.stacks[1].empty())){
        cout << "s[1] : " << s.stacks[1].top() << endl;
    }
    else {
        cout << "the stack in question is empty" << endl;
    }
*/
    //cout << s.stacks[0].size() << endl;
    //s.push(99);
    //cout << s.stacks[0].size() << endl;
    //s.push(101);
    if (!(s.stacks[0].empty())){
        cout << "s[0] : " << s.stacks[0].top() << endl;
    }
    else {
        cout << "the stack in question is empty" << endl;
    }
    //cout << "s[1] : " << s.stacks[1].top() << endl;
    s.pop();
    //cout << "s[0] : " << s.stacks[0].top() << endl;
    //cout << "s[1] : " << s.stacks[1].top() << endl;
    //cout << "s[2] : " << s.stacks[2].top() << endl;
    cout << endl;
    return 0;
}