# CyclicLatin7-in-HAT-forAAMAS19-
It shows the nonexistence of Cyclic Latin Matching of order 7 mentioned in my AAMAS19 paper:
  <Cooperation via Codes in Restricted Hat Guessing Games>

#################

This folder contains three cpp files and a file named S.txt

1.S5612.cpp  generates the Steiner system S(5,6,12) which unique upto  isomorphism and output it to S.txt

2.CheckS.cpp checks the data in file "S.txt" to see whether it is a S(5,6,12).

3.CyclicLatin7 inputs S(5,6,12) and searches all the 12!=479001600 codes iso to S(5,6,12) (via a permutation of the columns). Then check whether any such code satisfies the 2nd property mentioned in our paper (Section 2.3). 
If so, we obtain a cyclic Latin matching of order 7. Otherwise, there is no cyclic Latin matching of order 7.

This program runs in less in 10 minutes and the result is negative.
