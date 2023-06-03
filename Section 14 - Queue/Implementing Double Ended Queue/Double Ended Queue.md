
In this tutorial, you will learn what a double ended queue (deque) is. Also, you will find working examples of different operations on a deque in C, C++, Java and Python.

Deque or Double Ended Queue is a type of [queue](https://www.programiz.com/dsa/queue) in which insertion and removal of elements can either be performed from the front or the rear. Thus, it does not follow FIFO rule (First In First Out).

![representation of deque data structure](https://cdn.programiz.com/sites/tutorial2program/files/deque.png "Double ended queue")

Representation of Deque

---

## Types of Deque

-   **Input Restricted Deque**  
    In this deque, input is restricted at a single end but allows deletion at both the ends.
-   **Output Restricted Deque**  
    In this deque, output is restricted at a single end but allows insertion at both the ends.

---

## Operations on a Deque

Below is [the circular array](https://www.programiz.com/dsa/circular-queue) implementation of deque. In a circular array, if the array is full, we start from the beginning.

But in a linear array implementation, if the array is full, no more elements can be inserted. In each of the operations below, if the array is full, "overflow message" is thrown.

Before performing the following operations, these steps are followed.

1.  Take an array (deque) of size n.
2.  Set two pointers at the first position and set `front = -1` and `rear = 0`.

![initialize an array and pointers for deque operations](https://cdn.programiz.com/sites/tutorial2program/files/deque-array.png "Initialize array")

Initialize an array and pointers for deque

### 1. Insert at the Front

This operation adds an element at the front.

1.  Check the position of front.
    
    ![check the position of front](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-front-1.png "Deque - insert at the front")
    
    Check the position of front
    
2.  If `front < 1`, reinitialize `front = n-1` (last index).
    
    ![if front is less than 1 shift front to the end](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-front-2.png "Deque - insert at the front")
    
    Shift front to the end
    
3.  Else, decrease front by 1.
4.  Add the new key 5 into `array[front]`.
    
    ![Insert element at the position of front](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-front-3.png "Deque - insert at the front")
    
    Insert the element at Front
    

### 2. Insert at the Rear

This operation adds an element to the rear.

1.  Check if the array is full.
    
    ![check if deque is full](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-rear-1.png "Deque - insert at the rear")
    
    Check if deque is full
    
2.  If the deque is full, reinitialize `rear = 0`.
3.  Else, increase rear by 1.
    
    ![if deque is not full increase rear](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-rear-2.png "Deque - insert at the rear")
    
    Increase the rear
    
4.  Add the new key 5 into `array[rear]`.
    
    ![insert element at the rear](https://cdn.programiz.com/sites/tutorial2program/files/deque-insert-rear-3.png "Deque - insert at the rear")
    
    Insert the element at rear
    

### 3. Delete from the Front

The operation deletes an element from the front.

1.  Check if the deque is empty.
    
    ![check if deque is empty](https://cdn.programiz.com/sites/tutorial2program/files/deque-delete-front-1.png "Deque - delete from the front")
    
    Check if deque is empty
    
2.  If the deque is empty (i.e. `front = -1`), deletion cannot be performed (**underflow condition**).
3.  If the deque has only one element (i.e. `front = rear`), set `front = -1` and `rear = -1`.
4.  Else if front is at the end (i.e. `front = n - 1`), set go to the front `front = 0`.
5.  Else, `front = front + 1`.
    
    ![increase the index of front](https://cdn.programiz.com/sites/tutorial2program/files/deque-delete-front-2.png "Deque - delete from the front")
    
    Increase the front
    

### 4. Delete from the Rear

This operation deletes an element from the rear.

1.  Check if the deque is empty.
    
    ![check if deque is empty](https://cdn.programiz.com/sites/tutorial2program/files/deque-delete-rear-1.png "Deque - delete from the rear")
    
    Check if deque is empty
    
2.  If the deque is empty (i.e. `front = -1`), deletion cannot be performed (**underflow condition**).
3.  If the deque has only one element (i.e. `front = rear`), set `front = -1` and `rear = -1`, else follow the steps below.
4.  If rear is at the front (i.e. `rear = 0`), set go to the front `rear = n - 1`.
5.  Else, `rear = rear - 1`.
    
    ![decrease the position of rear](https://cdn.programiz.com/sites/tutorial2program/files/deque-delete-rear-2.png "Deque - delete from the rear")
    
    Decrease the rear
    

### 5. Check Empty

This operation checks if the deque is empty. If `front = -1`, the deque is empty.

### 6. Check Full

This operation checks if the deque is full. If `front = 0` and `rear = n - 1`  or  `front = rear + 1`, the deque is full.


