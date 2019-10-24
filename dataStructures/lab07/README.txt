Evan Trout
EECS 560
Lab 7

My user interface is slightly modified from what is specified in the lab handout:

The BuildHeap function on the handout seems to be misnamed, as it's just levelorder printing the heap
The actual buildheap function is called automatically on file execution to build the heap from the input file
So I renamed the buildheap menu option to PrintHeap for clarity, and moved it to option 5 to fit the organiztaion of the previous lab

I also want to point out that the example program on the lab handout has numerous confusing errors
- The MaxLevelElements output after inserting 23 is incorrect, as 22 and 23 should have switched places
- The program states that the number 1 was successfully deleted even though it was never in the heap to begin with
- The MinLevelElements output is correct but does not include the desired level-order newlines
I don't know who is in charge of writing the lab handouts, but please check your errors more closely next time.
This was extremely confusing to deal with and made me spend time debugging non-existant errors before realizing the mistake.