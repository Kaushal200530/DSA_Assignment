#include<iostream>
using namespace std;

class EmployeeDatabase{

    private:
    string empName;
    int empID;
    double empsalary;

    public:
    
    void setdata(){
        
          cout<<"Enter the name of the Emoloyee :"<<endl;
          cin>>empName;
          cout<<"Enter the employee ID :"<<endl;
          cin>>empID;
          cout<<"Enter the salary of the Employee :"<<endl;
          cin>>empsalary;
    }
    void qs(int arr[],int F,int L)
    
    {   if (F<L){
        int pivot = arr[F];
        int i = F+1;
        int j = L;
    
        

        while (i<j){
            while (arr[i]<pivot)
            i++;
            while(arr[j]>pivot){
            j--;
        }
            

         if (i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
         else {
            break;

        }
    }
    int temp;
    temp = arr[j];
    arr[j]=arr[pivot];
    arr[pivot]=temp;

    qs (arr ,F,j-1);
    qs (arr ,j+1,L );
        
    }
    }
    void display(){
     cout<<"Emloyee name "<<this->empName<<endl<<"ID "<<this->empID<<endl<<"salary "<<this->empsalary<<endl;
    }
};
    int main(){
    int n;
    int arr[n];
    int F;
    int L;
    cout<<"Enter the number of the Employee :"<<endl;
    cin>>n;
    
    EmployeeDatabase e[n];
    for(int i =0; i<n; i++)
    e[i].setdata();
    for(int i=0;i<n;i++)
    e[i].qs(arr, F, L);
    for(int i = 0; i<n; i++)
    e[i].display();


    
    return 0;
    }