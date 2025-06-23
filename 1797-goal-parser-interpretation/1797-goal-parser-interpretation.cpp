class Solution {
public:
    string interpret(string command) {
   string s = command,str="";
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='G')
			str.append("G");
		if (s[i]=='(' && s[i+1]==')')
			{str.append("o");
			i++;}
		if(s[i]=='(' && s[i+1]=='a')
			{str.append("al");
			i+=3;}
	}
    return str;
    }
};