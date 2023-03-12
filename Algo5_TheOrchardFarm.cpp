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
//
void assign_value(vector<int> tree[]){
    //m["fruit"] = {quantity, per tree / kg * price, per tree, grow, 1 kg, price 
    tree[0] ={0, 12000, 400, 10, 5, 150};
    tree[1] = {0, 10000, 280, 6, 7, 250};
    tree[2] = {0, 27500, 2200, 15, 8, 100};
    tree[3] = {0, 7500, 1500, 5, 10, 50};
    tree[4] = {0, 8000, 75, 15, 15, 1600};
}
void plant_all_tree(vector<int> tree[], int &N, int &D, double &sell){
    for(int i=0;i<5;++i){
        N--;
        tree[i][0] = 1;
        if(tree[i][3] <= D){
            sell += (tree[i][1] * ceil(D / tree[i][3]));
        }
    }    
}
long long find_tree(int index, vector<int> tree[], int N,double &max_N, int &D, double &sell){
    //cout << index <<" " << tree[index][0]<< " "<<N <<endl;
    if(tree[index][0] + 1 > max_N || N == 0)
        return 0;

    if(index == 0 ){
        //cout << "end";
        return (tree[index][1] * (D / tree[index][3]));
    }
    //pick the tree
    tree[index][0]++;
    long long profit = tree[index][1] * (D / tree[index][3]);
    long long pick = 0, not_pick = 0;
    pick = max(pick,find_tree(index, tree, N-1, max_N, D, sell));
    tree[index][0]--;

    not_pick = max(not_pick,(find_tree(index - 1, tree, N, max_N, D, sell)));
    return max(pick + profit, not_pick);
}
int main()
{
    inp_out();

    //Delaration
    int t=0, counter = 0;  
    vector<int> tree[5];  
    unordered_map<string, vector<int>> m;
    assign_value(tree);
    cin >> t;
    while(counter++ < t){
        int N, D;  //Number of trees, Number of Days
        //Take input 
        cin >> N >> D;
        double sell = 0, max_N = round((N*40)/100);
        plant_all_tree(tree, N, D, sell);//plant all tree with by default one
        //cout << sell << max_N;
        for(int i=4;i>=4;--i){
            cout << sell + find_tree(i, tree, N, max_N, D, sell) << endl;
        }
    }
    return 0;
}