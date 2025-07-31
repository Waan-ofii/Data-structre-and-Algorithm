package dataStructure_inJava;

public class bubble_sort {
    public static void BubbleSort(int[] list, int n){
int temp;
int flag = 0;

for(int i=0; i<n-1; i++){
    flag = 0;
    for(int j = 0; j<n-1-i; j++){
        if(list[j] > list[j+1]){
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
            
  flag = 1;
        }  
    }
    if( flag == 0){
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
