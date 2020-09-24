#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>

class Node {
    public :
        Node *next = nullptr;
        int data;
        
        Node(int d){
            data = d;
        }

        void appendToTail(int d){
            Node *end = new Node(d);
            Node *n = this;
            while (n->next != nullptr){
                n = n->next;
            }
            n->next = end;
        }

        Node * appendToEnd(Node *n, int x){
            Node *newNode = new Node(x);
            if (n == nullptr){
                return newNode;
            }
            Node *temp = n;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
            return n;
        }
        void display(void){
            Node *b = this;

            while (b != nullptr){
                std::cout << b->data << " ";
                b = b->next;
            }
        }

        void remove_duplicates(void){
            Node *first = this;

            while (first != nullptr && first->next != nullptr){
                Node *second = first;
                int value = first->data;
                while (second->next != nullptr){
                    if (second->next->data == value){
                        Node *temp = second->next;
                        second->next = second->next->next;
                        delete temp;
                        /*Node *temp2 = first;
                        first = first->next;
                        delete temp2;*/
                    }
                    else{
                        second = second->next;
                    }
                    
                }
                first = first->next;
            }
        }
        
        void remove_duplicates2(void){
            std::unordered_set<int> set;
            Node *previous = nullptr;
            Node *temp = this;
            while (temp != nullptr){
                if (set.find(temp->data) != set.end()){
                    previous->next = temp->next;
                }
                else {
                    set.emplace(temp->data);
                    previous = temp;
                }
                temp = temp->next; 
            }

        }
        Node * kth_to_last(Node *n, int k){
            Node *first = n;
            Node *second = n;
            int i = 0;
            while (i < k){
                if (first == nullptr) return nullptr;
                first = first->next;
                i++;
            }
            while (first != nullptr){
                first = first->next;
                second = second->next;
            }
            return second;
        }
        bool middle_node(Node *n){
            if (n == nullptr || n->next == nullptr){
                return false;
            }
            n->data = n->next->data;
            Node *t = n->next;
            n->next = n->next->next;
            delete t;
            return true;
        }

        Node * partition(Node *n, int x){
            Node * temp = n;
            Node * before = nullptr;
            Node * after = nullptr;

            while (temp != nullptr){
                if (temp->data < x){
                    before = before->appendToEnd(before, temp->data);
                }
                else {
                    after = after->appendToEnd(after, temp->data);
                }
                temp = temp->next;
            }

            Node *t = before;
            while (t != nullptr){
                std::cout << t->data << " ";
                t=t->next;
            }
            std::cout << std::endl;
            Node *s = after;
            while (s != nullptr){
                std::cout << s->data << " ";
                s=s->next;
            }
            
            temp = before;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = after;
            return before;
        }

        int sum_list_reverse_order(Node * l1, Node * l2){
            Node *t1 = l1;
            Node *t2 = l2;
            int result = 0;
            int carry = 0;
            int coeff = 1;
            while (t1 != nullptr && t2 != nullptr){
                int v1 = t1->data;
                int v2 = t2->data;
                int add = v1 + v2 + carry;
                carry = add / 10;

                result = result + (add%10) * coeff; 
                coeff*=10;

                t1 = t1->next;
                t2 = t2->next;
                std::cout << "result, add, carry, coeff " << result << " " << add << " " << carry << " " << coeff << std::endl;
            }
            while (t1 == nullptr && t2 != nullptr){
                int v2 = t2->data;
                result = result + v2 * coeff;
                coeff*=10;

                t2 = t2->next;
            }
            while (t2 == nullptr && t1 != nullptr){
                int v1 = t1->data;
                result = result + v1 * coeff;
                coeff*=10;

                t1 = t1->next;
            }
            return result;
        }

        int max(int x, int y){
            return x >= y ? x : y;
        }
        int sum_list_forward_order(Node * l1, Node * l2){
            Node *t1 = l1;
            Node *t2 = l2;
            int length1 = 0;
            int length2 = 0;
            int coeff = 1;
            int result = 0;
            while (t1 != nullptr && t2 != nullptr){
                length1++;
                length2++;
                t1 = t1->next;
                t2 = t2->next;
            }
            while (t1 == nullptr && t2 != nullptr){
                length2++;
                t2 = t2->next;
            }
            while (t2 == nullptr && t1 != nullptr){
                length1++;
                t1 = t1->next;
            }
            for (int i = 1; i < max(length1, length2); i++){
                coeff*=10;
            }

            t1 = l1;
            t2 = l2;
            while (length1 > 0 && length2 > 0){
                if (length1 == length2){
                    result = result + (t1->data + t2->data) * coeff;
                    coeff /= 10;
                    t1 = t1->next;
                    t2 = t2->next;
                    length1--;
                    length2--;
                }
                else if (length1 > length2) {
                    result = result + t1->data * coeff;
                    coeff /= 10;
                    t1 = t1->next;
                    length1--;
                }
                else {
                    result = result + t2->data * coeff;
                    coeff /= 10;
                    t2 = t2->next;
                    length2--;
                }
            }
            return result;
        }

        bool is_palindrome(Node *n){
            std::stack<int> s;
            Node * temp = n;
            while (temp != nullptr){
                s.push(temp->data);
                temp = temp->next;
            }
            temp = n;

            while (temp != nullptr){
                int value = s.top();
                if (value != temp->data){
                    return false;
                }
                s.pop();
                temp = temp->next;
            }
            return true;
        }

        Node * intersection(Node * l1, Node *l2){
            if (l1 == nullptr || l2 == nullptr) return nullptr;
            Node *t1 = l1; int length1 = 1;
            Node *t2 = l2; int length2 = 1;
            while (t1->next != nullptr){
                t1 = t1->next;
                length1++;
            }
            while (t2->next != nullptr){
                t2 = t2->next;
                length2++;
            }
            if (&t2 != &t1){
                return nullptr;
            }
            t1 = l1;
            t2 = l2;
            if (length1 > length2){
                while (length1 != length2){
                    t1 = t1->next;
                    length1--;
                }
            }
            else if (length2 > length1) {
                while (length2 != length1){
                    t2 = t2->next;
                    length2--;
                }
            }
            while (t1 != nullptr || t2 != nullptr){
                if (&t1 == &t2){
                    return t1;
                }
                t1 = t1->next;
                t2 = t2->next;
            }
        }

        Node * loop_detection(Node *n){
            Node * fast = n;
            Node * slow = n;

            while (fast != nullptr || fast->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow){
                    break;
                }
            }
            if (fast == nullptr || fast->next == nullptr) return nullptr;

            slow = n;
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
};
#endif