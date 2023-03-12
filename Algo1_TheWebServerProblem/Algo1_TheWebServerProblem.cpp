#include<bits/stdc++.h>
using namespace std;
void inp_out(){
    #ifndef ONLINE_JUDGE
 
        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);
    
        // Printing the Output to output.txt file
        freopen("output.txt", "w", stdout);
 
    #endif
}
//input Funciton
void inp(int &N, vector<vector<int>>& data){
    cin  >> N;
    for(int i=0;i<N;++i){
        int a=0,b=0,c=0;
        cin >> a >> b >> c;

        data.push_back({a,b,c});
    }
}
//Output Function
void out(int &N, vector<vector<int>> &data){
    for(int i=0;i<N;++i){
        cout << data[i][0] <<" "<< data[i][1] <<" "<< data[i][2] << endl;
    }
}

//Sort Website with comparison
bool compare(vector<int> a, vector<int> b){
    if(a[0] < b[0])
        return true;
    else if(a[0] == b[0]){
        if(a[1] > b[1])
            return true;
        else if(a[1] == b[1]){
            if(a[2] <= b[2])
                return true;
            return false;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
int main()
{
    inp_out();

    //Delaration
    int N = 0;
    vector<vector<int>> data;
    
    //input Function
    inp(N, data);

    //Logic
    sort(data.begin(), data.end(), compare);
    
    //Output Function
    out(N, data);
    
    return 0;
}