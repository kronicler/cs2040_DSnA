# Applications of data structure 

1. Vector/ Arr

- Use when we need fast random access 
- Use when we need the index as reference 
- Use when we are only appending to the end of the 'list'

2. Linked list 

- Use when we need a proper sequence/ flow of data 
- Use when we need to insert elements into the center of the collection

3. Stack 

- Use when we need to gather instructions in sequence (FILO), handle whatever tasks are top in the stack
	fun fact, this is how instructions are stacked in a computer too


4. Queue 

- Use when we wish to constantly add elements into the collection while also constantly accessing it
	eg. Queueing up nodes to inspect in a graph algo 

5. Deque 

- Use when we wish to stack/ pop elements like a stack but also pop/ push elements to the front

6. Priority Queue 

- Use when we wish to obtain the largest or smallest item in Olog(n)
	largest/ smallest item will always float up

7. Hash tables (unordered_map/ set)

- Use when we wish to retrieve/ search for data in O(1)
- Use when we have many updates to the data set. 
- Use when we need to identify duplicates 

Note: We usually use double hashing or seperate chaining 

8. BSTs (ordered map/ set)

- Use when we need to have a balance between retrieval of random data and finding order

- Keys are harder to hash eg. tuples/ pairs 

- Need to use upper bound/ lower bound 