class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {

       stack<int> mono_stack;
       int max_area = 0;

       for(int i = 0; i < heights.size(); i++){
           int curr_height = (i==heights.size()) ? 0: heights[i];

           while(!mono_stack.empty() && heights[mono_stack.top()] > curr_height){
               int height = heights[mono_stack.top()];
               mono_stack.pop();
               int width = mono_stack.empty() ? i : i - mono_stack.top() - 1;
               max_area = max(max_area, height * width);
           }

           mono_stack.push(i);
       }

       while (!mono_stack.empty()) {
           int height = heights[mono_stack.top()];
           mono_stack.pop();
           int width = mono_stack.empty() ? heights.size() : heights.size() - mono_stack.top() - 1;
           max_area = max(max_area, height * width);
       }

       return max_area;
   }
};