class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.length(); ++i)
        {
        	if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '*' || input.at(i) == '/')
        	{
        		std::vector<int> left = diffWaysToCompute(input.substr(0, i));
        		std::vector<int> right = diffWaysToCompute(input.substr(i+1));
        		for (int j = 0; j < left.size(); ++j)
        			for(int k=0; k<right.size(); ++k)
        		{
        			switch(input.at(i)){
        				case '+':
        					res.push_back(left[j]+right[k]);
        					break;
        				case '-':
        					res.push_back(left[j]-right[k]);
        					break;
        				case '*':
        					res.push_back(left[j]*right[k]);
        					break;
        				case '/':
        					res.push_back(left[j]/right[k]);
        					break;
        			}
        		}
        	}
        }
        if(res.empty()) res.push_back(atoi(input.c_str()));
        return res;
    }
};