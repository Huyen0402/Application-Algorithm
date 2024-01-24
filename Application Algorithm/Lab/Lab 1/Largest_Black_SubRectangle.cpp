// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <iostream>
#include <stack>
using namespace std;

int R;
int C;
int A[1001][1001];
int maxHist(int row[]){
    
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;
    
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i]){
            result.push(i++);
        }else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty()){
                area = top_val * (i - result.top() - 1);
            }
            max_area = max(area, max_area);
        }
    }

    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}


int maxRectangle(){
    int result = maxHist(A[0]);

    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++)
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        
        result = max(result, maxHist(A[i]));
    }

    return result;
}

// Driver code
int main()
{
    cin >> R >> C;
    for(int i = 0; i < R ; i++){
        for(int j = 0; j < C; j++){
            cin >> A[i][j];
        }
    }

    cout << maxRectangle() << endl;

    return 0;
}

