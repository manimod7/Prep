class Solution {

public:

    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {

        

        vector<vector<int>> ans;

        

        for(int i =0;i<restaurants.size();i++){

            if((veganFriendly==0)&&(restaurants[i][3]<=maxPrice)&&(restaurants[i][4]<=maxDistance))

            ans.push_back(restaurants[i]);

            if((veganFriendly==1)&&(restaurants[i][2]==1)&&(restaurants[i][3]<=maxPrice)&&(restaurants[i][4]<=maxDistance))

                           ans.push_back(restaurants[i]);

            }

         sort(ans.begin(),ans.end(),[](vector<int> &a, vector<int>&b){

                    if (a[1]==b[1])

                        return a[0]>b[0];

                    return a[1]>b[1];

        });

              vector<int> list ;

              for(int i =0;i<ans.size();i++){

                  list.push_back(ans[i][0]);

              }

              return list;

    }

};
