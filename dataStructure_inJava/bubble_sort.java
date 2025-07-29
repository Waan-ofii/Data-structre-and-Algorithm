package dataStructure_inJava;

public class bubble_sort {
    public static void BubbleSort(int[] list, int n){
int temp;
boolean flag = false;

for(int i=0; i<n-1; i++){
    flag = false;
    for(int j = 0; j<n-1-i; j++){
        if(list[j]>list[j+1]){
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;

            flag = true;
        }  
    }
    if( flag = false){
    break;
    }
}
}

public static void main(String[] args){
    int n = 6;
    int[] list = {10,5,20,15,30,25};
for(int i = 0; i<n-1; i++){
    System.out.println(list[i]);

}
    BubbleSort(list ,n);
    for(int i = 0; i<n-1; i++){
        System.out.println(list[i]);

    }





    }
}
