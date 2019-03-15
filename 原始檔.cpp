#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int caseNum,counter=0;
    cin>>caseNum;

    while(counter++ < caseNum){
        int p,q;
        cin>>p>>q;

        long q_pow = pow(2,q);
        long p_pow = pow(2,p);

        long long all_one = 0;
        for(int i=0;i<p;i++){
            all_one*=10;
            all_one++;
        }

        long long maxNum = 0;
        long long minNum = all_one*2+1;

        for(long i=0;i<p_pow;i++){

            long long temp=0,now = i;
            for(int j=0;j<p;j++){
                temp*=10;
                temp = temp + (now%2) + 1;
                now/=2;
            }
            //cout<<temp<<endl;
            if(temp < q_pow)
                continue;

            if(temp%q_pow == 0){
                if(temp > maxNum)
                    maxNum = temp;
                if(temp < minNum)
                    minNum = temp;
            }
        }
        cout<<"Case "<<counter<<": ";

        if(maxNum == 0)
            cout<<"impossible"<<endl;

        else if(maxNum == minNum)
            cout<<maxNum<<endl;

        else
            cout<<minNum<<" "<<maxNum<<endl;


    }
    return 0;
}
