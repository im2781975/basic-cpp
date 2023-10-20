Bucket count
"bucket count" refers to the number of separate storage areas (buckets) used internally by certain containers like `std::unordered_map` and `std::unordered_set`.

The purpose of dividing the elements into buckets is to provide a more efficient way to access and manage elements, especially in cases where there might be hash collisions (two or more elements mapping to the same bucket). Each element is assigned to a bucket based on its hash value.

The `bucket_count` function returns the current number of buckets in an unordered associative container. By knowing the number of buckets and understanding how elements are distributed among them, you can gain insights into the performance and efficiency of your data structure.

For example, if you have a large number of elements and you observe that they are concentrated in only a few buckets, it may indicate that your hash function is not distributing elements evenly, potentially causing performance issues. You can also use `bucket_size(bucket_index)` to get the number of elements in a specific bucket.

By adjusting the number of buckets and optimizing your hash function, you can improve the performance of operations like insertions and lookups in unordered associative containers.


Hash table & Hash function:
A hash table (or hash map) is a data structure that provides efficient data retrieval.

Here are the key components and concepts related to hash table:

1. **Array**: A hash table consists of an array (often referred to as the "buckets" or "slots") where data elements are stored. Each element can be accessed using a unique index within the array.

2. **Hash Function**: A hash function is a crucial component of a hash table. It takes an input (or key) and returns an index (often an integer) within the array. The goal is to distribute data evenly across the array, minimizing collisions (when two different keys produce the same index).

3. **Collisions**: Collisions occur when two different keys produce the same index from the hash function. Hash tables need to have mechanisms to handle collisions, such as chaining (each bucket contains a linked list of key-value pairs) or open addressing (placing the collided item in the next available bucket).

4. **Key-Value Pairs**: Hash tables store data as key-value pairs. The key is used to compute the hash, and the value is the associated data you want to store.

5. **Load Factor**: The load factor is the ratio of the number of stored elements to the number of buckets in the hash table. It helps determine when to resize the hash table to maintain efficiency.

6. **Resizing**: Hash tables are often resized when the load factor exceeds a certain threshold. Resizing involves creating a larger array and redistributing the elements to maintain an even distribution and prevent excessive collisions.

Now, let's discuss the hash function in more detail:

A **hash function** is a mathematical function that takes an input (or key) and maps it to a fixed-size value (typically an integer or an index within the array of the hash table). The main goals of a good hash function are:

1. **Deterministic**: Given the same input, the hash function should always produce the same output.

2. **Fast Computation**: It should be efficient to compute the hash value.

3. **Even Distribution**: The hash function should distribute keys as uniformly as possible across the available buckets. This minimizes collisions and ensures that the hash table remains efficient.

4. **Avalanche Effect**: A small change in the input should result in a significantly different hash value.

Common hash functions include division-remainder, multiplication, and more complex functions like DJB2 and MurmurHash. The choice of a hash function can significantly impact the performance of a hash table, and selecting the right hash function for your specific data is important.

In summary, a hash table is a data structure that uses a hash function to efficiently store and retrieve key-value pairs. Hash functions are crucial for the even distribution of keys and preventing collisions, ensuring the hash table remains fast and efficient.
