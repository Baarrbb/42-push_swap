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
- Algo : \
	Push into stack_b first two node. \
	Push half of the stack corresponding to the smallest values. \

