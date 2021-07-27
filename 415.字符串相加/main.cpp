string addStrings(string num1, string num2) 
{
    string addStrings(string num1, string num2)
{
    int l1=num1.length()-1;
    int l2=num2.length()-1;
    string res="";
    int count=0;
    while(l1>=0||l2>=0||count!=0)
    {
        int iNum1=l1>=0?num1[l1]-'0':0;
        int iNum2=l2>=0?num2[l2]-'0':0;
        int iNum=iNum1+iNum2+count;
        count=iNum/10;
        iNum=iNum%10;
        l1--;
        l2--;
        char temp=iNum+'0';
        res+=temp;
    }
    reverse(res.begin(), res.end());
    
    return res;
}
    
}