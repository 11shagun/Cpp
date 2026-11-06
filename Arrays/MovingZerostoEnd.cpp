/* Brute Force Approach - Create new array or vector and store non-zero in
                           that and then copy to original array from start.

       Time complexity = O[N]  || Space Complexity = O[N]                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BruteSolution(vector<int> &nums);
void OptimalSolution(vector<int> &nums);
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    BruteSolution(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    OptimalSolution(nums);
    for(int i=0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void BruteSolution(vector<int> &nums)
{
    vector<int> tempVec;
    // non-zero element to temporary vector
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            tempVec.push_back(nums[i]);
        }
    }
    // non-zero back to main vec
    for(int i=0;i<tempVec.size();i++)
    {
        nums[i]=tempVec[i];
    }
    // fill rest with zeros
    for(int i=tempVec.size();i<nums.size();i++)
    {
        nums[i]=0;
    }
}

/* Optimal Approach - Use two-pointer approach ont loop for Non-zero and
                      other for zero. TC= O[N], SC= O[1]
*/

void OptimalSolution(vector<int> &nums)
{
    int j=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
}
