# Cracking-The-Coding-Interview
My personal notes and solutions while working through the 6th Edition of the famous book.

This has bloated to more general Interview practice, maybe I'll split it off / or refocus the repo to
be more general than just about the book.

# Roadmap
* [ ] Things to Implement from Scratch
	* [x] Linked List
	* [x] Tree
	* [x] Binary Tree
		* [x] BST (Binary Search Tree)
		* [x] Min / Max Heap
	* [x] Trie
	* [x] Graph
	* [ ] Stack
	* [ ] Queue
	* [x] Vector / ArrayLists
	 	* [x] Constructor, Destructor
		* [x] push_back, pop_back
		* [x] insert / delete
	* [x] BFS
	* [x] DFS
	* [x] Binary Search
	* [x] Bubble Sort
	* [x] Heap Sort
	* [x] Insertion Sort (implemented as internal quicksort helper)
	* [x] Quick Sort
	* [x] Merge Sort
	* [ ] Dijkstra's Algorithm
	* [ ] A* for path finding
	* [ ] Knapsack Problem (DP)
* [ ] Stuff to learn
	* [ ] Dynamic Programming
	* [ ] BigO Notation
		* Practice Common Runtimes
		* Practice determining runtime of algorithms
		* Memorize common algo runtimes
	* [ ] Multithreading
		* Lock, Mutex, Race Conditions
* [ ] Know at least a high level overview of the following
	* [ ] CPU Hardware
		* What are Cache Lines
		* What is Cache Locality
		* What is a Cache Miss
		* What are L1, L2, L3 Caches
			* Roughly memorize access time pattern
		* How does SIMD work
		* Pagesize
		* Instruction Pipeline
		* Branch Predictor
		* Out-Of-Order Execution
		* Hyper-Threading SMT
		* Cache Coherency, False Sharing
		* How to track / measure CPU performance
	* [ ] GPU Hardware
		* What is the difference between CPU and GPU
		* Why use GPUs over CPUs
		* How could you leverage GPUs for programming (think GPUCompute)
		* SIMT (as opposed to SIMD)
		* Memory Hierarchy on GPUs
		* Warp and Block Scheduling
		* What is the difference between a TensorCore and a normal GPU core
		* CPU-GPU data transfer
			* Especially the common pitfalls
	* [ ] FPGA
		* What is it and why is it useful
		* How to use it
	* [ ] Distributed Computing
* [ ] Advanced Programming Topics
	* [ ] Distributed Systems
	* [ ] Low-Latency Programming & Optimizations
		* Memory Management: Learn how to optimize cache usage, avoid heap allocations in performance-critical sections, and handle memory allocation/deallocation efficiently (e.g., avoiding memory fragmentation).
		* Latency Sensitivity: Understanding and measuring the impact of data movement (e.g., cache misses, context switches) and I/O latencies is crucial. For example, dive into lock-free or wait-free programming.
		* Real-Time Systems: Hedge funds often deal with real-time market data processing, so familiarizing yourself with real-time systems and latency-critical operations might help.
		* High-Performance Libraries: Learn the inner workings of libraries used in performance-critical contexts (e.g., Boost, Intel TBB, CUDA, etc.).
* [ ] C++ Specifics
	* [x] Testing
	* [x] Benchmarking
	* [ ] Profiling
	* [ ] Multithreaded Code
	* [ ] OOP Style
		* Virtual Functions
		* Subclassing
		* Polymorphism
	* [ ] Inline Assembly, in particular for SIMD intrinsics
	* Coding best practices, learn about common pitfalls
	 	* When and how to use const
			* (!!) constexpr
		* Using size_t > using int for indexers
		* When and how to use modern tools
			* Iterators
			* Lambdas
			* Smart Pointers (unique, shared, weak)
			* Move semantics
				* Rvalue References
				* std::move
			* Optional, Variant, Any
		* Ranges
		* What not to use
			* C Style arrays
			* C Style strings