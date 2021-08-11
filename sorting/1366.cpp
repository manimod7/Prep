class Solution {

public:

    string rankTeams(vector<string>& votes) {

        vector<vector<int>> rank (26, vector<int> (26,0));

        int v = votes.size(); //number of voters

        int t = votes[0].size(); //number of teams teams

        for (int i =0;i<v;i++){

            for(int j=0;j<t;j++){

                rank[votes[i][j]-'A'][j]++;

            }

        }

        string res = votes[0];

        sort(res.begin(),res.end(),[=](char &a,char&b){

            for(int i =0;i<t;i++){

                if (rank[a-'A'][i]==rank[b-'A'][i]) 

                    continue;

                return rank[a-'A'][i]>rank[b-'A'][i];

            }

           return a<b;

        });

        return res;

    }

}; 
