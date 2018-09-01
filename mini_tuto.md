# Mini tutoriais

### [Upper and lower bound](https://stackoverflow.com/questions/28389065/difference-between-basic-binary-search-for-upper-bound-and-lower-bound)

The lower and upper bound of a  binary search are the lowest and highest position where the value could  be inserted without breaking the ordering. (In the C++ standard library,  these bounds will be represented by iterators referencing the element  before which the value could be inserted, but the concept is not  essentially changed.)

Take, for example, a sorted range

```
1 2 3 4 5 5 5 6 7 9
```

In a binary search for `3`, we will have

```
   v-- lower bound
1 2 3 4 5 5 5 6 7 9
     ^-- upper bound
```

And in a binary search for `5`:

```
       v-- lower bound
1 2 3 4 5 5 5 6 7 9
             ^-- upper bound
```

The lower and upper bound are the same if the element does not exist in the range. In a binary search for `8`:

```
                 v-- lower bound
1 2 3 4 5 5 5 6 7 9
                 ^-- upper bound
```

The author of the article to which you refer phrases all this in the  equivalent terms of "smaller than" and "greater than" so that in a  search of 5,

```
       v-- lower bound
t t t t f f f f f f      <-- smaller than?
1 2 3 4 5 5 5 6 7 9
f f f f f f f t t t      <-- greater than?
             ^-- upper bound
```

The C++ iterators will, in all these cases, refer to the element directly behind the bound. That is to say:

- In the search for `3`, the iterator returned by `std::lower_bound` would refer to `3` and the one from `std::upper_bound` would refer to `4`
- In the search for `5`, the iterator returned by `std::lower_bound` would refer to the first `5` and the one from `std::upper_bound` would refer to `6`
- In the search for `8`, both would refer to `9`

This is because the convention in the C++ standard library for  insertions is to pass an iterator referring to the element before which  the new element should be inserted. For example, after

```c++
std::vector<int> vec { 1, 3, 4, 5, 5, 5, 6, 7, 9 };
vec.insert(vec.begin() + 1, 2);
```

`vec` would contain `1, 2, 3, 4, 5, 5, 5, 6, 7, 9`. `std::lower_bound` and `std::upper_bound` follow this convention so that

```c++
vec.insert(std::lower_bound(vec.begin(), vec.end(), 5), 5);
vec.insert(std::upper_bound(vec.begin(), vec.end(), 8), 8);
```

work as desired and leave `vec` sorted.

More generally, this is an expression of the way ranges are specified  in the C++ standard library. The beginning iterator of a range refers  to the first element of the range (if any), while the ending iterator  refers to the element (if any) directly behind the end of the range.  Another way to look at it is that the iterators returned by `std::lower_bound` and `std::upper_bound` span the range of elements in the searched range that are equivalent to the searched element.

This range is empty if the element is not in the range, so that `lower_bound` and `upper_bound` return the same iterator, and otherwise `lower_bound` returns an iterator referring to the first element in the searched range that's equivalent to the search value while `upper_bound` returns an iterator referring to the element (if any) that's directly behind the last such element.



​         
