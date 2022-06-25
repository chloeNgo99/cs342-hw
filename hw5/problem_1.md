<img src="https://user-images.githubusercontent.com/252020/169446666-7a9def2c-f7a4-419a-a683-31aff5e645f7.png"
     alt="hand"
     width="40%" />
     

     
## (30pt) Reverse a List

Going backward is fun sometimes. And this time we are doing it with recursion. 

### Going Reverse

First, we'll reverse a list implemented with an array, aka ArrayList:


```c++
template<class T>
void ArrayList<T>::reverse_recursive() {
    /*
     * TODO: homework
     */
}
```

And then, same for a single linked list:

```c++
template<class T>
void LinkedList<T>::reverse_recursive() {
    /*
     * TODO: homework
     */
}
```

15pt for each, and all tests are given.

In our [previously lecture](https://youtu.be/po5xhPsq4Ug?t=780), the idea of how to reverse a linked list *iteratively (meaning using loop)* was discussed, and that is to travel through the linked list front front to end, and move each node of the linked list to the front. Now, with recursion, the idea is actually very similiar, except it's doing it from the opposite direction. See if you can figure it out. We will have a special lecture to discuss more of this. 

Key requirements to note:

- With recursion, these are to be done with O(1) space complexity, meaning no additional buffer such as array/vector/stack/queue/map can be used. Helper functions are provided but you can define your own.
- No loop of any kind (for, while, do...while, goto?) is allowed.





