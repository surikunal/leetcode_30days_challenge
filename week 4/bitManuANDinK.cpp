class Solution
{
public:
    /* here the fact is that 

    for a range like 9 to 15

idx:0 1 2 3

    1001    --> 9
    1010    --> 10
    1011    --> 11
    1100    --> 12
    1101    --> 13
    1110    --> 14
    1111    --> 15

    starting iterating from left bit and whenever the bits of all the number are not same (here at index 1) then
    after that index all bits in the answer should be 0
    bcz after that all bits are start toggling 
    bcz that is the method of writing bits i.e., 
    1 0 1 0 1 0 1 0 ....in first position   
    1 1 0 0 1 1 0 0 ....in second position   
    1 1 1 1 0 0 0 0 ....in third position   
    and so on...


    so to do that 
    we are right shifting both the extreme values until they are same...
    and increemneting the count too (going to use later)
    like for random example

    initially (2 extreme values)
    11100110 and 11101010
    (ans should be 1110"0000")

    first loop (check if not equal)--> 01110011 and 01110101
    count = 1
    second loop (check if not equal)--> 00111001 and 00111010
    count = 2
    third loop (check if not equal)--> 00011100 and 00011101
    count = 3
    fourth loop (check if not equal)--> 00001110 and 00001110
    count = 4

    now in the fifth loop both values are equal
    so we stop here

    and now the IMPORTANT point is that 
    in answer : last 4 digits should be 0 bcz they are the one which are toggling (so there AND shold be 0)
    and now we have a count which is correct

    so, while returing we will left shift any one of the extreme value count(here 4) num of times
    m = 00001110
    so
    1st time = 00011100
    2nd time = 00111000
    3rd time = 01110000
    4th time = 11100000 ==> which is the answer

    UFFF.. HARD WORK
 */
    int rangeBitwiseAnd(int m, int n)
    {
        int count = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            ++count;
        }
        return m << count;
    }
};