#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<int> Vec;

Vec findMultiplesBelowCap (int number, int cap) 
{
    Vec multiples;
    int highestMultiple = (cap - 1) / number;
    for(int curNumber = highestMultiple; curNumber > 0; curNumber--) 
    {
        multiples.push_back(curNumber * number);
    }
    return multiples;
}

Vec combineArraysAndRemoveDuplicates(Vec vecA, Vec vecB) 
{
    std::sort(vecA.begin(), vecA.end());
    std::sort(vecB.begin(), vecB.end());
    
    Vec vecC;
    std::merge(vecA.begin(), vecA.end(),
            vecB.begin(), vecB.end(),
            std::back_inserter(vecC));
    
    Vec::iterator pte = std::unique(vecC.begin(), vecC.end());
    // dups now in [pte, vecC.end()), so erase
    vecC.erase(pte, vecC.end());

    return vecC;
}

int addVectorElements(Vec vecToSum) 
{
    int total = 0;
    
    for (unsigned int idx = 0; idx < vecToSum.size(); idx++)
    {
        total += vecToSum.at(idx);
    }
    return total;
}

int main()
{
    std::cout << "Press any key to begin." << std::endl;
    std::cin.ignore();
    
    Vec multiplesOfThree = findMultiplesBelowCap(3, 1000);
    Vec multiplesOfFive = findMultiplesBelowCap(5, 1000);
    
    Vec multiples = combineArraysAndRemoveDuplicates(multiplesOfThree, multiplesOfFive);
    
    int sum = addVectorElements(multiples);
    std::cout << sum << std::endl;
}