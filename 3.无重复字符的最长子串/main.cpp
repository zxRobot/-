#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;


int lengthOfLongestSubstring(string s) {
    int len=s.size();
    int right=-1;
    int max=0;
    unordered_set<char> str;
    for(int left=0;left<len;left++)
    {
        int ans=0;
        right=left-1;
        while(right+1<len && !str.count(s[right+1]))
        {
            ans++;
            right++;
            str.insert(s[right]);
        }
        max=max>ans?max:ans;
        str.clear();
    }
    return max;
}



int main(int argc, const char * argv[]) {
    int s=lengthOfLongestSubstring("abcabcvv");
    std::cout<<s<<"\n";
    return 0;
}
