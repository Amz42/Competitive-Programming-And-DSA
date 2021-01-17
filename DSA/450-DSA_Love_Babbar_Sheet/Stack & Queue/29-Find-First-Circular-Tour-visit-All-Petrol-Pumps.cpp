// Question: https://practice.geeksforgeeks.org/problems/circular-tour/1
// Soltuion: https://practice.geeksforgeeks.org/viewSol.php?subId=1f8f20e5376f50f8b8a0ec59804064fa&pid=700285&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol,distance;
};

int tour(petrolPump [],int );

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++) cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}

/*
APPROACH:
    Firstly confirm is answer exists, Take the sum of (petrol-distance) for all pumps:
        if sum >= 0 then answer exists:
            Traverse petrol pumps by taking some point as start point:
                if you can traverse all petrol pumps from this start point then its the answer
                else choose next petrol pump as new start point
        else answer is not possible
*/

int tour(petrolPump p[],int n){
   // Check if it is not possible to travel
   int sm = 0;
   for(int i=0;i<n;i++) sm += (p[i].petrol - p[i].distance);
   if(sm<0) return -1;
   
   int ptr = 0;
   while(true){
       int start = ptr;
       int fuel = 0;
       
       while(true){
           fuel += p[ptr].petrol;
           if(p[ptr].distance<=fuel){
               fuel-=p[ptr].distance;
               ptr = (ptr+1) % n;
           }else{
               ptr = (ptr+1) % n;
               break;
           }
           if(ptr==start) break;
       }
       
       if(ptr==start) return start;
   }
}