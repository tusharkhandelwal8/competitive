Sorting a vector in C++ 
	sort(v.begin(), v.end()); 
	sort in descending order
 	sort(v.begin(), v.end(), greater<int>()); 


cout for decimal precision
	cout << setprecision(15) << f;


vector erase() and clear() in C++
`	to delete all elements in vector-
		vectorname.clear()
	to delete few or one element-
		1. vectorname.erase(position)//posn-one.begin()+i;
		2. vectorname.erase(startingposition, endingposition)   //wont delete last element


binary search
	1. binary_search(start_ptr, end_ptr, num) :      //eg :binary_search(arr.begin(), arr.end(), 15)
	 	This function returns boolean true if the element is present in the container, else returns false
	2. lower_bound(start_ptr, end_ptr, num) -start_ptr //to get index of number from below conditions 
		Returns pointer to “position of num” if container contains 1 occurrence of num. 
		Returns pointer to “first position of num” if container contains multiple occurrence of num. 
		Returns pointer to “position of next higher number than num” if container does not contain occurrence of num. 
	3. upper_bound(start_ptr, end_ptr, num) -start_pts//to get index 
		Returns pointer to “position of next higher number than num” if container contains 1 occurrence of num.
		Returns pointer to “first position of next higher number than last occurrence of num” if container contains multiple occurrence of num.
		Returns pointer to “position of next higher number than num” if container does not contain occurrence of num. 
		Subtracting the pointer to 1st position i.e “vect.begin()” returns the actual index.


accumulate()
	This function returns the sum of all the values lying in a range between [first, last) with the variable sum.
		Syntax 1:
			accumulate(first, last, sum);
				//first, last : first and last elements of range  whose elements are to be added  sum :  initial value of the sum
		Syntax 2: This function returns the sum of all the values lying between [first, last) with the variable sum.
			accumulate(first, last, sum, myfun); 
				//myfun : a function for performing any specific task. For example, we can find product of elements between first and last. 


string to int
	string s = "12345"; // object from the class stringstream 
    	stringstream geek(s);		// The object has the value 12345 and stream // it to the integer x 
    	int x = 0; 
    	geek >> x; 



replace element in vector
	replace(arr, arr + n, old_val, new_val);



remove element from top-
	vectorname.pop(); 



vector to arrange it in desceding order & ascending while pushing;
		priority_queue <int> vectorname; //banao fir push_back 
		//specifically designed such that the first element of the queue is the greatest of all elements in the queue
		priority_queue <int, vector<int>, greater<int>> vectorname; 
    

top()
		returns top value of stack	




 to print vector easy  way-	
	std::vector<int> v = {0, 1, 2, 3, 4, 5}; 
    	for (auto i : v) 
        std::cout << i << ' '; 	




Unordered_set allows only unique keys,
	// declaring set for storing string data-type 
    	unordered_set <string> stringSet ; 

how to inset in set-
	vectorname.insert(.)//. is what i want to insert
	
how to access particular index in set-
	set<string> iterator iter = vectorname.begin();
 	// It will move forward the passed iterator by passed value
	advance(iter, 3);
 	cout<<"3rd Element in set = "<<*iter<<std::endl;


unique(to delete same element in sequence)
		vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 }, i; 
		vector<int>::iterator ip; 
   		ip = std::unique(v.begin(), v.begin() + 12); 
    		// Now v becomes {1 3 10 1 3 7 8 * * * * *}  
    		v.resize(std::distance(v.begin(), ip)); 
    		for (ip = v.begin(); ip != v.end(); ++ip) { 
        	cout << *ip << " ";  } 


getline(cin,str); 
memset


back_inserter for vector;
	vector<int> v1 = { 1, 2, 3 }; 
  
    // Declaring second container for 
    // copying values 
    vector<int> v2 = { 4, 5, 6 }; 
  
    // Using std::back_inserter inside std::copy 
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2)); 
    // v2 now contains 4 5 6 1 2 3 


merge
		merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin()); 
	              
