/*

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/


class Solution
{

    private:

        int largestRectangleArea(vector<int> &heights)
        {

            stack<int> st;
            int n = heights.size();
            int maxArea = 0;
            for (int i = 0; i <= n; i++)
            {
                while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
                {
                    int height = heights[st.top()];
                    st.pop();

                    int width;
                    if (st.empty())
                        width = i;
                    else
                        width = i - st.top() - 1;

                    maxArea = max(maxArea, height *width);
                }
                st.push(i);
            }
            return maxArea;
        }
    public:
        int maximalRectangle(vector<vector < char>> &matrix) {
            
            int ans = 0;
            int n = matrix.size(), m = matrix[0].size();
            
            vector<int> heights(m,0);
            for(int i = 0 ; i< n ; i++)
            {
                for(int j = 0 ; j< m ; j++)
                {
                    if(matrix[i][j] == '1')
                    {
                         heights[j]++;
                    }
                    else
                        heights[j] = 0;
                }
                int area = largestRectangleArea(heights);
                ans = max(ans,area);
            }
            return ans;
        }
};
