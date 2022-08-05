class Solution {
public:
    string longestPalindrome(string s) {
        int start = -1; //This is the start of the substring in s(the starting index from 0)
        int end = -1; //This is the end of the substring in s(the ending index from 0)
        int ans = 0; //This is the length of the longest palindrome
        /*
        If string is "abcbr" then start = 1 and end = 3 and longest palindrome is bcb
        */
        string srev = string(s.rbegin(),s.rend()); //We reverse the given string and store it
        /*
        1. Let's create the LCS array. 
        2. In this array, arr[index1][index2] tells us what is the length of the longest subarray
           till index1-1 in string s and index2-1 in string srev.
        3. The indexing in this dp array is done 1 based so in string "abcs", the index 0 element 
           which is 'a' is actually represented by 1 because we need 0 index to store the initial values
           which is 0 for all row and all columns of 0 index. This is explained in the video above by 
           Abdul Bari Sir.
        */
        int arr[s.size()+1][s.size()+1];
        for(int i=0;i<=s.size();i++) {
            //So the outer loop which is i is representing the original string which is: s
            for(int j=0;j<=s.size();j++) {
                //The inner loop which is j is representing the original string which is: srev
                
                /*
                1. If the index is 0 which actually signifies the empty string or taking no value till now
                   in the string, we make it 0. Because no string means clearly no value.
                2. In this, if the current values in the 2 string are not equal we make the current item
                   to be 0 because we need substring and it has to be continuous.
                */
                if((i==0 || j==0) || (s[i-1]!=srev[j-1])) arr[i][j] = 0; 
                
                else{  //If the values are equal that is s[i-1]==srev[j-1]
                    arr[i][j]=arr[i-1][j-1]+1; //Lets add one to the value till previous
                    /*
                    1. OK so here is where the original error correction starts.
                    2. What is there exists a copy and get matched?
                    3. Then we have to see just 1 thing, if the index of the reversed string matched the index of the unreverse string.
                    4. I have explained it above.
                    5. ob = original begin
                    6. oe = original end
                    7. revbo = reverse begin original
                    8. reveo = revree end original
                    */
                    int ob = i-arr[i][j]; 
                    int oe = i-1;
                    int revbo = s.size()-(j-arr[i][j])-1;
                    int reveo = s.size()-(j-1)-1;
                    /*
                    1. So if the string is not a coincidence and is a genuine answer, that is, ob == reveo and oe == revbo, lets check
                       if this substring is the longest by comparing its size.
                    2. If its genuine and longer than what we have so far, let's take it.
                    3. Mark the end and start so that we can construct this string at the end as we need string not the size.
                    */
                    if(ob == reveo && oe == revbo && arr[i][j] > ans){ 
                        ans = arr[i][j];
                        start = i-arr[i][j];
                        end = i-1;
                    }
                }
            }
        }
        if(start == -1){ start=0; end=0; } //So if there was nothing then a single character is the longest substring
        /*
        1. Making a variable temp and finding all the value of the string from the index we stored.
        */
        string temp = "";
        for(int i=start;i<=end;i++) temp+=s[i];
        /*
        1. Return this string and we are done
        */
        return temp;
    }
};