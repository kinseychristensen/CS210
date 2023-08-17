Project Name: Corner Grocer Produce Reports

For this project, I was tasked to create a program that simulated a grocery store’s produce sales and gathered the daily sales numbers for each product name.  
This program would read in a file containing the sales data, generate a report summarizing the sales numbers, and allow a user to access various versions of 
that report or search for a specific product. In completing this project, I was able to demonstrate my growing confidence and competence with object oriented 
programming as well as output formatting. I feel my code cleanly creates a functioning menu, handles the user input validation well, and creates a clear and 
useful file for the user.  

	There are a few improvements that I would make to enhance this code.  First, I would create an exception catch for the menu input loop.  I noticed in testing 
that if I entered a multiple character response while in the menu that it would reprint the “this is an invalid menu selection” message for each character 
  before finally returning to the user input.  Second, I would create a parent class called “Reports” and move some of my code out of the ProduceReport class in 
  order to make it more readily scalable.  I did not do this within the scope of this project as I was very new to file input and output and thus uncertain how 
to read in multiple potential file names using a shared function. 

The biggest challenge I faced in this project was reconciling the possibility of case changes between the user input and the data contained within the original 
sales file.  I knew that if I did a direct comparison between the data file and the user input, then there was bound to be logic errors.  After all, the
computer cannot see that “apples” and “APPLES” should both be considered “Apples.” I did some research on how to do a character-by-character comparison and 
concluded that a set of loops would be necessary.  The first loop would iterate through the user input text, using ASCII values to determine whether that letter 
was upper or lower case and then transposing if necessary.  The new case-correct user input was then used in the second loop which iterated through the sales 
data seeking a match.   

While I built this program to only look at a single report, I believe it would require very little adaptation in order to be scalable to larger needs.  First, 
it could incorporate the previously mentioned parent class and from there, I could add child classes for other departments such as a dairy, butcher, or bakery 
report generator.  Also, if there was a set of files representing multiple days of sales reports, a user input option could be added to choose which day’s 
report is analyzed. In order to aid future changes,  I made sure to include specific and generous commenting throughout my code.  I also chose easily 
identifiable variable and function names.  

I really enjoyed the opportunity to work on this project in a very hands-off manner.  While we were given the needed text files and some basic instructions, 
there was very little piloting from my professor so I was able to approach this problem and build the solution from the ground up.  I felt that my ability to 
break down the necessary components into individual functions and parse out code from there has been showcased.  I may already see many things I would do 
differently if I approached a similar project, but I think that’s an excellent skill itself: learning and adapting to experience. 

Thank you.
