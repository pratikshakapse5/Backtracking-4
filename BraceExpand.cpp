//TC: O(exponential)
//SC: O(n)
//approach: go over the string to preprocess the blocks and use backtrackig to form a string from all the characters.
class Solution {
public:
vector<string> ans;
vector<vector<char>> blocks;
    vector<string> expand(string s) {
        if(s.size()==0)
            return {};
        int i=0;
       //iterate over the initial string to preprocess
        while(i<s.size())
        {
            vector<char> block;
            if(s[i]=='{') //case1: found a block of chars
            {
                i++;
                while(s[i]!='}') //grab characters before end brace
                {
                    if(s[i]!=',') //ignore commas
                        block.push_back(s[i]);
                    i++;
                }
            }
            else //case2: simple characters
            {
                block.push_back(s[i]); 
            }
            sort(block.begin(), block.end()); //essential to sort: lexicographical order
            blocks.push_back(block); //push each preprocessed block in blocks
            i++;
        }
        backtrack(0,""); //recursive backtrack 0 index, empty string
        return ans;
    }

    void backtrack(int index, string temp)
    {
        //base
        if(index==blocks.size()) //when index reach size of blocks
        {
            ans.push_back(temp);    //append the string sp far to answer
            return;
        }
        //logic
        vector<char> block=blocks[index]; //grab each preprocessed block of chars
        for(auto c: block)
        {
            //action
            temp+=c;  //append character 
            //recurse
            backtrack(index+1, temp); //go find next char from next block 
            //backtrack
            temp.pop_back(); //backtrack
        }

    }

};