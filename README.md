<h1 align="center">
42-push_swap 125/100
</h1>
<div align="center">
  <img src="./badge/push_swapm.png" alt="badge-push_swap">
</div>

## Mandatory

### Step 1 :
- Get args and check args

### Step 2 :

- Implement operations :
	- **sa** *(swap a)* : Swap the first 2 elements at the top of stack ***a***.
	Do nothing if there is only one or no elements.
	- **sb** *(swap b)* : Swap the first 2 elements at the top of stack ***b***.
	Do nothing if there is only one or no elements.
	- **ss** : ***sa*** and ***sb*** at the same time.
	- **pa** *(push a)* : Take the first element at the top of ***b*** and put it at the top of ***a***.
	Do nothing if b is empty.
	- **pb** *(push b)* : Take the first element at the top of ***a*** and put it at the top of ***b***.
	Do nothing if a is empty.
	- **ra** *(rotate a)* : Shift up all elements of stack ***a*** by 1.
	The first element becomes the last one.
	- **rb** *(rotate b)* : Shift up all elements of stack ***b*** by 1.
	The first element becomes the last one.
	- **rr** : ***ra*** and ***rb*** at the same time.
	- **rra** *(reverse rotate a)* : Shift down all elements of stack ***a*** by 1.
	The last element becomes the first one.
	- **rrb** *(reverse rotate b)* : Shift down all elements of stack ***b*** by 1.
	The last element becomes the first one.
	- **rrr** : ***rra*** and ***rrb*** at the same time.

	[Visualizer](https://vscza.itch.io/push-swap)

### Step 3 :
- Initialize stack
- Check if it's already sort

### Step 3 :
- Algo :

	- Push into *stack_b* the first two node.
	- Then, push into *stack_b* the half of the stack corresponding to the smallest values, and then the largest values, until there are only 3 nodes left in *stack_a*.
	- For three nodes, sorting has to be done "manually".
	- For each node of the *stack_b*, there is a target which is the nearest largest value in the *stack_a*. If there is no largest value, the target will be the smallest value.
	- Then you have to calculate for each node of the *stack_b*, the cost to get above his target in the *stack_a*.
	- After that you bring to the top of the *stack_b* the node with the lowest cost and in the *stack_a* the node which is the target of the node of the lowest cost and then push the node above the *stack_b* into the *stack_a* (so the node will be above his target in the *stack_a*).
	- Do it until the *stack_b* is empty.
	- At this point all the nodes are almost sort because there are all near their target, but it can be possible that the lowest or the largest are bellow or above the stack so check if it's sort and if not, do some ***ra*** or ***rra***