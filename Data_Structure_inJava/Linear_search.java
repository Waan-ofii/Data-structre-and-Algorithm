package Data_Structure_inJava;

import java.util.Scanner;

public class Linear_search {
   public static void linearSearch(int list[],int n,int data){
     int flag = 0;
     for(int i=0; i<n; i++){
        if(list[i] == data){
            System.out.println("Yes, data is found at index : "+i);
            flag = 1;
            break;
        }
     }
     if(flag == 0){
        System.out.println("No , data is not found");
     }
    }
    public static void main(String[] args) {
        int n = 6;
        int[] list = {20,14,44,53,27,92};
        int data;
        Scanner numb =new Scanner(System.in);
        System.out.print("Enter data you are looking for :");
        data = numb.nextInt();
        System.out.print("is "+data+" found ? :");
        linearSearch(list,n,data);
    }    
}
