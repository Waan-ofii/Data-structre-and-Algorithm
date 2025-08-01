package dataStructure_inJava;

public class Insertion_sort {
    public static void insertionSort(int list[], int n){
        int temp,i,j;

        for(i=1; i<n; i++){
            temp = list[i];
            j=i-1;
            while(j>=0 && list[j]>temp){
                list[j+1]=list[j];
                j--;
            }
            list[j+1] = temp;
        }
    }


    public static void main(String[] args) {
        int n = 6;
        int[] list = {10,5,15,20,30,25};
        for(int i=0; i<n; i++){
            System.out.print(list[i]+ " ");
        }
insertionSort(list,n);
        System.out.println("\n sorted one");
        for(int i=0; i<n; i++){
            System.out.print(list[i]+ " ");
        }
    }
}
