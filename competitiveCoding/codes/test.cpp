#include <bits/stdc++.h>

using namespace std;

void display(vector<int> arr){
    for(auto i :arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}

int trapWater(vector<int>& height) {

    int L = height.size();
    int next_wall = -1, water_capacity = 0;
    display(height);

    for(int i =0 ; i < L-1;){
        // i is current wall that is supposed to be min within this range

        next_wall = -1;
        // find the next bigger wall to hold water
        for(int j = i+1 ; j <= L; j++){
            if( height[j] >= height[i] ) {next_wall = j; break;}
        }

        // get water capacity for this range
        for(int j = i+1 ; j <= next_wall; j++){
            water_capacity += max( height[i] - height[j],0);
        }

        // wall not found move ahead
        if(next_wall == -1){
            i++;
        }
        else{
            i = next_wall;
        }
    }

    // right to left
    reverse(height.begin(),height.end());

    for(int i =0 ; i < L-1;){
        // i is current wall that is supposed to be min within this range

        next_wall = -1;
        // find the next bigger wall to hold water
        for(int j = i+1 ; j <= L; j++){
            if( height[j] > height[i] ) {next_wall = j; break;}
        }

        // get water capacity for this range
        for(int j = i+1 ; j <= next_wall; j++){
            water_capacity += max( height[i] - height[j],0);
        }

        // wall not found move ahead
        if(next_wall == -1){
            i++;
        }
        else{
            i = next_wall;
        }
    }

    return water_capacity;
}


int main(int argc, char **argv)
{   
    vector<int> v = {0,1,0, 2, 1, 0, 1, 3, 0};
    int ans = trapWater(v);
    cout<<ans;
    return 0;
}