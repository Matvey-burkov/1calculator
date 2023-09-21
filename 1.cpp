#include <iostream>
#include <string>
#include <vector> 

using namespace std;


void plus1(string number1, string number2){
    string big,small;
    
    if (number1.length() > number2.length())
    {
        big = number1;
        small = number2;
    } else{
        big = number2;
        small = number1;
    } 
    while (big.length() > small.length()) small = "0" + small;
    
    vector<int> arr1, arr2, resault;
    for(int i = 0; i < small.length(); i++){
        arr1.push_back(small[i] - '0');
        arr2.push_back(big[i] - '0');
    }
    
    int temp_num = 0;
    for(int i = small.length() - 1; i >= 0; i--){
        int sum = arr1[i] + arr2[i] + temp_num;
        cout << arr1[i] << " - " << arr2[i] << " - " << temp_num << "\n";
        temp_num = 0;
        if(sum > 9){
            temp_num = sum / 10;
            sum = sum % 10;
        }
        resault.insert(resault.begin(), sum);
    }
    if(temp_num != 0) resault.insert(resault.begin(), temp_num);
    for(int i: resault) cout << i;
}

int main()
{
    string arr1  = "90234123";
    string arr2  = "32223452" ;
    plus1(arr1, arr2);
    

    return 0;
}
