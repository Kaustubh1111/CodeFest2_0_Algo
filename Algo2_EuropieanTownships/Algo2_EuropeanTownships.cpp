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
        vector<int> temp;
        char str[20];
        cin >> str;
        char* break_data = strtok(str, ",");

        while (break_data) {
            break_data = strtok(NULL, ",");
            temp.push_back(atoi(break_data));
        }
        data.push_back(temp);
    }
}

int main()
{
    inp_out();

    //Delaration
    int t=0;    //Township

    //R = (1/3) * 3(wall)
    //S = (1/3) * 4(wall)
    //H = (1/3) * 6(wall)
    double R = 1.00, S = (1/3.0) * 4.0, H = 2.00;
    double acc_col = 1.50, acc_hour = 2.50, reg_col = 2.25, reg_hour = 3.25;

    cin >> t;
    while(t--){
        int N;  //Houses
        vector<vector<int>> data;

        //input Function
        inp(N, data);

        //logic 
        double total_hour =0, total_acc = 0, total_reg = 0;
        for(int i=0;i<N;++i){
            //total bedroom = (roof + bedroom)
            //Standared room = kitchen + Room, So neglate Total Bedroom because it's already counted
            int roof = data[i][0], std_room = data[i][1], hall = data[i][2];

            //Count Hour
            total_hour += ((roof * R * acc_hour ) + (std_room * S * acc_hour ) + (hall * H * acc_hour)) ;
            total_hour += ((roof * R * 2 * reg_hour ) + (std_room * S * 2 * reg_hour) + (hall * H * 2 * reg_hour)); 

            //asc Color
            total_acc += ((roof * R * acc_col * 100.0)/100.0 + (std_room * S * acc_col * 100.0) / 100.0 + (hall * H * acc_col * 100.0) / 100.0);
            
            //reg Color
            total_reg += ((roof * R * 2 * reg_col * 100.0) / 100.0 + (std_room * S * 2 * reg_col * 100.0) / 100.0 + (hall * H * 2 * reg_col* 100.0) / 100.0);
        }

        //Print Output
        cout << fixed << setprecision(2) << total_hour <<" " << total_acc << " " << total_reg << endl;
    }
    return 0;
}