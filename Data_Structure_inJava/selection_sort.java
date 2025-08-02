package Data_Structure_inJava;

public class selection_sort {
    public static void selectionSort(int list[], int n){
        int smallest,i;
        int j, temp;
        for(i= 0; i< n-1; i++){
            smallest = i;
            for(j=i+1; j < n; j++){
                if(list[j] < list[smallest]){
                    smallest = j;
                }
            }
            if(smallest != i){
                temp = list[smallest];
                list[smallest] = list[i];
                list[i] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int n = 6;
        int[] list={10,5,20,15,30,25};

        for(int i=0; i<n; i++){
            System.out.print(list[i] + " ");
        }

        selectionSort(list,n);
        System.out.println("\n sorted one");
        for(int i=0; i<n; i++){
            System.out.print(list[i]+ " ");
        }




    }
}
