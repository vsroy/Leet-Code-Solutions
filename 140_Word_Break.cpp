/*Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct
a sentence where each word is a valid dictionary word. Return all such possible sentences.*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:

	bool canBreak(const string &s, unordered_set<string> &dict){
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;

		for (int i = 1; i <= s.size(); ++i){
			for (int j = i; j > 0; j--){
				string curr = s.substr(j - 1, i - j + 1);
				if (dict.find(curr) != dict.end() && dp[j - 1]){
					dp[i] = true;
					break;
				}
			}
		}

		return dp[s.size()];
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		vector<vector<string> > dp(s.size() + 1, vector<string>());
		dp[s.size()].push_back("");
		unordered_set<string> dict(begin(wordDict), end(wordDict));

		if (!canBreak(s, dict)){
			return{};
		}

		for (int i = s.size() - 1; i >= 0; i--){
			for (int j = i + 1; j <= s.size(); j++){
				string curr = s.substr(i, j - i);
				if (dict.find(curr) != dict.end()){
					if (!dp[j].empty()){
						for (auto &inj : dp[j]){
							string temp = curr;
							if (inj != ""){
								temp += " " + inj;
							}

							dp[i].push_back(temp);
						}
					}
				}
			}
		}

		return dp[0];
	}
};

int main()
{

}