<img src="https://user-images.githubusercontent.com/252020/165889219-7c26e3b7-7b30-43f3-b4c0-8cd005a6b142.png"
     alt="media store sketch"
     width="50%" />
     
[sketch source](http://www.urbansketchers.org/2009/12/sketching-at-historic-bookstore-in.html) 

This homework was developed based on Programming Projects 8.2 & 8.3 on page 518 in the textbook "Absolute Java" 6th edition. Converted to C++ for 342 in 2022.

## (40pt) Design OOP for A Media Store

A media rental store needs to write a software to manage some operations for their books and movies. 

There are two kinds of media: 

- Book
- Movie
 
Both media types have an **inventory_id** field as its store unique identifier. To guarentee the uniqueness of this identifier, [singleton pattern](https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern) is used in this repo. A singleton InventoryManager is responsible of generating unique *inventory_id*. There could be only one instance of this InventoryManager in this program.

### Task 1.1 (10pt)
Implement the "==" operator that is used to compare between the **same** kind of media. Book with book, and movie with movie.

Code is src/problem_1/store_media_interface.h
```c++
    bool operator==(const StoreMediaInterface &other_media) const {
        /*
         * TODO: homework
         */
        return false;
    };
```    

A movie equals another movie only when their **id** are the same. Same rule for books being equal. Read this line again before moving on.

### Task 1.2 (30pt)
Implement a few functions related to calulating the late fee. All of such places are marked as

```c++
    /*
     * TODO: homework
     */
 ```

The following shows all the places to work on as homework:

<img width="355" alt="image" src="https://user-images.githubusercontent.com/252020/165890528-9e3435a7-1a23-4976-83a6-1c0791eab3a4.png">
 
This is another chance to **use unit tests as manual** to figure out what should go into each function. 

For example, This function:
```
int MovieAction::calculate_late_fees(int num_of_days_past_due) {
    /*
     * TODO: homework
     */
}
```

This is used to calculate the late fee for action movies. Look for the corresponding unit test. It's called "calculate_late_fees_movie_action". Use the logic in the test to figure out how the late fee is calculated for action movies. This one may feel like a bit detective work. Make a conjecture and try it in the code.
