///////////////////////////////////////////////////////////////////////////////
//main.cpp
//

#include <iostream>
#include <list>


//unlike vectors, you can insert elements into the middle of a list.
//lists are made of nodes that are linked together

int main()
{
	std::list<int> numbers;
	
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	//adding a number to the front of the list is just as efficient
	numbers.push_front(0);

	
	
	//the element is inserted into the middle of the list just before the
	//location of the iterator. The iterator is still pointing at Element 1 in
	//the list, even though it is not the 3rd item in the list.
	auto it = numbers.begin();
	++it;
	numbers.insert(it, 999); 	
	std::cout << "Element: " << *it << std::endl;



	//we can erase an element in the middle of the list very easily. 
	//you MUST set the iterator = to numbers.erase() here. The reson is
	//that the iterator becomes invalid and you may or may not get
	//the correct element after erasing UNLESS you set it again. 
	//numbers.erase() will return and iterator to the next element after the
	//erased element.	
	auto eraseIt = numbers.begin();
	++eraseIt;
	eraseIt = numbers.erase(eraseIt);
	std::cout << "Element: " << *eraseIt << std::endl;


	//auto becomes: std::list<int>::iterator
	//Here, we are inserting the int 1234 after element 2 which is 
	//straightforward. When we remove an element from the list, we 
	//have to set the iterator again because it has become invalid. However,
	//if we do this, we have effictivly skipped an element in the loop. We,
	//can fix this by only incrementing the iterator if we have not erased,
	//an element. 
	it = numbers.begin();
	while(it != numbers.end())
	{
		//insert an element after item 2 in the list
		if (*it == 2)
		{
			numbers.insert(it, 1234);
		}

		//remove element 1 from the list
		if (*it == 1)
		{
			it = numbers.erase(it);
		}
		else
		{
			//increment the iterator iff we have not erased an element.
			++it;
		}
	}

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}