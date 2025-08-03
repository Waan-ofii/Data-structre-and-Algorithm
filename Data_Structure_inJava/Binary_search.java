package Data_Structure_inJava;

import java.util.Scanner;

public class Binary_search {
public static int binarySearch(int list[], int n, int key){
    int left =0;
    int right = n-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(key == list[mid]){
            return mid;
        }else if(key ==list[mid]){
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }

    return -1;
}

public static void main(String[] args) {
    int n = 9;
    int list[]  = {10,15,20,30,40,60,70,90,99};
    int key;
    System.out.print("plese enter a key you looking for : ");
    Scanner numb = new Scanner(System.in);
    key = numb.nextInt();


    int result = binarySearch(list, n, key);
    if(result != -1){
        System.out.println("key "+key+" found at index: "+result);
    }else{
        System.out.println("key is not found");
    }
}
    
}
